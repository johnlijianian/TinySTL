//
// Created by LJN on 2021/2/27.
//

#ifndef TINYSTL_QUEUE_H
#define TINYSTL_QUEUE_H

#include "Deque.h"
#include "Functional.h"
#include "Vector.h"

namespace TinySTL{
    template<class T, class Container = TinySTL::deque<T>>
    class queue{
    public:
        typedef T value_type;
        typedef Container container_type;
        typedef typename Container::reference reference;
        typedef typename Container::const_reference const_reference;
        typedef typename Container::size_type size_type;

    private:
        Container container_;

    public:
        queue(){}
        explicit queue(const container_type& ctnr) :container_(ctnr){}

        bool empty() const{ return container_.empty(); }
        size_type size() const{ return container_.size(); }
        reference& front(){ return container_.front(); }
        const_reference& front() const{ return container_.front(); }
        reference& back(){ return container_.back(); }
        const_reference& back() const{ return container_.back(); }
        void push(const value_type& val){ container_.push_back(val); }
        void pop(){ container_.pop_front(); }
        void swap(queue& x){ container_.swap(x.container_); }

    public:
        template <class T_, class Container_>
        friend bool operator == (const queue<T_, Container_>& lhs, const queue<T_, Container_>& rhs);
        template <class T_, class Container_>
        friend bool operator != (const queue<T, Container_>& lhs, const queue<T_, Container_>& rhs);
        template <class T_, class Container_>
        friend void swap(queue<T_, Container_>& x, queue<T_, Container_>& y);
    };

    template <class T_, class Container_ = TinySTL::deque<T_>>
    bool operator != (const queue<T_, Container_>& lhs, const queue<T_, Container_>& rhs){
        return lhs.container_ != rhs.container_;
    }

    template <class T_, class Container_= TinySTL::deque<T_>>
    bool operator == (const queue<T_, Container_>& lhs, const queue<T_, Container_>& rhs){
        return lhs.container_ == rhs.container_;
    }

    template <class T_, class Container_ = TinySTL::deque<T_>>
    void swap(queue<T_, Container_>& x, queue<T_, Container_>& y){
        TinySTL::swap(x.container_, y.container_);
    }

    template <class T, class Container = TinySTL::vector<T>,
            class Compare = TinySTL::less<typename Container::value_type>>
    class priority_queue{
    public:
        typedef T value_type;
        typedef Container container_type;
        typedef typename Container::reference reference;
        typedef typename Container::const_reference const_reference;
        typedef typename Container::size_type size_type;

    private:
        container_type container_;
        Compare compare_;

    public:
        explicit priority_queue(const Compare& comp = Compare(),
                                const Container& ctnr = Container())
                : container_(ctnr), compare_(comp){}
        template <class InputIterator>
        priority_queue(InputIterator first, InputIterator last,
                       const Compare& comp = Compare(),
                       const Container& ctnr = Container())
                : container_(ctnr), compare_(comp){
            container_.insert(container_.end(), first, last);
            TinySTL::make_heap(container_.begin(), container_.end());
        }

        bool empty() const{
            return container_.empty();
        }
        size_type size() const{
            return container_.size();
        }
        reference top() {
            return container_.front();
        }

        void push(const value_type& val){
            container_.push_back(val);
            TinySTL::push_heap(container_.begin(), container_.end(), compare_);
        }
        void pop(){
            TinySTL::pop_heap(container_.begin(), container_.end(), compare_);
            container_.pop_back();
        }
        void swap(priority_queue& x){
            TinySTL::swap(container_, x.container_);
            TinySTL::swap(compare_, x.compare_);
        }
    public:
        template <class T_, class Container_, class Compare_>
        friend void swap(priority_queue<T_, Container_, Compare_>& x, priority_queue<T_, Container_, Compare_>& y);
        };

    template <class T_, class Container_, class Compare_>
    void swap(priority_queue<T_, Container_, Compare_>& x, priority_queue<T_, Container_, Compare_>& y){
        x.swap(y);
    }
}

#endif //TINYSTL_QUEUE_H
