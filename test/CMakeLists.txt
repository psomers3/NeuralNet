cmake_minimum_required(VERSION 3.1)
project(neural_test CXX)

# Add aUSsie test
add_executable(neural_test test.cpp)

target_include_directories(neural_test PUBLIC
"$<BUILD_INTERFACE:${include_dir}>")

target_compile_features(neural_test PUBLIC
cxx_constexpr
cxx_final
cxx_nullptr
cxx_noexcept
cxx_override
)
target_compile_options(neural_test PRIVATE
-Wall
-Wextra
-g
)

# Link to necessary test libraries
target_link_libraries(neural_test NeuralNet)
