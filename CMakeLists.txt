cmake_minimum_required(VERSION 3.1)
project(NeuralNet CXX)

AUX_SOURCE_DIRECTORY(src NeuralNetsources)
add_library(NeuralNet ${NeuralNetsources})

add_library(NeuralNet::NeuralNet ALIAS NeuralNet)

target_include_directories(NeuralNet PUBLIC
"$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
)

target_compile_features(NeuralNet PUBLIC
cxx_constexpr
cxx_final
cxx_nullptr
cxx_noexcept
cxx_override
)

target_compile_options(NeuralNet PRIVATE
-Wall
-Wextra
-g
)

add_subdirectory(test)
