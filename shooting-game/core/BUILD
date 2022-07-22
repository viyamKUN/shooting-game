package(default_visibility = ["//shooting-game:__subpackages__"])

cc_library(
    name = "config",
    hdrs = ["config.h"],
)

cc_library(
    name = "coordination",
    srcs = ["coordination.cpp"],
    hdrs = ["coordination.h"],
)

cc_test(
    name = "coordination_test",
    srcs = ["coordination_test.cpp"],
    deps = [
        ":coordination",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_library(
    name = "event",
    srcs = ["event.cpp"],
    hdrs = ["event.h"],
    deps = ["@SDL2"],
)

cc_library(
    name = "entity_registry",
    srcs = ["entity_registry.cpp"],
    hdrs = ["entity_registry.h"],
    deps = ["//shooting-game/core/entity"],
)

cc_library(
    name = "object_pool",
    srcs = ["object_pool.cpp"],
    hdrs = ["object_pool.h"],
    deps = [
        ":entity_registry",
    ],
)

cc_test(
    name = "object_pool_test",
    srcs = ["object_pool_test.cpp"],
    deps = [
        ":object_pool",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_library(
    name = "game",
    srcs = ["game.cpp"],
    hdrs = ["game.h"],
    deps = [
        ":config",
        ":entity_registry",
        ":event",
        "//shooting-game/play:play_manager",
        "@SDL2",
    ],
)
