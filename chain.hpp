
//
// Created by Dvir on 05/05/2019.
//

#ifndef CPP_PROJECT5_CHAIN_HPP
#define CPP_PROJECT5_CHAIN_HPP

#include "range.hpp"

namespace itertools {
    template <typename T, typename Z>
    class itChain {

    public:
        T a ;
        Z b;
        itChain(T a , Z b)
                :a(a),b(b){}
        itChain()
        {}

        // begin of class iterator

        class iterator {

        public:

            decltype(a.begin()) a_startPointer;
            decltype(a.end()) a_endPointer;
            decltype(b.begin()) b_startPointer;
            decltype(b.end()) b_endPointer;


            iterator(T& a, Z& b)
                    :a_startPointer (a.begin()),
                     a_endPointer(a.end()),
                     b_startPointer (b.begin()),
                     b_endPointer(b.end())
            {}

            iterator(T& a, Z& b,bool F)
                    :a_startPointer(a.end()),
                     a_endPointer(a.end()),
                     b_startPointer(b.end()),
                     b_endPointer(b.end())
            {}

            iterator()
            {}

            auto operator*() const {
                if (a_startPointer != a_endPointer)
                    return *a_startPointer;

                else return *b_startPointer;

            }

            iterator& operator++() {
                if (a_startPointer != a_endPointer)
                    a_startPointer++;
                else
                    b_startPointer++;

                return *this;
            }

            const iterator operator++(int) {
                iterator tmp;
                if (a_startPointer != a_endPointer){
                    tmp = a_startPointer;
                    a_startPointer++;
                    return tmp;
                }
                else {
                    tmp = b_startPointer;
                    b_startPointer++;
                    return tmp;
                }

            }

            bool operator==(const iterator &it) const {
                return (a_startPointer == it.a_startPointer || b_startPointer == it.b_startPointer);
            }

            bool operator!=(const iterator& it) const {
                return (a_startPointer != it.a_startPointer || b_startPointer != it.b_startPointer);
            }

        };

        //end of class iterator

        iterator begin() {
            return iterator{ a,b };
        }
        iterator end() {
            return iterator{ a,b , false};

        }


    };

    template<typename T, typename Z>
    itChain<T, Z> chain(T a, Z b) {
        return itChain<T,Z>(a, b);
    }

}


#endif //CPP_PROJECT5_CHAIN_HPP

