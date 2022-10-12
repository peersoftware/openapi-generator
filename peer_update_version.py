#!/usr/bin/env python3

"""Set the version based on the current git branch/SHA."""

import os
import re
import subprocess


def run_cmmd_capture_stdout(command):
    """Run a command and capture its stdout."""
    process = subprocess.run(command, check=False, capture_output=True, text=True)
    return process.stdout.rstrip('\n')


def get_branch():
    """Get the git branch."""
    return run_cmmd_capture_stdout(['git', 'rev-parse', '--abbrev-ref', '@'])


def get_sha():
    """Get the git SHA."""
    return run_cmmd_capture_stdout(['git', 'rev-parse', '--short', '@'])


def update_version(file_path, branch, sha):
    """Update version information in a pom.xml file."""
    encoding = 'utf-8'

    with open(file_path, 'r', encoding=encoding) as file:
        filedata = file.read()

    filedata = re.sub(
        # Find the version between RELEASE_VERSION tags and append the branch and SHA to it
        r'(?P<start><!-- RELEASE_VERSION -->\s*\n' +
        r'\s*<version>)(?P<version>[\d.]*)(?P<version_suffix>-SNAPSHOT).*(?P<end></version>\s*\n' +
        r'\s*<!-- /RELEASE_VERSION -->)',
        r'\g<start>\g<version>\g<version_suffix>-' + branch + r'-' + sha + r'\g<end>', filedata)

    with open(file_path, 'w', encoding=encoding) as file:
        file.write(filedata)


def update_poms():
    """Set the version in necessary pom.xml files to tag the openapi generator build."""
    branch = get_branch()
    sha = get_sha()
    files = [
        os.path.join('modules', 'openapi-generator-cli', 'pom.xml'),
        os.path.join('modules', 'openapi-generator-core', 'pom.xml'),
        os.path.join('modules', 'openapi-generator-gradle-plugin', 'pom.xml'),
        os.path.join('modules', 'openapi-generator-maven-plugin', 'pom.xml'),
        os.path.join('modules', 'openapi-generator-online', 'pom.xml'),
        os.path.join('modules', 'openapi-generator', 'pom.xml'),
        'pom.xml'
    ]

    for file in files:
        update_version(file, branch, sha)


if __name__ == '__main__':
    update_poms()
