if (MSVC)
    if(USE_MSVC_RUNTIME_LIBRARY_DLL)
        cmake_policy(SET CMP0091 NEW)
        set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>DLL")
    else()
        cmake_policy(SET CMP0091 NEW)
        set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
    endif()
endif()


if (BUILD_VIEWER OR BUILD_EDITOR)
    if (WIN32)
        set(boxer_src Boxer/boxer_win.cpp)
    elseif(APPLE)
        set(boxer_src Boxer/boxer_osx.mm)
    else()
        find_package(X11 REQUIRED)
        find_package(PkgConfig REQUIRED)
        pkg_check_modules(GTK3 REQUIRED gtk+-3.0)
        set(boxer_src Boxer/boxer_linux.cpp)
    endif()

    add_library(Boxer STATIC ${boxer_src})

    target_include_directories(Boxer PUBLIC Boxer/)

    if(UNIX AND NOT APPLE)
        target_include_directories(Boxer 
            PUBLIC
            ${GTK3_INCLUDE_DIRS}
            ${X11_INCLUDE_DIR})

        target_link_directories(Boxer PRIVATE ${GTK3_LIBRARY_DIRS})
        target_link_libraries(Boxer INTERFACE ${GTK3_LIBRARIES})
        add_definitions(${GTK3_CFLAGS_OTHER})
    endif()

    set(nfd_src
        nativefiledialog/src/include/nfd.h
        nativefiledialog/src/nfd_common.h
        nativefiledialog/src/nfd_common.c)

    if (WIN32)
        list(APPEND nfd_src nativefiledialog/src/nfd_win.cpp)
    elseif(APPLE)
        list(APPEND nfd_src nativefiledialog/src/nfd_cocoa.m)
    else()
        find_package(X11 REQUIRED)
        find_package(PkgConfig REQUIRED)
        pkg_check_modules(GTK3 REQUIRED gtk+-3.0)
        list(APPEND nfd_src nativefiledialog/src/nfd_gtk.c)
    endif()

    add_library(nfd STATIC ${nfd_src})
    target_include_directories(nfd PUBLIC nativefiledialog/src/include/)

    if(UNIX AND NOT APPLE)
        target_include_directories(nfd 
            PUBLIC
            ${GTK3_INCLUDE_DIRS}
            ${X11_INCLUDE_DIR})

        target_link_directories(nfd PRIVATE ${GTK3_LIBRARY_DIRS})
        target_link_libraries(nfd INTERFACE ${GTK3_LIBRARIES})
        add_definitions(${GTK3_CFLAGS_OTHER})
    endif()

    set(imgui_src
        imgui/imgui.cpp
        imgui/imgui_draw.cpp
        imgui/imgui_tables.cpp
        imgui/imgui_widgets.cpp)
    add_library(imgui STATIC ${imgui_src})
    target_include_directories(imgui PUBLIC imgui/)

    set(imgui-node-editor_src
        imgui-node-editor/crude_json.cpp
        imgui-node-editor/imgui_canvas.cpp
        imgui-node-editor/imgui_node_editor.cpp
        imgui-node-editor/imgui_node_editor_api.cpp)
    add_library(imgui-node-editor STATIC ${imgui-node-editor_src})
    target_include_directories(imgui-node-editor PUBLIC imgui-node-editor/)
    target_link_libraries(imgui-node-editor PRIVATE imgui)
endif()

