
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
        const T a;
        const Z b;

        itChain(const T& a , const Z& b)
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


            iterator(const T& a,const  Z& b)
                    :a_startPointer (a.begin()),
                     a_endPointer(a.end()),
                     b_startPointer (b.begin()),
                     b_endPointer(b.end())
            {}

            iterator(const T& a, const Z& b,int i)
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
                    ++a_startPointer;
                else if (b_startPointer != b_endPointer)
                    ++b_startPointer;

                return *this;
            }


            bool operator==(const iterator &it) const {
                return (a_startPointer == it.a_startPointer || b_startPointer == it.b_startPointer);
            }

            bool operator!=(const iterator& it) const {
                return (a_startPointer != it.a_startPointer || b_startPointer != it.b_startPointer);
            }

        };

        //end of class iterator

        iterator begin() const {
            return iterator{ a,b };
        }
        iterator end() const {
            return iterator{ a,b , 1};
        }


        int  length() const {
            auto itStartA = a.begin();
            auto itEndA = a.end();
            auto itStartB = b.begin();
            auto itEndB = b.end();
            int counter = 0;

            while(itStartA != itEndA){
                counter++;
                itStartA++;
            }
            while(itStartB != itEndB){
                counter++;
                itStartB++;
            }
            return counter;

        }


    };

    template<typename T, typename Z>
    itChain<T, Z> chain(T a, Z b) {
        return itChain<T,Z>(a, b);
    }

}


#endif //CPP_PROJECT5_CHAIN_HPP

