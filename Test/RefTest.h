//
// Created by LJN on 2021/2/28.
//

#ifndef TINYSTL_REFTEST_H
#define TINYSTL_REFTEST_H
#include "../Detail/Ref.h"

#include <cassert>

namespace TinySTL{
    namespace RefTest{
        template<class T>
        using ref_t = TinySTL::Detail::ref_t < T > ;

        void testCaseRef();
        void testAllCases();
    }
}
#endif //TINYSTL_REFTEST_H
