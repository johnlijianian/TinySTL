//
// Created by LJN on 2021/2/27.
//

#ifndef TINYSTL_UTILITY_H
#define TINYSTL_UTILITY_H
namespace TinySTL{
    //************ [swap] ***************
    template<class T>
    void swap(T& a, T& b){
        T temp = a;
        a = b;
        b = temp;
    }
}

#endif //TINYSTL_UTILITY_H
