package(default_visibility = ["//shooting-game:__subpackages__"])

cc_library(
    name = "bullet",
    srcs = ["bullet.cpp"],
    hdrs = ["bullet.h"],
    deps = [
        "//shooting-game/core:config",
        "//shooting-game/core/entity",
        "//shooting-game/play:game_settings",
    ],
)

cc_library(
    name = "bullet_pool",
    srcs = ["bullet_pool.cpp"],
    hdrs = ["bullet_pool.h"],
    deps = [
        ":bullet",
        "//shooting-game/core:object_pool",
    ],
)
