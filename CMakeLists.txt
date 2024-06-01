cmake_minimum_required(VERSION 3.13 FATAL_ERROR)
project( CPPBasicsTest )

set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_CXX_EXTENSIONS OFF )
set( CMAKE_CXX_STANDARD_REQUIRED ON )

set( APP_EXECUTABLE CPPBasicsTest )

include_directories( inc )

ADD_EXECUTABLE(CPPBasics "src/CPPBasics.cpp")

ADD_EXECUTABLE( ${APP_EXECUTABLE} "src/CPPBasicsTest.cpp"  "src/CPPBasics.cpp")

target_compile_definitions(CPPBasicsTest PRIVATE TESTING)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

set_property( DIRECTORY PROPERTY VS_STARTUP_PROJECT ${APP_EXECUTABLE} )

include (CTest)
add_test(${APP_EXECUTABLE}_testCPPBasics ${APP_EXECUTABLE} 1)

find_program(VALGRIND "valgrind")
if(VALGRIND)
	add_custom_target(valgrind
    COMMAND "${VALGRIND}" --tool=memcheck --leak-check=yes --show-reachable=yes --error-exitcode=1 $<TARGET_FILE:${APP_EXECUTABLE}>)
endif()
