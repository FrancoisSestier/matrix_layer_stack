cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

project(
  mls
  VERSION 0.1
  LANGUAGES CXX
)

if(PROJECT_SOURCE_DIR STREQUAL PROJECT_BINARY_DIR)
  message(
    FATAL_ERROR
      "In-source builds not allowed. Please make a new directory (called a build directory) and run CMake from there."
  )
endif()

include(cmake/tools.cmake)
include(cmake/CPM.cmake)
CPMAddPackage("gh:TheLartians/PackageProject.cmake@1.6.0")

file(GLOB_RECURSE headers CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp")

add_library(mls_headers EXCLUDE_FROM_ALL ${headers})
set_target_properties(mls_headers PROPERTIES LINKER_LANGUAGE CXX)

add_library(mls INTERFACE)

set_target_properties(mls PROPERTIES INTERFACE_COMPILE_FEATURES cxx_std_20)
target_compile_options(mls INTERFACE "$<$<COMPILE_LANG_AND_ID:CXX,MSVC>:/permissive->")

target_include_directories(mls
INTERFACE
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include/${PROJECT_NAME}-${PROJECT_VERSION}>
)

packageProject(
  NAME ${PROJECT_NAME}
  VERSION ${PROJECT_VERSION}
  BINARY_DIR ${PROJECT_BINARY_DIR}
  INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include
  INCLUDE_DESTINATION include/${PROJECT_NAME}-${PROJECT_VERSION}
)