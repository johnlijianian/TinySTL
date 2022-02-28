//
// Created by LJN on 2021/2/27.
//

#ifndef TINYSTL_QUEUETEST_H
#define TINYSTL_QUEUETEST_H

#include "TestUtil.h"

#include "../Queue.h"
#include <queue>

#include <cassert>
#include <string>

namespace TinySTL{
    namespace QueueTest{
        template<class T>
        using stdQ = std::queue < T > ;
        template<class T>
        using tsQ = TinySTL::queue < T > ;

        void testCase1();
        void testCase2();
        void testCase3();
        void testCase4();
        void testCase5();

        void testAllCases();
    }
}

#endif //TINYSTL_QUEUETEST_H
