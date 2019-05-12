
//
// Created by Dvir on 05/05/2019.
//

#ifndef CPP_PROJECT5_CHAIN_HPP
#define CPP_PROJECT5_CHAIN_HPP

#include "range.hpp"

namespace itertools {
    template <typename T>
    class chain {
        typedef T*  pointer;
    private:
        static range<T> r1;
        static range<T> r2;


    public:

        chain(range<T> r1 , range<T> r2){
            this->r1 = r1;
            this->r2 = r2;

        }


        // begin of class iterator

        class iterator {
        private:
            pointer ptr1;
            pointer ptr2;

        public:
            iterator(pointer ptr1 = nullptr, pointer ptr2 = nullptr)
                    : ptr1(ptr1), ptr2(ptr2) {}

            range<T>& operator*() const {
                return *this->ptr1;

            }

            iterator& operator++() {
                return r1.begin().operator++();
            }

            const iterator operator++(int) {
                iterator tmp = r1.begin().operator++(1);
                ptr1++;
                return tmp;

            }

            bool operator==(const iterator &it) const {
                return ptr1 == it.ptr1;
            }

            bool operator!=(const iterator& it) const {
                return *ptr1 != *it.ptr1;
            }

        };

        //end of class iterator

        iterator begin() {
            return iterator{&(r1.a), &(r2.a)};
        }
        iterator end() {
            return iterator{&(r1.b),&(r2.b)};
        }


    };

}


#endif //CPP_PROJECT5_CHAIN_HPP

