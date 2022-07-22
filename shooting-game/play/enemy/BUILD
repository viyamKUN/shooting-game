package(default_visibility = ["//shooting-game:__subpackages__"])

cc_library(
    name = "enemy_hit_effect",
    srcs = ["enemy_hit_effect.cpp"],
    hdrs = ["enemy_hit_effect.h"],
    deps = ["//shooting-game/core/entity"],
)

cc_library(
    name = "enemy_blood_pool",
    srcs = ["enemy_blood_pool.cpp"],
    hdrs = ["enemy_blood_pool.h"],
    deps = [
        ":enemy_hit_effect",
        "//shooting-game/core:object_pool",
        "//shooting-game/core/entity",
    ],
)

cc_library(
    name = "enemy",
    srcs = ["enemy.cpp"],
    hdrs = ["enemy.h"],
    deps = [
        "//shooting-game/core:config",
        "//shooting-game/core/entity",
        "//shooting-game/play:game_settings",
        "//shooting-game/play:service_provider",
    ],
)

cc_library(
    name = "enemy_spawner",
    srcs = ["enemy_spawner.cpp"],
    hdrs = ["enemy_spawner.h"],
    deps = [
        ":enemy",
        "//shooting-game/core:config",
        "//shooting-game/core:object_pool",
        "//shooting-game/core/entity",
    ],
)
