#!/usr/bin/env bash
#
# CI entry point for the Cryptofuzz build task. Unpacks the dist produced by the
# parent NSS fuzz build, then runs the shared Cryptofuzz builder. OSS-Fuzz calls
# build_cryptofuzz.sh directly, against a tree it has already built itself.

source $(dirname "$0")/tools.sh

set -e

test -n "${VCS_PATH}"

# dist/{public,Debug} from the parent build task.
fetch_dist

# Cryptofuzz's NSS module compiles against headers in the source tree.
cp -a "${VCS_PATH}/nss" .

# build_cryptofuzz.sh writes its tarball to ./artifacts.
ln -sfn /builds/worker/artifacts artifacts

exec "${VCS_PATH}/nss/automation/taskcluster/scripts/build_cryptofuzz.sh" "$@"
