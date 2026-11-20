#!/usr/bin/env bash
# This script sets up a cross-compile for macOS from another OS with clang, the
# LLVM binutils and an unpacked macOS SDK. It is sourced by build.sh, which then
# builds NSPR and NSS with the CC, CXX, AR, ... exported here.

macos_setup()
{
    local arch
    case "${target_arch:=arm64}" in
        arm64|aarch64) arch=arm64; target_arch=arm64; nspr_target=aarch64-apple-darwin ;;
        x64) arch=x86_64; nspr_target=x86_64-apple-darwin ;;
        *)
            echo "Unsupported macOS target architecture: $target_arch" 1>&2
            exit 2
            ;;
    esac

    if [ ! -d "$macos_sdk" ]; then
        echo "Cross-compiling for macOS needs --macos-sdk=<path to an unpacked MacOSX.sdk>." 1>&2
        exit 2
    fi
    macos_sdk=$(cd "$macos_sdk" && pwd -P)
    : "${macos_version_min:=11.0}"

    local tool
    for tool in clang clang++ ld64.lld llvm-ar llvm-ranlib llvm-strip llvm-libtool-darwin llvm-nm llvm-otool; do
        if ! hash "$tool" 2>/dev/null; then
            echo "Cross-compiling for macOS needs $tool on the PATH." 1>&2
            exit 2
        fi
    done

    local target="-target $arch-apple-macos$macos_version_min -isysroot $macos_sdk"
    export CC=clang CCC=clang++ CXX=clang++
    export CFLAGS="$CFLAGS $target -DHAS_CONNECTX"
    export CXXFLAGS="$CXXFLAGS $target"
    export LDFLAGS="$LDFLAGS $target -fuse-ld=lld"
    export AR=llvm-ar
    export RANLIB=llvm-ranlib
    export STRIP=llvm-strip
    export MACOSX_DEPLOYMENT_TARGET="$macos_version_min"
    export PATH="$cwd/coreconf/macos-tools:$PATH"

    gyp_format=ninja-mac
    gyp_params+=(-DOS=mac -Dsign_libs=0)
}

macos_setup
