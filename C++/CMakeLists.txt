cmake_minimum_required(VERSION 3.13)
project(C__)

set(CMAKE_CXX_STANDARD 14)

add_executable(C__ main.cpp TwoSum.cpp ReverseInteger.cpp ValidParentheses.cpp MergeTwoSortedLists.cpp ImplementStrStr.cpp
        CountAndSay.cpp NumberOf1Bits.cpp MultiplyStrings.cpp)

include_directories(./)