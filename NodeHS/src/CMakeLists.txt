## Note; This file always accompanies the source files that are being tested.

## The name of the project can be changed to anything.
project(NODEHS)

## Header files of source code.
set(HEADER_FILES NodeHS.h)

## Implementation files of source code.
set(SOURCE_FILES NodeHS.cpp)

## The name of the project goes first.
add_library(NODEHS ${SOURCE_FILES} ${HEADER_FILES})
