#!/usr/bin/env python3
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

"""
Generate NSS release documentation (Markdown file) based on version number.

Usage: python3 generate_release_doc.py <version> [output_file]

Example:
  python3 generate_release_doc.py 3.118
  python3 generate_release_doc.py 3.118.1 doc/src/releases/nss_3_118_1.md
"""

import os
import sys
from datetime import datetime

sys.path.insert(0, os.path.dirname(__file__))
from release_utils import (
    get_nspr_version,
    get_bug_list_for_version,
    version_string_to_underscore,
    version_string_to_RTM_tag,
    get_rtm_tag_date,
)


def generate_md_content(version, nspr_version, bug_lines, release_date):
    """Generate the MyST Markdown content for the release notes."""
    version_underscore = version_string_to_underscore(version)
    version_dash = version.replace(".", "-")
    changes_text = "\n".join([f"- {line}" for line in bug_lines])

    md_content = f"""(mozilla-projects-nss-nss-{version_dash}-release-notes)=

# NSS {version} release notes

## Introduction

:::{{container}}
Network Security Services (NSS) {version} was released on *{release_date}*.
:::

## Distribution Information

:::{{container}}
The HG tag is NSS_{version_underscore}_RTM. NSS {version} requires NSPR {nspr_version} or newer.

NSS {version} source distributions are available on ftp.mozilla.org for secure HTTPS download:

- Source tarballs:
  <https://ftp.mozilla.org/pub/mozilla.org/security/nss/releases/NSS_{version_underscore}_RTM/src/>

Other releases are available {{ref}}`mozilla-projects-nss-releases`.
:::

(changes-in-nss-{version_dash})=

## Changes in NSS {version}

:::{{container}}
{changes_text}
:::
"""
    return md_content


def main():
    if len(sys.argv) < 2:
        print(__doc__)
        sys.exit(1)

    version = sys.argv[1].strip()

    # Determine output file
    if len(sys.argv) >= 3:
        output_file = sys.argv[2].strip()
    else:
        version_underscore = version_string_to_underscore(version)
        output_file = f"doc/src/releases/nss_{version_underscore}.md"

    rtm_tag = version_string_to_RTM_tag(version)
    rtm_date = get_rtm_tag_date(rtm_tag)
    current_date = rtm_date or datetime.now().strftime("%-d %B %Y")

    # Get NSPR version from the RTM tag revision if it exists
    nspr_version = get_nspr_version(rtm_tag if rtm_date else None)

    print(f"Generating release documentation for NSS {version}")
    print(f"NSPR version: {nspr_version}")
    print(f"Release date: {current_date}")
    print()

    # Get changes from Mercurial
    print("Extracting changes from Mercurial...")
    bug_lines = get_bug_list_for_version(version)
    print(f"Found {len(bug_lines)} bug entries")
    print()

    # Generate Markdown content
    md_content = generate_md_content(version, nspr_version, bug_lines, current_date)

    # Write to file
    output_dir = os.path.dirname(output_file)
    if output_dir:
        os.makedirs(output_dir, exist_ok=True)
    with open(output_file, "w") as f:
        f.write(md_content)

    print(f"Release documentation written to: {output_file}")
    print()
    print(
        "Add it to the toctree in doc/src/releases/index.md, then run "
        "`./mach doc-lint`."
    )
    print()
    print("=" * 70)
    print("Preview:")
    print("=" * 70)
    print(md_content)


if __name__ == "__main__":
    main()
