package(default_visibility = ["//shooting-game:__subpackages__"])

cc_library(
    name = "transform",
    srcs = ["transform.cpp"],
    hdrs = ["transform.h"],
    deps = [
        "//shooting-game/core:coordination",
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
        ":collider",
        "//shooting-game/core/entity/visual:surface",
    ],
)
