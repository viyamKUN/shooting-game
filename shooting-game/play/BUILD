package(default_visibility = ["//shooting-game:__subpackages__"])

cc_library(
    name = "game_settings",
    hdrs = ["game_settings.h"],
)

cc_library(
    name = "background",
    srcs = ["background.cpp"],
    hdrs = ["background.h"],
    deps = [
        "//shooting-game/core:config",
        "//shooting-game/core:coordination",
        "//shooting-game/core/entity",
    ],
)

cc_library(
    name = "service_provider",
    srcs = ["service_provider.cpp"],
    hdrs = ["service_provider.h"],
    deps = [
        "//shooting-game/play/bullet:bullet_pool",
        "//shooting-game/play/enemy:enemy_blood_pool",
        "//shooting-game/play/ui:ui_manager",
    ],
)

cc_library(
    name = "play_manager",
    srcs = ["play_manager.cpp"],
    hdrs = ["play_manager.h"],
    deps = [
        ":background",
        ":game_settings",
        ":service_provider",
        "//shooting-game/play/enemy:enemy_spawner",
        "//shooting-game/play/player",
    ],
)
