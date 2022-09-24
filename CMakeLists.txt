cmake_minimum_required(VERSION 3.16)

# set the project name and version
project(eval_sort)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(eval "main.cpp" 
                    "lib/utils.cpp" 
                    "lib/insertion_sort.cpp" 
                    "lib/quick_sort.cpp"
                    "lib/bubble_sort.cpp"
                    "lib/bucket_sort.cpp"
                    "lib/merge_sort.cpp")