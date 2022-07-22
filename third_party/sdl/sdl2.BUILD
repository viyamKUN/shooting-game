load("@rules_foreign_cc//foreign_cc:defs.bzl", "cmake")

package(default_visibility = ["//visibility:public"])

licenses(["notice"])  # Zlib

exports_files(["LICENSE"])

filegroup(
    name = "all_srcs",
    srcs = glob(["**"]),
)

cmake(
    name = "SDL2",
    generate_args = [
        "-G Ninja",
        "-DSDL_STATIC=ON",
    ],
    lib_source = ":all_srcs",
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
    out_static_libs = [
        "libSDL2.a",
        "libSDL2main.a",
    ],
)

config_setting(
    name = "osx",
    constraint_values = ["@platforms//os:osx"],
)
