//
// Created by Dvir on 05/05/2019.
//

#ifndef CPP_PROJECT5_PRODUCT_HPP
#define CPP_PROJECT5_PRODUCT_HPP

#include "utility"
#include "zip.hpp"
#include "ostream"

namespace itertools {
    template <typename T, typename Z>
    class itProduct {

    public:
        const T a ;
        const Z b;
        itProduct(T a , Z b)
                :a(a),b(b){}
        itProduct()
        {}

        // begin of class iterator

        class iterator {

        public:

            decltype(a.begin()) a_startPointer;
            decltype(a.end()) a_endPointer;
            decltype(b.begin()) b_startPointer;
            decltype(b.end()) b_endPointer;
            decltype(b.begin()) saveFirst;


            iterator(const T& a,const  Z& b)
                    :a_startPointer (a.begin()),
                     saveFirst(b.begin()),
                     a_endPointer(a.end()),
                     b_startPointer (b.begin()),
                     b_endPointer(b.end())
            {}

            iterator(const T& a,const  Z& b,int i)
                    :saveFirst(b.begin()),
                     a_startPointer(a.end()),
                     a_endPointer(a.end()),
                     b_startPointer(b.end()),
                     b_endPointer(b.end())


            {}

            /* iterator()
             {}*/

            auto operator*() const {

                return std :: make_pair(*a_startPointer, *b_startPointer);

            }

            iterator& operator++() {
                ++b_startPointer;

                if (b_startPointer == b_endPointer){
                    b_startPointer = saveFirst;
                    ++a_startPointer;
                }

                return *this;
            }


            bool operator==(const iterator &it) const {
                return (a_startPointer == it.a_startPointer && b_startPointer == it.b_startPointer);
            }

            bool operator!=(const iterator& it) const {
                return (a_startPointer != it.a_startPointer && b_startPointer != it.b_startPointer);
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
            return  a.length() + b.length();
        }


    };

    template<typename T, typename Z>
    itProduct<T, Z> product(T a, Z b) {
        return itProduct<T,Z>(a, b);
    }



}

#endif //CPP_PROJECT5_PRODUCT_HPP
