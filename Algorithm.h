//
// Created by LJN on 2022/2/24.
//

#ifndef TINYSTL_ALGORITHM_H
#define TINYSTL_ALGORITHM_H

#include <cstring>
#include <utility>

#include "Allocator.h"
#include "Functional.h"
#include "Iterator.h"
#include "TypeTraits.h"
#include "Utility.h"

namespace TinySTL{
    //*********** [min] ********************
    //********* [Algorithm Complexity: O(1)] ****************
    template <class T>
    const T& min(const T& a, const T& b){
        return !(b < a) ? a : b;
    }
    template <class T, class Compare>
    const T& min(const T& a, const T& b, Compare comp){
        return !comp(b, a) ? a : b;
    }
    //*********** [max] ********************
    //********* [Algorithm Complexity: O(1)] ****************
    template <class T>
    const T& max(const T& a, const T& b){
        return (a < b) ? b : a;
    }
    template <class T, class Compare>
    const T& max(const T& a, const T& b, Compare comp){
        return (copm(a, b)) ? b : a;
    }

    //********** [equal] ******************************
    //********* [Algorithm Complexity: O(N)] ****************
    template <class InputIterator1, class InputIterator2>
    bool equal(InputIterator1 first1, InputIterator1 last1,
               InputIterator2 first2){
        return TinySTL::equal(first1, last1, first2, TinySTL::equal_to<typename TinySTL::iterator_traits<InputIterator1>::value_type>());
    }
    template <class InputIterator1, class InputIterator2, class BinaryPredicate>
    bool equal(InputIterator1 first1, InputIterator1 last1,
               InputIterator2 first2, BinaryPredicate pred){
        for (; first1 != last1; ++first1, ++first2){
            if (!pred(*first1, *first2))
                return false;
        }
        return true;
    }

    //********* [fill_n] ********************
    //********* [Algorithm Complexity: O(N)] ****************
    template<class OutputIterator, class Size, class T>
    OutputIterator fill_n(OutputIterator first, Size n, const T& value)
    {
        for (; n > 0; --n, ++first)
            *first = value;
        return first;
    }
    template<class Size>
    char *fill_n(char *first, Size n, const char& value)
    {
        memset(first, static_cast<unsigned char>(value), n);
        return first + n;
    }
    template<class Size>
    wchar_t *fill_n(wchar_t *first, Size n, const wchar_t& value)
    {
        memset(first, static_cast<unsigned char>(value), n * sizeof(wchar_t));
        return first + n;
    }
    //********** [distance] ******************************
    //********* [Algorithm Complexity: O(N)] ****************
    template<class InputIterator>
    typename iterator_traits<InputIterator>::difference_type
    _distance(InputIterator first, InputIterator last, input_iterator_tag){
        typename iterator_traits<InputIterator>::difference_type dist = 0;
        while (first++ != last){
            ++dist;
        }
        return dist;
    }
    template<class RandomIterator>
    typename iterator_traits<RandomIterator>::difference_type
    _distance(RandomIterator first, RandomIterator last, random_access_iterator_tag){
        auto dist = last - first;
        return dist;
    }
    template<class Iterator>
    typename iterator_traits<Iterator>::difference_type
    distance(Iterator first, Iterator last){
        typedef typename iterator_traits<Iterator>::iterator_category iterator_category;
        return _distance(first, last, iterator_category());
    }
    //********** [make_heap] ***************
    //********* [Algorithm Complexity: O(N)] ****************
    template<class RandomAccessIterator, class Compare>
    //heap上溯算法
    static void up(RandomAccessIterator first, RandomAccessIterator last,
                   RandomAccessIterator head, Compare comp){//1.[first, last], 2.headr points the header of the heap
        if (first != last){
            int index = last - head;
            auto parentIndex = (index - 1) / 2;
            for (auto cur = last; parentIndex >= 0 && cur != head; parentIndex = (index - 1) / 2){
                auto parent = head + parentIndex;//get parent
                if (comp(*parent, *cur))
                    TinySTL::swap(*parent, *cur);
                cur = parent;
                index = cur - head;
            }
        }
    }
    template<class RandomAccessIterator, class Compare>
    //heap下降算法
    static void down(RandomAccessIterator first, RandomAccessIterator last,
                     RandomAccessIterator head, Compare comp){//1.[first, last], 2.headr points the header of the heap
        if (first != last){
            auto index = first - head;
            auto leftChildIndex = index * 2 + 1;
            for (auto cur = first; leftChildIndex < (last - head + 1) && cur < last; leftChildIndex = index * 2 + 1){
                auto child = head + leftChildIndex;//get the left child
                if ((child + 1) <= last && *(child + 1) > *child)//cur has a right child
                    child = child + 1;
                if (comp(*cur, *child))
                    TinySTL::swap(*cur, *child);
                cur = child;
                index = cur - head;
            }
        }
    }

    template <class RandomAccessIterator, class Compare>
    void make_heap(RandomAccessIterator first, RandomAccessIterator last, Compare comp){
        const auto range = last - first;
        for (auto cur = first + range / 2 - 1; cur >= first; --cur){
            TinySTL::down(cur, last - 1, first, comp);
            if (cur == first) return;
        }
    }

    template <class RandomAccessIterator>
    void make_heap(RandomAccessIterator first, RandomAccessIterator last){
        TinySTL::make_heap(first, last,
                           typename TinySTL::less<typename TinySTL::iterator_traits<RandomAccessIterator>::value_type>());
    }

    //********* [push_heap] ***************
    //********* [Algorithm Complexity: O(lgN)] ****************
    template <class RandomAccessIterator>
    void push_heap(RandomAccessIterator first, RandomAccessIterator last){
        TinySTL::push_heap(first, last,
                           TinySTL::less<typename TinySTL::iterator_traits<RandomAccessIterator>::value_type>());
    }
    template <class RandomAccessIterator, class Compare>
    void push_heap(RandomAccessIterator first, RandomAccessIterator last, Compare comp){
        TinySTL::up(first, last - 1, first, comp);
    }
    //********* [pop_heap] ***************
    //********* [Algorithm Complexity: O(lgN)] ****************
    template <class RandomAccessIterator>
    void pop_heap(RandomAccessIterator first, RandomAccessIterator last){
        TinySTL::pop_heap(first, last,
                          TinySTL::less<typename TinySTL::iterator_traits<RandomAccessIterator>::value_type>());
    }
    template <class RandomAccessIterator, class Compare>
    void pop_heap(RandomAccessIterator first, RandomAccessIterator last, Compare comp){
        TinySTL::swap(*first, *(last - 1));
        if (last - first >= 2)
            TinySTL::down(first, last - 2, first, comp);
    }
}

#endif //TINYSTL_ALGORITHM_H
