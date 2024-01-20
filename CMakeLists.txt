cmake_minimum_required(VERSION 3.26)
project(mlibc)

set(CMAKE_C_STANDARD 11)

add_executable(m_cat m_cat/m_cat.c m_cat/m_cat.h)
add_executable(m_grep m_grep/m_grep.c m_grep/m_grep.h)