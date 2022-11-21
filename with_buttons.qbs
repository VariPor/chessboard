import qbs

Project {
    minimumQbsVersion: "1.7.1"

    CppApplication {
        consoleApplication: true

        cpp.cxxLanguageVersion: "c++14"

        property path lib_dir: "../lib"

        files: [
            "board.cpp",
            "board.cpp",
            "board.h",
            "board.h",
            "cell.cpp",
            "cell.h",
            lib_dir +"/Graph_lib/Graph.cpp",
            lib_dir +"/Graph_lib/GUI.cpp",
            lib_dir +"/Graph_lib/Window.cpp",
            "main.cpp",
        ]

        cpp.includePaths: lib_dir
        cpp.defines: [
            "_LARGEFILE_SOURCE",
            "_LARGEFILE64_SOURCE",
            "_FILE_OFFSET_BITS=64",
        ]
        Properties {
            condition: qbs.targetOS.contains("windows")
            cpp.defines: [
                "WIN32",
                "USE_OPENGL32",
            ]
            cpp.systemIncludePaths: "C:/Users/CAT/Desktop/С++ code/lib/fltk-1.3.8_win64/include"
            cpp.libraryPaths: "C:/Users/CAT/Desktop/С++ code/lib/fltk-1.3.8_win64/lib"
            cpp.driverLinkerFlags: "-mwindows"
            cpp.staticLibraries: [
                "fltk_images",
                "fltk_jpeg",
                "fltk_png",
                "fltk_z",
                "fltk",
                "ole32",
                "uuid",
                "comctl32",
            ]
        }
        Properties {
            condition: qbs.targetOS.contains("linux")
            cpp.defines: [
                "_THREAD_SAFE",
                "_REENTRANT",
            ]
            cpp.cxxFlags: [
                "-fno-plt", "-Wp,-D_FORTIFY_SOURCE=2",
                "-Wformat", "-Werror=format-security",
                "-fstack-clash-protection", "-fcf-protection",
                "-flto", "-ffat-lto-objects",
            ]
            cpp.staticLibraries: [
                "fltk_images",
                "jpeg",
                "png",
                "z",
                "fltk",
                "m",
                "X11",
                "Xext",
                "pthread",
                "Xinerama",
                "Xfixes",
                "Xcursor",
                "Xft",
                "Xrender",
                "m",
                "fontconfig",
                "dl",
            ]
        }

        Group {     // Properties for the produced executable
            fileTagsFilter: "application"
            qbs.install: true
        }
    }
}



