cmake_minimum_required(VERSION 3.20)
project(TinySTL)

set(CMAKE_CXX_STANDARD 14)

add_executable(TinySTL main.cpp Detail/Alloc.cpp Allocator.h Construct.h TypeTraits.h Vector.h Iterator.h ReverseIterator.h UninitializedFunctions.h Algorithm.h Detail/Vector.impl.h Test/TestUtil.h Test/VectorTest.h Test/VectorTest.cpp Utility.h Functional.h List.h Detail/List.impl.h Test/ListTest.h Test/ListTest.cpp Deque.h Detail/Deque_impl.h Test/DequeTest.h Test/DequeTest.cpp Queue.h Test/QueueTest.h Test/QueueTest.cpp Test/PriorityQueueTest.h Test/PriorityQueueTest.cpp Unordered_set.h Stack.h CirclularBuffer.h String.h Detail/String.cpp Detail/Unordered_set.impl.h Bitmap.h Detail/Bitmap.impl.h Memory.h Detail/Ref.h Detail/CircularBuffer.impl.h Test/AlgorithmTest.h Test/AlgorithmTest.cpp Test/BitmapTest.h Test/BitmapTest.cpp Test/CircularBufferTest.h Test/CircularBufferTest.cpp Test/RefTest.h Test/RefTest.cpp Test/SharedPtrTest.h Test/SharedPtrTest.cpp Test/StackTest.h Test/StackTest.cpp Test/StringTest.h Test/StringTest.cpp Test/TypeTraitsTest.h Test/TypeTraitsTest.cpp Test/Unordered_setTest.h Test/Unordered_setTest.cpp Test/UniquePtrTest.h Test/UniquePtrTest.cpp)
