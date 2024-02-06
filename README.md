# mlibc

This repository contains the practice questions for the studying C. Here you can find a set of problems designed to practice and gain C programming skills. For each important topic, there are several problems that will help you understand the basics of the C language and apply them in practice.

## Solution code

In other project folders you will find my solutions for each problem. The code was written using the practices that I knew at the time of studying the C language and can be improved in every possible way.

## Contents


1. [m_cat](https://github.com/pheroom/mlibc/blob/main/README.md#m_cat)
2. [m_grep](https://github.com/pheroom/mlibc/blob/main/README.md#m_grep)
2. [dsa_1](https://github.com/pheroom/mlibc/blob/main/README.md#dsa_1)

## Tasks

### m_cat

TEMPLATE: `cat [OPTION] [FILES]`

The cat utility shall read files in sequence and shall write their contents to the standard output in the same sequence.

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

### dsa_1

All the basic and advanced data structures and algorithms implementation section. In this basic paragraph it is necessary to implement a variety of simple algorithms and basic data structure. In particular sorting and recursion.

Implement data structures:
1. **stack** insertion of a new element and removal of an existing element takes place at the same end represented as the top of the stack
2. **queue** open at both ends and the operations are performed in First In First Out (FIFO) order
3. **hash map** associative array, maps keys to values

Implement functions:
1. **isPrime()** checking a number for primality
2. **sieveEratosthenes()** implements the Sieve of Eratosthenes algorithm
3. **max()** and **min()** find max and min value from of a array
4. **factorial()** find factorial form of a number
5. **gcd()** implements the Euclidean algorithm
6. **power()** fast find power of a number
7. **fib()** find Fibonacci sequence with a given length
8. **bubbleSort()** implements sinking sort
9. **selectSort()** is an in-place comparison sorting algorithm 
10. **insertSort()** builds the final sorted array (or list) one item at a time by comparisons
11. **counterSort()** counting the number of occurrences of each unique element in an array or list