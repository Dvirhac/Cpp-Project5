

//
// Created by Dvir on 05/05/2019.
//

#ifndef CPP_PROJECT5_POWERSET_HPP
#define CPP_PROJECT5_POWERSET_HPP

#include "set"
#include <bits/stdc++.h>
#include "iostream"
#include <math.h>



namespace itertools {
    template<typename T>
    class itPowerSet {

    public:

        const T a;
        const int size = a.length();
        int count = pow(2, size);


        itPowerSet(const T& a)
                : a(a) {}

        itPowerSet() {}

        // begin of class iterator

        class iterator {

        public:

            decltype(a.begin()) a_startPointer;
            decltype(a.end()) a_endPointer;
            int size = 0;
            int length = 0;
            string subset;


            iterator(const T& a) :
                    a_startPointer(a.begin()),
                    a_endPointer(a.end()),
                    size(a.length()),
                    length(pow(2, size)),
                    subset("") {}

            iterator(const T& a, bool f) :
                    a_startPointer(a.end()),
                    a_endPointer(a.end()) {}


            iterator() {}

            auto operator*() const {

                return subset;
            }

            iterator& operator++() {

                for (int i = 0; i < length; i++) {
                    for (int i; i < length; i++) {
                        subset = "{ ";
                        for (int j; j < size; j++) {
                            if ((i & (1 << j)) != 0)
                                subset += *a_startPointer + ", ";
                        }
                    }


                    subset += " }";
                    ++a_startPointer;
                    return *this;
                }
            }




                /*  const iterator operator++(int) {

                      return "";


                  }*/

                bool operator==(const iterator &it) const {
                    return (a_startPointer == a_endPointer);

                }

                bool operator!=(const iterator &it) const {
                    return (a_startPointer != a_endPointer);
                }

        };


            //end of class iterator

            iterator begin() const{
                return iterator(a);
            }

            iterator end() const {
                return iterator(a, false);

            }

        };

        template<typename T>
        itPowerSet<T> powerset( T a) {
            return itPowerSet<T>(a);
        }


        template<typename T>
        std::ostream &operator<<(std::ostream &os, const set <T> &subset) {
            os << "{";
            for (auto i : subset) {
                os << i << ",";
            }
            os << "]";
            return os;

        }


    };




#endif //CPP_PROJECT5_POWERSET_HPP
































/*

//
// Created by Dvir on 05/05/2019.
//

#ifndef CPP_PROJECT5_POWERSET_HPP
#define CPP_PROJECT5_POWERSET_HPP

#include "set"
#include <bits/stdc++.h>
#include "iostream"

namespace itertools {
    template <typename T>
    class itPowerSet {

    public:

        T a ;
        int size = a.length();
        int count = pow(2,size);

        itPowerSet(T a )
                :a(a){}
        itPowerSet()
        {}

        // begin of class iterator

        class iterator {

        public:

            decltype(a.begin()) a_startPointer;
            decltype(a.end()) a_endPointer;
            string subset = " ";


            iterator(T& a)
                    :a_startPointer (a.begin()),
                     a_endPointer(a.end())

            {}


            iterator()
            {}

            auto operator*() const {

                return *this;
            }

            iterator& operator++() {

                a_startPointer++;
                return *this;
            }


            const iterator operator++(int) {
                iterator tmp;
                tmp = a_startPointer;
                a_startPointer++;
                return tmp;


            }

            bool operator==(const iterator &it) const {
                return (a_startPointer == it.a_startPointer && a_endPointer == a_endPointer);
            }

            bool operator!=(const iterator& it) const {
                return (a_startPointer != it.a_startPointer && a_endPointer != a_endPointer);
            }

        };

        //end of class iterator

        iterator begin() const{
            return iterator{ a};
        }
        iterator end() const{
            return iterator{a};

        }
        std::set<T> buildSet(){
            std::set<T> set1;
            int size = a.length();
            int count = pow(2,size);
            for (auto i = a.begin(); i < count; i++)
            {

                for (auto j = a.begin(); j < size; j++)
                {
                    if ((i & (1 << j)) > 0)
                       set1.insert(i);
                }

            }
            return set1;
        }


    };

    template<typename T>
    itPowerSet<T> powerset(T a) {
        return itPowerSet<T>(a);
    }


*//*

*/
/*    template<typename T>
    std:: ostream& operator<<(std :: ostream &os, const set<T>& subset) {
        os << "{";
        for (auto i : subset) {
            os << i << ",";
        }
        os << "]";
        return os;

    }*//*
*/
/*

};


#endif //CPP_PROJECT5_POWERSET_HPP

*/

