//
// Created by Dvir on 05/05/2019.
//

#ifndef CPP_PROJECT5_RANGE_HPP
#define CPP_PROJECT5_RANGE_HPP

#include <iostream>
#include "stdlib.h"
#include "iterator"
#include "list"

namespace itertools {

    using namespace std;

    template<typename T>
    class itRange {

        typedef T pointer;


    public:
        T a, b;

        itRange(T a, T b)
                : a(a), b(b) {}

    public:
        class iterator {
        public:
            decltype(a) ptr;

            iterator(pointer ptr)
                    : ptr(ptr) {}

            auto operator*() const {
                return ptr;
            }

            iterator &operator++() {
                ptr++;
                return *this;
            }

            const iterator& operator++(int) {
                iterator tmp = *this;
                ptr++;
                return tmp;

            }

            bool operator==(const iterator &it) const {
                return ptr == it.ptr;
            }

            bool operator!=(const iterator &it) const {
                return ptr != it.ptr;
            }

        };

        //end of class iterator
    public:
        iterator begin() {
            return iterator{a};
        }

        iterator end() {
            return iterator{b};
        }


    };

    template<typename T>
    itRange<T> range(T a, T b) {
        return itRange<T>(a, b);
    }
}


#endif //CPP_PROJECT5_RANGE_HPP
