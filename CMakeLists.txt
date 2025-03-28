cmake_minimum_required(VERSION 3.20) #versione CMake
project("ComplexNumber")
 
set(CMAKE_CXX_STANDARD 20) #versione C++
set(CMAKE_CXX_STANDARD_REQUIRED ON) #versione C++ richiesta

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow") #imposta i flag per il compilatore

#aggiungo eseguibili del progetto
add_executable(${PROJECT_NAME}
    main.cpp
    "${CMAKE_CURRENT_SOURCE_DIR}/complex_number.hpp"
    ${SumValues_SOURCES}
    ${SumValues_HEADERS})

target_link_libraries(${PROJECT_NAME} ${SumValues_LINKED_LIBRARIES})
target_include_directories(${PROJECT_NAME} PRIVATE ${SumValues_INCLUDE})
target_compile_options(${PROJECT_NAME} PUBLIC -fPIC)
