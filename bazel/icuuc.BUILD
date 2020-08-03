# Copyright (C) 2020 Dhi Aurrahman <dio@rockybars.com>
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
# 1. Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
# 2. Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the distribution.
#
# THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
# ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
# ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
# FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
# DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
# OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
# HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
# LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
# OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
# SUCH DAMAGE.

load("@rules_cc//cc:defs.bzl", "cc_library")

licenses(["notice"])  # BSD license

exports_files(["LICENSE"])

icuuc_copts = [
    "-DU_STATIC_IMPLEMENTATION",
    "-DU_COMMON_IMPLEMENTATION",
    "-DU_HAVE_STD_ATOMICS",
] + select({
    "@icuuc//:darwin": [
        "-Wno-shorten-64-to-32",
        "-Wno-unused-variable",
    ],
    "@icuuc//:windows_x86_64": [
        "/utf-8",
        "/DLOCALE_ALLOW_NEUTRAL_NAMES=0",
    ],
    "//conditions:default": [],
})

cc_library(
    name = "headers",
    hdrs = glob(["source/common/unicode/*.h"]),
    includes = [
        "source/common",
    ],
    visibility = [
        "//visibility:public",
    ],
)

cc_library(
    name = "common",
    hdrs = glob([
        "source/common/unicode/*.h",
    ]),
    includes = [
        "source/common",
    ],
    visibility = [
        "//visibility:public",
    ],
    deps = [
        ":icuuc",
    ],
)

cc_library(
    name = "icuuc",
    srcs = glob([
        "source/common/*.c",
        "source/common/*.cpp",
        "source/stubdata/*.cpp",
    ]),
    hdrs = glob([
        "source/common/*.h",
    ]),
    copts = icuuc_copts,
    visibility = [
        "//visibility:private",
    ],
    deps = [
        ":headers",
    ],
)

cc_library(
    name = "data",
    srcs = ["@icuuc//bazel/data:generated"],
    visibility = [
        "//visibility:public",
    ],
    deps = [":headers"],
    alwayslink = 1,
)
