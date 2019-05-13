/*
//
// Created by Dvir on 05/05/2019.
//

#ifndef CPP_PROJECT5_POWERSET_HPP
#define CPP_PROJECT5_POWERSET_HPP

#include "set"


namespace itertools {
    template <typename T, typename Z>
    class itPowerSet {

    public:
        T a ;

        itPowerSet(T a )
                :a(a){}
        itPowerSet()
        {}

        // begin of class iterator

        class iterator {

        public:

            decltype(a.begin()) a_startPointer;
            decltype(a.end()) a_endPointer;
            decltype(a.begin()) saveFirst;


            iterator(T& a)
                    :a_startPointer (a.begin()),
                     a_endPointer(a.end())

            {}

            iterator(T& a, Z& b,bool F)
                    :a_startPointer(a.end()),
                     a_endPointer(a.end())



            {}

            iterator()
            {}

            auto operator*() const {

                return std :: make_pair(*a_startPointer, *b_startPointer);

            }

            iterator& operator++() {
                if (a_startPointer != a_endPointer){
                    b_startPointer++;

                }

                if (b_startPointer == b_endPointer){
                    b_startPointer = saveFirst;
                    a_startPointer++;
                }

                return *this;
            }


            const iterator operator++(int) {
                iterator tmp;
                tmp = make_pair(a_startPointer,b_startPointer);
                if (a_startPointer != a_endPointer){
                    b_startPointer++;

                }

                if (b_startPointer == b_endPointer){
                    b_startPointer = saveFirst;
                    a_startPointer++;
                }
                return tmp;

            }

            bool operator==(const iterator &it) const {
                return (a_startPointer == it.a_startPointer && b_startPointer == it.b_startPointer);
            }

            bool operator!=(const iterator& it) const {
                return (a_startPointer != it.a_startPointer && b_startPointer != it.b_startPointer);
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
    itPowerSet<T, Z> powerset(T a, Z b) {
        return itPowerSet<T,Z>(a, b);
    }


    template<typename T>
    std :: ostream& operator<<(std :: ostream &os, const std :: set<T>& subset) {
        os << "{";
        for (auto i : subset) {
            os << i << ",";
        }
        os << "]";
        return os;

    }
};


#endif //CPP_PROJECT5_POWERSET_HPP
*/
