cmake_minimum_required(VERSION 3.5)

project (data_structures)


find_package(Qt5Widgets PATHS "/home/julio/Qt/5.6/gcc_64/lib/cmake" REQUIRED)
add_definitions(-std=c++11)



add_subdirectory(src)
add_subdirectory(include)
add_subdirectory(test)
add_subdirectory(external)
#add_subdirectory(tests)



