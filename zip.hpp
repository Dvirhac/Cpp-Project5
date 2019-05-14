//
// Created by YuvalAmar on 5/13/2019.
//

#ifndef CPP_PROJECT5_ZIP_HPP
#define CPP_PROJECT5_ZIP_HPP
#include <iosfwd>
#include <iostream>
#include "utility"
#include "ostream"
namespace itertools {
    template <typename T, typename Z>
    class itZip {

    public:
        T a ;
        Z b;

        itZip(T a , Z b)
                :a(a),b(b){}
        itZip()
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
            iterator(const T& a,const  Z& b)
                    :a_startPointer (a.begin()),
                     a_endPointer(a.end()),
                     b_startPointer (b.begin()),
                     b_endPointer(b.end())


            {}

            iterator(const T& a,const  Z& b,bool F)
                    :a_startPointer(a.end()),
                     a_endPointer(a.end()),
                     b_startPointer(b.end()),
                     b_endPointer(b.end())
            {}

            iterator()
            {}

            auto operator*() const {

                return std :: make_pair(*a_startPointer, *b_startPointer);

            }

            iterator& operator++() {
                    ++a_startPointer;
                    ++b_startPointer;


                return *this;
            }

            const iterator operator++(int) {
                iterator tmp;
                tmp = make_pair(a_startPointer,b_startPointer);
                a_startPointer++;
                b_startPointer++;
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
        const iterator begin() const {
            return iterator{a,b};
        }

        const iterator end() const{
            return iterator{a,b , false};
        }

        int  length(){
            return  a.length() + b.length();
        }


    };

    template<typename T, typename Z>
    itZip<T, Z> zip(T a, Z b) {
        return itZip<T,Z>(a, b);
    }


    template<typename T, typename Z>
    std :: ostream& operator<<(std :: ostream &os, const std :: pair<T, Z>& pair) {
        os <<  pair.first << "," << pair.second;
        return os;

    }

}
#endif //CPP_PROJECT5_ZIP_HPP
