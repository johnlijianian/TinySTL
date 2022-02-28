#include <iostream>

#include "Algorithm.h"

#include "Test/AlgorithmTest.h"
#include "Test/VectorTest.h"
#include "Test/ListTest.h"
#include "Test/DequeTest.h"
#include "Test/PriorityQueueTest.h"
#include "Test/QueueTest.h"
#include "Test/BitmapTest.h"
#include "Test/CircularBufferTest.h"
#include "Test/DequeTest.h"
#include "Test/PriorityQueueTest.h"
#include "Test/QueueTest.h"
#include "Test/RefTest.h"
#include "Test/SharedPtrTest.h"
#include "Test/StackTest.h"
#include "Test/StringTest.h"
#include "Test/TypeTraitsTest.h"
#include "Test/UniquePtrTest.h"
#include "Test/Unordered_setTest.h"


int main(){
    TinySTL::VectorTest::testAllCases();
//    TinySTL::ListTest::testAllCases();
    TinySTL::DequeTest::testAllCases();
    TinySTL::PriorityQueueTest::testAllCases();
    TinySTL::QueueTest::testAllCases();
    TinySTL::BitmapTest::testAllCases();
    TinySTL::CircularBufferTest::testAllCases();
    TinySTL::DequeTest::testAllCases();
    TinySTL::RefTest::testAllCases();
    TinySTL::SharedPtrTest::testAllCases();
    TinySTL::StackTest::testAllCases();
    TinySTL::StringTest::testAllCases();
    TinySTL::TypeTraitsTest::testAllCases();
    TinySTL::UniquePtrTest::testAllCases();
    TinySTL::Unordered_setTest::testAllCases();

    std::cin.get();
    return 0;
}