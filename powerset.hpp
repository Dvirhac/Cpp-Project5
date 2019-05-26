

//
// Created by Dvir on 05/05/2019.
//

#ifndef CPP_PROJECT5_POWERSET_HPP
#define CPP_PROJECT5_POWERSET_HPP

#include "set"
#include "iostream"
#include "product.hpp"
#include <math.h>



namespace itertools {
    template<typename T>
    class itPowerSet {

    public:

        const T a;
        int numOfSubsets;


        itPowerSet(const T& a)
                : a(a) {
            numOfSubsets = pow(2, a.length());
        }

        itPowerSet() {}

        // begin of class iterator

        class iterator {

        public:

            decltype(a.begin()) a_startPointer;
            decltype(a.begin()) a_saveStart;
            int finish;
            int length;
            int begin;
            string subset;


            iterator(const T& a,int num) :
                    a_startPointer(a.begin()),
                    a_saveStart(a.begin()),
                    length(a.length())

            {
                begin = num;
                finish = pow(2,a.length());
            }


            iterator() {}

            auto operator*() {
                string subSet = "";
                if(begin != finish) {
                    subSet += "{";
                    for (int i = 0; i < length; ++i) {
                        if ((begin & (1 << i))) {
                            if (*a_startPointer <= 'z' && *a_startPointer >= 'a') {
                                subSet += *a_startPointer;

                            } else {
                                subSet += to_string(*a_startPointer);
                            }
                            subSet += ",";
                        }
                        ++a_startPointer;
                    }

                    if (subset.back() == ',') subSet = subSet.substr(0, subSet.size() - 1);
                    subSet += '}';
                }

                return subset;
            }

            iterator& operator++() {
                begin++;
                a_startPointer = a_saveStart;
                return *this;
            }

            bool operator==(const iterator &it) const {
                return (a_startPointer == it.a_startPointer);

            }

            bool operator!=(const iterator &it) const {
                return (begin == it.begin);
            }

        };


        //end of class iterator

        iterator begin() const{
            return iterator(a,0);
        }
        iterator end() const {
            return iterator(a, numOfSubsets);

        }
    };

    template<typename T>
    itPowerSet<T> powerSet( T a) {
        return itPowerSet<T>(a);
    }

};


#endif //CPP_PROJECT5_POWERSET_HPP
