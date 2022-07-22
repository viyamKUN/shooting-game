package(default_visibility = ["//shooting-game:__subpackages__"])

cc_library(
    name = "player_walk_effect",
    srcs = ["player_walk_effect.cpp"],
    hdrs = ["player_walk_effect.h"],
    deps = [
        "//shooting-game/core/entity:entity",
        "//shooting-game/play:game_settings",
    ],
)

cc_library(
    name = "player",
    srcs = ["player.cpp"],
    hdrs = ["player.h"],
    deps = [
        ":player_walk_effect",
        "//shooting-game/core:config",
        "//shooting-game/core:entity_registry",
        "//shooting-game/play:bullet",
        "//shooting-game/play:bullet_pool",
        "//shooting-game/play:game_settings",
        "//shooting-game/play:service_provider",
    ],
)
