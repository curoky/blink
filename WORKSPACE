# Copyright 2021 curoky(cccuroky@gmail.com).
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

workspace(name = "com_github_curoky_blink")

load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

git_repository(
    name = "com_curoky_rules_pkg",
    branch = "master",
    remote = "https://github.com/curoky/rules_pkg",
)

load("@com_curoky_rules_pkg//:rules_dependencies.bzl", "pkg_rules_dependencies")

pkg_rules_dependencies(["qt"])

load("@com_curoky_rules_pkg//:register_toolchains.bzl", "pkg_register_toolchains")

pkg_register_toolchains()

git_repository(
    name = "com_github_curoky_iwyu_imp",
    branch = "master",
    remote = "https://github.com/curoky/iwyu-imp.git",
)