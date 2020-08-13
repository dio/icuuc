load("@rules_cc//cc:defs.bzl", "cc_binary")
load("//bazel/build.bzl", "load_targets")

load_targets()

cc_binary(
    name = "test",
    srcs = ["test.c"],
    deps = [
        "@org_unicode_icuuc//:common",
        "@org_unicode_icuuc//:data",
    ],
)
