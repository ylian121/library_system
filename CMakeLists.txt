CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

ADD_SUBDIRECTORY(googletest)


ADD_EXECUTABLE(test
   test/booktest.cpp
   test/libraryTest.cpp
)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)