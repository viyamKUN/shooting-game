package(default_visibility = ["//shooting-game:__subpackages__"])

cc_library(
    name = "config",
    hdrs = ["config.h"],
)

cc_library(
    name = "coordination",
    srcs = ["coordination.cpp"],
    hdrs = ["coordination.h"],
    deps = ["@SDL2"],
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
    name = "transform",
    srcs = ["transform.cpp"],
    hdrs = ["transform.h"],
    deps = [
        ":coordination",
        "@SDL2",
    ],
)

cc_library(
    name = "collider",
    srcs = ["collider.cpp"],
    hdrs = ["collider.h"],
    deps = [
        ":transform",
        "@SDL2",
    ],
)

cc_library(
    name = "entity",
    srcs = ["entity.cpp"],
    hdrs = ["entity.h"],
    deps = [
        "//shooting-game/gamelogic/visual:animation",
        "//shooting-game/gamelogic/visual:surface",
        ":collider",
        ":transform",
        "@SDL2",
    ],
)

cc_library(
    name = "entity_registry",
    srcs = ["entity_registry.cpp"],
    hdrs = ["entity_registry.h"],
    deps = [":entity"],
)

cc_library(
    name = "object_pool",
    srcs = ["object_pool.cpp"],
    hdrs = ["object_pool.h"],
    deps = [
        ":entity",
        ":entity_registry",
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
