package(default_visibility = ["//shooting-game:__subpackages__"])

cc_library(
    name = "animation",
    srcs = ["animation.cpp"],
    hdrs = ["animation.h"],
    deps = ["@SDL2"],
)

cc_library(
    name = "surface",
    srcs = ["surface.cpp"],
    hdrs = ["surface.h"],
    deps = [
        ":animation",
        "//shooting-game/core/entity:transform",
        "@SDL2",
    ],
)
