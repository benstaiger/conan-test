# Example/Test Conan Usage in VSCode

## Initial Conan Setup

Following the Getting Started Conan docs:

    conan profile new default --detect
    conan profile update settings.compiler.libcxx=libc++ default

## Setting up the build

    mkdir build && cd build
    conan install ..

If pre-built packages are missing (as in the case of M1 mac) you can add `--build missing` or another
build flag to resolve these issues.

Afterwards everything should work just by using your own compiler toolchain to build. Specifically here we output the conan build commands to build/conanbuildinfo.args which was added to the build task in .vscode/tasks.json. Essentially doing the following:

    clang++ ... @build/conanbuildinfo.args ...