cmake_minimum_required(VERSION 3.26)
project(mlibc)

set(CMAKE_C_STANDARD 11)

add_executable(m_cat m_cat/m_cat.c m_cat/m_cat.h)
add_executable(m_grep m_grep/m_grep.c m_grep/m_grep.h)
add_executable(dsa_1
                dsa_1/dsa_1.c dsa_1/dsa_1.h
                dsa_1/dsa_1_sorts.c dsa_1/dsa_1_sorts.h
                dsa_1/dsa_1_stack.c dsa_1/dsa_1_stack.h
                dsa_1/dsa_1_hashmap.c dsa_1/dsa_1_hashmap.h)
