
using namespace std;
#include <iostream>
#include "chain.hpp"
#include "powerset.hpp"
#include "product.hpp"
#include "range.hpp"
#include "zip.hpp"
#include "badkan.h"
#include "string"

#define COMMA ,

using namespace itertools;


template<typename Iterable>
string iterable_to_string( Iterable& iterable) {
    ostringstream ostr;
    for (decltype(*iterable.begin()) i: iterable)
        ostr << i << ",";
    return ostr.str();
}

int main() {

    badkan::TestCase testcase;
    int grade=0;
    int signal = setjmp(badkan::longjmp_buffer);
    if (signal == 0) {


//              ===========RANGE ==============

        itRange<int> intRange(3,7);
        itRange<int> intRange2(-1,3);
       /* auto it1 = intRange.begin();
        auto it2 = intRange.end();
*/


        itRange<double> doubleRange(2.1,7.1);
        itRange<double> doubleRange2(10.1,14.1);
        itRange<char> charRange('a','d');
        itRange<char> charRange2('f','h');
        itRange<char> charRange3('d','g');



        //              ===========chain ==============
        itChain<itRange<int>,itRange<int>> chain1(intRange,intRange2);
        itChain<itRange<char>,string> chain4(charRange,"yuvaldvir");
        itChain<string,itRange<char>> chain5("yuvaldvir",charRange2);
        //              ===========ZIP ==============
        itZip<itRange<int>,string> zip1(intRange,"cpp5");
        itZip<itRange<double>,string> zip2(doubleRange,"yuval");
        itZip<itRange<char>,string> zip3(charRange,"dvir1");
        itZip<itZip<itRange<int>,string>,itZip<itRange<double>,string>> zipOfZip(zip1,zip2);
        //              ===========PROUDCT ==============
        itProduct<itRange<int>,string> proudct1(intRange,"yuval");
        itProduct<itRange<double>,string> proudct2(doubleRange,"Dvir");
        itProduct<string,string> proudct3("yuval","dvir");
        //              ===========POWERSET ==============
       /* itPowerSet<itRange<int>> powerSet1(intRange);
        itPowerSet<itRange<char>> powerSet2(charRange3);*/



        cout << iterable_to_string(zip2)<<endl;

        testcase.setname("TEST RANGE")

                .CHECK_EQUAL (iterable_to_string(intRange).compare("3,4,5,6, "), true)
                .CHECK_EQUAL (iterable_to_string(intRange2).compare("-4,-3,-2,-1,0,1,2 "), true)
                .CHECK_EQUAL (iterable_to_string(doubleRange).compare("2.1,3.1,4.1,5.1,6.1, "),true )
                .CHECK_EQUAL (iterable_to_string(doubleRange2).compare("10.1,11.1,12.1,13.1, "),true )
                .CHECK_EQUAL (iterable_to_string(charRange).compare("a,b,c, "),true )
                .CHECK_EQUAL (iterable_to_string(charRange2).compare("f,g, "), true)
                .CHECK_EQUAL (iterable_to_string(charRange3).compare("d,e,f, "),true )
                //.CHECK_EQUAL (it1 != it2, true )

                ;
        testcase.setname("TEST CHAIN")

                .CHECK_EQUAL (iterable_to_string(chain1).compare("3,4,5,6,-4,-3,-2,-1,0,1,2"), true)
                .CHECK_EQUAL (iterable_to_string(chain4).compare("a,b,c,y,u,v,a,l,d,v,i,r,"), true)
                .CHECK_EQUAL (iterable_to_string(chain5).compare("y,u,v,a,l,d,v,i,r,f,g"),true )

                ;
        testcase.setname("TEST PRODUCT")

                .CHECK_EQUAL (iterable_to_string(proudct1).compare("3f,3g,4f,4g,5f,5g,6f,6g,"), true)
                .CHECK_EQUAL (iterable_to_string(proudct2).compare("2.1,D,2.1,v,2.1,i,2.1,r,3.1,D,3.1,v,3.1,i,3.1,r,4.1,D,4.1,v,4.1,i,4.1,r,5.1,D,5.1,v,5.1,i,5.1,r,6.1,D,6.1,v,6.1,i,6.1,r, "), true)
                .CHECK_EQUAL (iterable_to_string(proudct3).compare("2.1,3.1,4.1,5.1,6.1,3,4,5,6,"),true )


                ;
        testcase.setname("TEST ZIP")

                .CHECK_EQUAL (iterable_to_string(zip1).compare("3,c,4,p,5,p,6,5, "), true)
                .CHECK_EQUAL (iterable_to_string(zip2).compare("2.1,y,3.1,u,4.1,v,5.1,a,6.1,l, "), true)
                .CHECK_EQUAL (iterable_to_string(proudct3).compare("2.1,3.1,4.1,5.1,6.1,3,4,5,6,"),true )


                ;


























        grade = testcase.grade();
    } else {
        testcase.print_signal(signal);
        grade = 0;
    }
    cout << "Your grade is: "  << grade << endl;
    return 0;
}