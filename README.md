# mlibc

This repository contains the practice questions for the studying C. Here you can find a set of problems designed to practice and gain C programming skills. For each important topic, there are several problems that will help you understand the basics of the C language and apply them in practice.

## Solution code

In other project folders you will find my solutions for each problem. The code was written using the practices that I knew at the time of studying the C language and can be improved in every possible way.

## Contents


1. [m_cat](https://github.com/pheroom/mlibc/blob/main/README.md#m_cat)
2. [m_grep](https://github.com/pheroom/mlibc/blob/main/README.md#m_grep)

## Tasks

### m_cat

TEMPLATE: `cat [OPTION] [FILES]`

The cat utility shall read files in sequence and shall write
their contents to the standard output in the same sequence.

Flags:
1. **-b** numbers only non-empty lines
2. **-e** but also display end-of-line characters as $
3. **-n** number all output lines
4. **-s** squeeze multiple adjacent blank lines
5. **-t** but also display tabs as ^I

### m_grep 

TEMPLATE: `grep [OPTION] [FILE]`

Given one or more patterns, grep searches input files for matches to the patterns. When it finds a match in a line, it copies the line to standard output (by default), or produces whatever other sort of output you have requested with options.

Flags:
1. **-e** pattern
2. **-i** ignore uppercase vs. lowercase
3. **-v** invert match
4. **-c** output count of matching lines only.
5. **-l** output matching files only
6. **-n** precede each matching line with a line number
7. **-h** output matching lines without preceding them by file names
8. **-s** suppress error messages about nonexistent or unreadable files
9. **-f file** take regexes from a file
10. **-o** output the matched parts of a matching line
