package(default_visibility = ["//shooting-game:__subpackages__"])

cc_library(
    name = "letter_ui",
    srcs = ["letter_ui.cpp"],
    hdrs = ["letter_ui.h"],
    deps = ["//shooting-game/core:entity_registry"],
)

cc_test(
    name = "letter_ui_test",
    srcs = ["letter_ui_test.cpp"],
    deps = [
        ":letter_ui",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_library(
    name = "text_ui",
    srcs = ["text_ui.cpp"],
    hdrs = ["text_ui.h"],
    deps = [
        ":letter_ui",
    ],
)

cc_test(
    name = "text_ui_test",
    srcs = ["text_ui_test.cpp"],
    deps = [
        ":text_ui",
        "@com_google_googletest//:gtest_main",
    ],
)
