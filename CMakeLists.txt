cmake_minimum_required(VERSION 3.17)
set(CMAKE_GENERATOR_PLATFORM Win32)
project(Patcher VERSION 1.0 LANGUAGES CSharp CXX)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(Patcher)
add_subdirectory(Loader)

make_directory(Binaries)
if(EXISTS ${PROJECT_SOURCE_DIR}/Patcher/Release/Patcher.dll)
	configure_file(${PROJECT_SOURCE_DIR}/Patcher/Release/Patcher.dll ${PROJECT_SOURCE_DIR}/Binaries/Patcher.dll COPYONLY)
endif()
if(EXISTS ${PROJECT_SOURCE_DIR}/Loader/Release/wininet.dll)
	configure_file(${PROJECT_SOURCE_DIR}/Loader/Release/wininet.dll ${PROJECT_SOURCE_DIR}/Binaries/wininet.dll COPYONLY)
endif()