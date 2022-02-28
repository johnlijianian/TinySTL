cmake_minimum_required(VERSION 3.20)
project(TinySTL)

set(CMAKE_CXX_STANDARD 14)

add_executable(TinySTL main.cpp Detail/Alloc.cpp Allocator.h Construct.h TypeTraits.h Vector.h Iterator.h ReverseIterator.h UninitializedFunctions.h Algorithm.h Detail/Vector.impl.h Test/TestUtil.h Test/VectorTest.h Test/VectorTest.cpp Utility.h Functional.h List.h Detail/List.impl.h Test/ListTest.h Test/ListTest.cpp Deque.h Detail/Deque_impl.h Test/DequeTest.h Test/DequeTest.cpp Queue.h Test/QueueTest.h Test/QueueTest.cpp Test/PriorityQueueTest.h Test/PriorityQueueTest.cpp Unordered_set.h)
