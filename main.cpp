#include <iostream>

#include "Algorithm.h"

#include "Test/VectorTest.h"
#include "Test/ListTest.h"
#include "Test/DequeTest.h"
#include "Test/PriorityQueueTest.h"
#include "Test/QueueTest.h"

int main(){
    TinySTL::VectorTest::testAllCases();
//    TinySTL::ListTest::testAllCases();
    TinySTL::DequeTest::testAllCases();
    TinySTL::PriorityQueueTest::testAllCases();
    TinySTL::QueueTest::testAllCases();
    std::cin.get();
    return 0;
}