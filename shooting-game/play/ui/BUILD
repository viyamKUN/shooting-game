package(default_visibility = ["//shooting-game:__subpackages__"])

cc_library(
    name = "game_over_ui",
    srcs = ["game_over_ui.cpp"],
    hdrs = ["game_over_ui.h"],
    deps = [
        "//shooting-game/core:config",
        "//shooting-game/core:entity_registry",
    ],
)

cc_library(
    name = "game_start_ui",
    srcs = ["game_start_ui.cpp"],
    hdrs = ["game_start_ui.h"],
    deps = [
        "//shooting-game/core:config",
        "//shooting-game/core:entity_registry",
        "//shooting-game/play/ui/text:text_ui",
    ],
)

cc_library(
    name = "hp_heart_ui",
    srcs = ["hp_heart_ui.cpp"],
    hdrs = ["hp_heart_ui.h"],
    deps = ["//shooting-game/core:entity_registry"],
)

cc_library(
    name = "hp_ui",
    srcs = ["hp_ui.cpp"],
    hdrs = ["hp_ui.h"],
    deps = [
        ":hp_heart_ui",
        "//shooting-game/play:game_settings",
    ],
)

cc_library(
    name = "number_ui",
    srcs = ["number_ui.cpp"],
    hdrs = ["number_ui.h"],
    deps = ["//shooting-game/core:entity_registry"],
)

cc_library(
    name = "score_ui",
    srcs = ["score_ui.cpp"],
    hdrs = ["score_ui.h"],
    deps = [
        ":number_ui",
        "//shooting-game/core:config",
        "//shooting-game/core/entity",
    ],
)

cc_library(
    name = "ui_manager",
    srcs = ["ui_manager.cpp"],
    hdrs = ["ui_manager.h"],
    deps = [
        ":game_over_ui",
        ":game_start_ui",
        ":hp_ui",
        ":score_ui",
    ],
)
