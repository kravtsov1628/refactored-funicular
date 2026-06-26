cmake_minimum_required(VERSION 3.15)
project(Laba8 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_PREFIX_PATH "C:/msys64/ucrt64")

find_package(OpenCV REQUIRED)
find_package(OpenSSL REQUIRED)

add_executable(Laba8 main.cpp task1.h task1.cpp task2.h task2.cpp task3.h task3.cpp )

target_include_directories(Laba8 PRIVATE ${OpenCV_INCLUDE_DIRS} ${OPENSSL_INCLUDE_DIR})
target_link_libraries(Laba8 PRIVATE ${OpenCV_LIBS} OpenSSL::Crypto)