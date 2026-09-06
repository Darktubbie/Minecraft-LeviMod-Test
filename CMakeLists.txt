cmake_minimum_required(VERSION 3.22)

project(bedrock_minimal LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(MOD_ID "bedrock_minimal" CACHE STRING "")
set(MOD_NAME "Bedrock Minimal" CACHE STRING "")
set(MOD_AUTHOR "DarkTubbie" CACHE STRING "")
set(MOD_VERSION "0.1.0" CACHE STRING "")
set(MOD_LIBRARY_NAME "bedrock_minimal" CACHE STRING "")
set(MOD_MINECRAFT_VERSIONS "[\"1.26.*\"]" CACHE STRING "")

include(FetchContent)

FetchContent_Declare(
    preloader_android
    GIT_REPOSITORY https://github.com/LiteLDev/preloader-android.git
    GIT_TAG 0.2.2
)

FetchContent_MakeAvailable(preloader_android)

add_library(
    ${MOD_LIBRARY_NAME}
    SHARED
    src/main.cpp
    src/mod/MyMod.cpp
)

target_include_directories(
    ${MOD_LIBRARY_NAME}
    PRIVATE
    src
    ${preloader_android_SOURCE_DIR}/include
)

target_link_libraries(
    ${MOD_LIBRARY_NAME}
    PRIVATE
    preloader
)

find_library(log-lib log)

target_link_libraries(
    ${MOD_LIBRARY_NAME}
    PRIVATE
    ${log-lib}
)

set(PACK_ROOT
    "${CMAKE_CURRENT_BINARY_DIR}/package"
)

set(PACK_MOD
    "${PACK_ROOT}/${MOD_ID}"
)

configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/manifest.json.in"
    "${CMAKE_CURRENT_BINARY_DIR}/manifest.json"
    @ONLY
)

add_custom_target(
    levi_package

    COMMAND ${CMAKE_COMMAND} -E rm -rf
        "${PACK_ROOT}"

    COMMAND ${CMAKE_COMMAND} -E make_directory
        "${PACK_MOD}"

    COMMAND ${CMAKE_COMMAND} -E copy
        "$<TARGET_FILE:${MOD_LIBRARY_NAME}>"
        "${PACK_MOD}/lib${MOD_LIBRARY_NAME}.so"

    COMMAND ${CMAKE_COMMAND} -E copy
        "${CMAKE_CURRENT_BINARY_DIR}/manifest.json"
        "${PACK_MOD}/manifest.json"

    COMMAND ${CMAKE_COMMAND} -E chdir
        "${PACK_ROOT}"
        ${CMAKE_COMMAND} -E tar
        "${CMAKE_CURRENT_BINARY_DIR}/${MOD_ID}-${MOD_VERSION}.levipack"
        --format=zip
        "${MOD_ID}"

    DEPENDS
        ${MOD_LIBRARY_NAME}

    VERBATIM
)
