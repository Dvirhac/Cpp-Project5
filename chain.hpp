//
// Created by Dvir on 05/05/2019.
//

#ifndef CPP_PROJECT5_CHAIN_HPP
#define CPP_PROJECT5_CHAIN_HPP

#include "range.hpp"
namespace itertools {
    template <typename range>
    class chain {
        typedef range* pointer;
    private:
        range r1;
        range r2;
    public:

        chain(range r1 , range r2)
                :r1(r1),r2(r2){}

        // begin of class iterator

        class iterator {
        private:
            pointer ptr;
        public:
            iterator(pointer ptr = nullptr)
                    : ptr(ptr) {}

            range& operator*() const {
                return
            }

            iterator& operator++() {
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

            bool operator!=(const iterator& it) const {
                return ptr != it.ptr;
            }

        };

        //end of class iterator

        iterator begin() {
            return iterator{&r1};
        }
        iterator end() {
            return iterator{&r2};
        }


    };

}


#endif //CPP_PROJECT5_CHAIN_HPP
