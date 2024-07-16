cmake_minimum_required(VERSION 3.16)
project(Sorting_Algorithm_Visualization LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

add_executable(Sorting_Algorithm_Visualization src/main.cpp
        src/Algorithms/insertionSort.cpp
        src/Algorithms/insertionSort.h "src/Program.h" "src/Program.cpp"  "src/ui.cpp" "src/ui.h" "src/Algorithms/bubbleSort.h" "src/Algorithms/bubbleSort.cpp" "src/Algorithms/selectionSort.h" "src/Algorithms/selectionSort.cpp")
target_link_libraries(Sorting_Algorithm_Visualization PRIVATE sfml-graphics)
target_compile_features(Sorting_Algorithm_Visualization PRIVATE cxx_std_17)

if(WIN32)
    add_custom_command(
            TARGET Sorting_Algorithm_Visualization
            COMMENT "Copy OpenAL DLL"
            PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:Sorting_Algorithm_Visualization>
            VERBATIM)
endif()

install(TARGETS Sorting_Algorithm_Visualization)