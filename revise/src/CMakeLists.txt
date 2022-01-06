cmake_minimum_required(VERSION 3.5)

project(revise LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
link_libraries(-lcurl)


add_executable(revise main.cpp
	read_url.h read_url.cpp
	read_file.h read_file.cpp
	pur_test_online.h pur_test_online.cpp
	wrfile.h wrfile.cpp
	analizer.h analizer.cpp
	test_original.h test_original.cpp
	help.h help.cpp
	keys.h)

install (TARGETS revise
	DESTINATION ${CMAKE_INSTALL_DIR})
