cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    data = [
        "//assets",
    ],
    linkopts = select({
        ":osx": [
            "-lm",
            "-liconv",
            "-lobjc",
            "-Wl,-framework,AVFoundation",
            "-Wl,-framework,AppKit",
            "-Wl,-framework,AudioToolbox",
            "-Wl,-framework,CoreGraphics",
            "-Wl,-framework,CoreAudio",
            "-Wl,-framework,CoreVideo",
            "-Wl,-framework,CoreMotion",
            "-Wl,-framework,CoreHaptics",
            "-Wl,-framework,Metal",
            "-Wl,-framework,GameController",
            "-Wl,-framework,Foundation",
            "-Wl,-framework,ForceFeedback",
            "-Wl,-framework,Carbon",
            "-Wl,-framework,IOKit",
            "-Wl,-framework,QuartzCore",
        ],
        "//conditions:default": [],
    }),
    deps = [
        "//shooting-game/gamelogic:game",
    ],
)

config_setting(
    name = "osx",
    constraint_values = ["@platforms//os:osx"],
)
