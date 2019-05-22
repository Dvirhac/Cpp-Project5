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
    class range {

        typedef T pointer;


    public:
        const T a;
        const T b;

        range(const T& a,const T& b)
                : a(a), b(b) {}

    public:
        class iterator {
        public:
            T ptr;



            iterator(const pointer ptr)
                    : ptr(ptr) {}


            T operator*() const {
                return ptr;
            }


            const iterator &operator++() {
                ptr++;
                return *this;
            }

            const iterator operator++(int) {
                iterator tmp = *this;
                ptr++;
                return tmp;

            }

            bool operator==(const iterator &it) const {
                return ptr == it.ptr;
            }

            bool operator!=(const iterator &it) const {
                return !(ptr == it.ptr);
            }

        };

        //end of class iterator
    public:
        iterator begin() const {
            return iterator{a};
        }

        iterator end() const {
            return iterator{b};
        }

        int  length()const {
            auto itStart = a;
            auto itEnd = b;
            int counter = 0;

            while(itStart != itEnd){
                counter++;
                itStart++;
            }
            return counter;

        }

    };

    template<typename T>
    range<T> rangeC(T a, T b) {
        return range<T>(a, b);
    }


}


#endif //CPP_PROJECT5_RANGE_HPP
