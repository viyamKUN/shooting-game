load("@com_github_bazelbuild_buildtools//buildifier:def.bzl", "buildifier", "buildifier_test")

buildifier(name = "buildifier")

buildifier_test(
    name = "buildifier_test",
    srcs = glob(
        [
            "**/*.bzl",
            "**/*.bazel",
            "**/BUILD",
        ],
        exclude = ["bazel-*/**/*"],
    ) + ["WORKSPACE"],
)
