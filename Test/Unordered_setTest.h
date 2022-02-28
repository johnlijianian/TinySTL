//
// Created by LJN on 2021/2/28.
//

#ifndef TINYSTL_UNORDERED_SETTEST_H
#define TINYSTL_UNORDERED_SETTEST_H

#include "TestUtil.h"

#include "../Unordered_set.h"
#include <unordered_set>

#include <algorithm>
#include <cassert>
#include <random>
#include <string>
#include <vector>

namespace TinySTL{
    namespace Unordered_setTest{
        template<class T>
        using stdUst = std::unordered_set < T > ;
        template<class T>
        using tsUst = TinySTL::Unordered_set < T > ;

        void testCase1();
        void testCase2();
        void testCase3();
        void testCase4();
        void testCase5();

        void testAllCases();
    }
}

#endif //TINYSTL_UNORDERED_SETTEST_H
