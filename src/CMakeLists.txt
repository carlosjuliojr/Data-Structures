###############################################################################
# @file CMakeLists.txt
# @project server for the simulations of processes
# @brief  CMakeLists.txt principal for  the simulations of processes
# @details this doc contains all requirements needs for the execution
# @author Ronald Sulbaran and Julio Jaimes R, ronaldanto03@gmail.com, carlosjuliojr@hotmail.com
# @date 15/10/2016
###############################################################################


cmake_minimum_required(VERSION 2.8.9)
project(directory_test)

#Bring the headers, such as Student.h into the project
#include_directories(../include)

set(library_sources
   CMakeLists.txt
   node.h
   node2.h
   node2.cpp
   singlelinkedlist.h
   node.cpp
   singlelinkedlist.cpp
   doublylinkedlist.h
   doublylinkedlist.cpp
  )

add_library(datelib ${library_sources})
#FILE(GLOB files "*.h")

#INSTALL(TARGETS ${datelib} DESTINATION lib)
