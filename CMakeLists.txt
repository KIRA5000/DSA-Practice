cmake_minimum_required(VERSION 3.0)

# set(CMAKE_VERBOSE_MAKEFILE ON)

project(Cpp-programs)

add_executable(Test Amazon-8.cpp)

if (WIN32)
  SET (CMAKE_CXX_FLAGS_RELEASE "/Zi /Od")
  SET_TARGET_PROPERTIES(
   Test PROPERTIES LINK_FLAGS 
   "/DEBUG /OPT:REF /OPT:ICF"
  )
endif (WIN32)

SET_PROPERTY(TARGET Test PROPERTY CXX_STANDARD 17)

target_include_directories(
 Test
 PRIVATE
 ${CMAKE_CURRENT_SOURCE_DIR}
 ${CMAKE_CURRENT_SOURCE_DIR}/INCLUDE
)

target_link_libraries(Test wbemuuid.lib)