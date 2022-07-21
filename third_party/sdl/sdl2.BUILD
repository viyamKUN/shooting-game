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
    out_static_libs = [
        "libSDL2.a",
        "libSDL2main.a",
    ],
)
