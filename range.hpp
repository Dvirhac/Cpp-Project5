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
    template <typename T>

    class range : public std::iterator<std::output_iterator_tag, T>
    {
    private:
        T arr[2];
    public:
        range(T a, T b)
        {
            arr[0] = a;
            arr[1] = b;
        }

        T operator*() const{
            return *this;
        }

        range & operator++(){

        }
        range operator++(T) {

        }

        iterator begin();
        iterator end();
    };



    template <typename T>
    list<T> range(T a, T b)
    {

        /*list<T> listOfElements;
        auto it  = listOfElements.begin();
        for (auto i = a; i < b; i++)
        {
            listOfElements.insert(it,i);
            it++;
        }

        return listOfElements;
         */
    }



}



#endif //CPP_PROJECT5_RANGE_HPP
