//
// Created by LJN on 2022/2/27.
//

#ifndef TINYSTL_UNORDERED_SET_H
#define TINYSTL_UNORDERED_SET_H

#include "Allocator.h"
#include "Algorithm.h"
#include "Functional.h"
#include "Iterator.h"
#include "List.h"
#include "Vector.h"

namespace TinySTL{
//    template < class Key,            //容器中存储元素的类型
//            class Hash = hash<Key>,    //确定元素存储位置所用的哈希函数
//            class Pred = equal_to<Key>,   //判断各个元素是否相等所用的函数
//            class Alloc = allocator<Key>   //指定分配器对象的类型
//    > class unordered_set;
    template<class Key, class Hash, class KeyEqual, class Allocator>
    class Unordered_set;

    namespace Detail{
        template<class Key, class ListIterator, class Hash = std::hash<Key>,
                class KeyEqual = TinySTL::equal_to<Key>, class Allocator = TinySTL::allocator < Key >>
                class KeyEqual = TinySTL::equal_to<Key>, class Allocator = TinySTL::allocator < Key >>
                class ust_iterator : public iterator<forward_iterator_tag, Key>{
                private:
                    template<class Key, class Hash, class KeyEqual, class Allocator>
                    friend class Unordered_set;

                private:
                    typedef Unordered_set<Key, Hash, KeyEqual, Allocator>* cntrPtr;
                    size_t bucket_index_;
                    ListIterator iterator_;
                    cntrPtr container_;

                public:
                    ust_iterator(size_t index, ListIterator it, cntrPtr ptr);
                    ust_iterator& operator ++();
                    ust_iterator operator ++(int);
                    Key& operator*(){ return *iterator_; }
                    Key* operator->(){ return &(operator*()); }

                private:
                    template<class Key, class ListIterator, class Hash, class KeyEqual, class Allocator>
                    friend bool operator ==(const ust_iterator<Key, ListIterator, Hash, KeyEqual, Allocator>& lhs,
                                            const ust_iterator<Key, ListIterator, Hash, KeyEqual, Allocator>& rhs);
                    template<class Key, class ListIterator, class Hash, class KeyEqual, class Allocator>
                    friend bool operator !=(const ust_iterator<Key, ListIterator, Hash, KeyEqual, Allocator>& lhs,
                                            const ust_iterator<Key, ListIterator, Hash, KeyEqual, Allocator>& rhs);
                };
    }//end of namespace Detail

    template<class Key, class Hash = std::hash<Key>,
            class KeyEqual = TinySTL::equal_to<Key>, class Allocator = TinySTL::allocator < Key >>
    class Unordered_set{
    private:
        template<class Key, class ListIterator, class Hash, class KeyEqual, class Allocator>
        friend class Detail::ust_iterator;

    public:
        typedef Key key_type;
        typedef Key value_type;
        typedef size_t size_type;
        typedef Hash haser;
        typedef KeyEqual key_equal;
        typedef Allocator allocator_type;
        typedef value_type& reference;
        typedef const value_type& const_reference;
        typedef typename TinySTL::list<key_type>::iterator local_iterator;
        typedef Detail::ust_iterator<Key, typename TinySTL::list<key_type>::iterator, Hash, KeyEqual, Allocator> iterator;

    private:
        TinySTL::vector<TinySTL::list<key_type>> buckets_;
        size_type size_;
        float max_load_factor_;
    };
}

#endif //TINYSTL_UNORDERED_SET_H
