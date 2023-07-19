project(demo)
cmake_minimum_required(VERSION 3.24)

# ------ 全局变量：子目录下可引用 ------ #
set(PROJECT_OUTOUT_DIR ${PROJECT_BINARY_DIR}/output)
set(PROJECT_OUTOUT_BIN_DIR ${PROJECT_OUTOUT_DIR}/bin)
set(PROJECT_OUTOUT_INC_DIR ${PROJECT_OUTOUT_DIR}/include)
set(PROJECT_OUTOUT_LIB_DIR ${PROJECT_OUTOUT_DIR}/lib)
set(PROJECT_OUTOUT_ETC_DIR ${PROJECT_OUTOUT_DIR}/etc)

# Init
file(MAKE_DIRECTORY ${PROJECT_OUTOUT_DIR})
file(MAKE_DIRECTORY ${PROJECT_OUTOUT_BIN_DIR})
file(MAKE_DIRECTORY ${PROJECT_OUTOUT_INC_DIR})
file(MAKE_DIRECTORY ${PROJECT_OUTOUT_LIB_DIR})
file(MAKE_DIRECTORY ${PROJECT_OUTOUT_ETC_DIR})

set(WORKROOT "/Users/hexueyuan/Workroot/CPPRELEASE")
include_directories(${WORKROOT}/include)
link_directories(${WORKROOT}/lib)

set(CMAKE_CXX_STANDARD 17) # C++17
set(CMAKE_OSX_ARCHITECTURES "arm64")

set(DYNAMIC_LIB ${DYNAMIC_LIB}
        pthread
        "-framework CoreFoundation"
        "-framework CoreGraphics"
        "-framework CoreData"
        "-framework CoreText"
        "-framework Security"
        "-framework Foundation"
        "-Wl,-U,_MallocExtension_ReleaseFreeMemory"
        "-Wl,-U,_ProfilerStart"
        "-Wl,-U,_ProfilerStop")

add_subdirectory(src)