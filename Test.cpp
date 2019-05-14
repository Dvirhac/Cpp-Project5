#include <iostream>

#include "range.hpp"
#include "chain.hpp"
#include "zip.hpp"
#include "product.hpp"
#include "powerset.hpp"
#include "badkan.hpp"
#include "iostream"

using namespace std;
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
    int grade = 0;
    int signal = setjmp(badkan::longjmp_buffer);
    if (signal == 0) {


        //              ===========RANGE ==============

        itRange<int> intRange(3, 7);
        itRange<int> intRange2(-1,3);
        auto it1 = intRange.begin();
        auto it2 = intRange.end();
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
        itZip<itRange<char>,string> zip3(charRange,"dvi");
        itZip<itZip<itRange<int>,string>,itZip<itRange<double>,string>> zipOfZip(zip1,zip2);

        //              ===========PROUDCT ==============
        itProduct<itRange<int>,string> proudct1(intRange,"yuval");
        itProduct<itRange<double>,string> proudct2(doubleRange,"Dvir");
        itProduct<string,string> proudct3("yuval","dvir");


        //              ===========POWERSET ==============
        /* itPowerSet<itRange<int>> powerSet1(intRange);
         itPowerSet<itRange<char>> powerSet2(charRange3);
        */



        testcase.setname("TEST RANGE")
                .CHECK_OUTPUT(iterable_to_string(intRange), "3,4,5,6,")
                .CHECK_OUTPUT(iterable_to_string(intRange2),"-1,0,1,2,")
                .CHECK_OUTPUT (iterable_to_string(doubleRange),"2.1,3.1,4.1,5.1,6.1,")
                .CHECK_OUTPUT (iterable_to_string(doubleRange2),"10.1,11.1,12.1,13.1,")
                .CHECK_OUTPUT (iterable_to_string(charRange),"a,b,c,")
                .CHECK_OUTPUT (iterable_to_string(charRange2),"f,g,")
                .CHECK_OUTPUT (iterable_to_string(charRange3),"d,e,f,")
                .CHECK_EQUAL (it1 != it2, true );

        testcase.setname("TEST CHAIN")
                .CHECK_OUTPUT (iterable_to_string(chain1),"3,4,5,6,-1,0,1,2,")
                .CHECK_OUTPUT (iterable_to_string(chain4),"a,b,c,y,u,v,a,l,d,v,i,r,")
                .CHECK_OUTPUT (iterable_to_string(chain5),"y,u,v,a,l,d,v,i,r,f,g,");

        testcase.setname("TEST ZIP")
                .CHECK_OUTPUT (iterable_to_string(zip1),"3,c,4,p,5,p,6,5,")
                .CHECK_OUTPUT (iterable_to_string(zip2),"2.1,y,3.1,u,4.1,v,5.1,a,6.1,l,")
                .CHECK_OUTPUT (iterable_to_string(zip3),"a,d,b,v,c,i,")
                .CHECK_OUTPUT (iterable_to_string(zipOfZip),"3,c,2.1,y,4,p,3.1,u,5,p,4.1,v,6,5,5.1,a,");

        testcase.setname("TEST PRODUCT")
                .CHECK_OUTPUT (iterable_to_string(proudct1),"3,y,3,u,3,v,3,a,3,l,4,y,4,u,4,v,4,a,4,l,5,y,5,u,5,v,5,a,5,l,6,y,6,u,6,v,6,a,6,l,")
                .CHECK_OUTPUT (iterable_to_string(proudct2),"2.1,D,2.1,v,2.1,i,2.1,r,3.1,D,3.1,v,3.1,i,3.1,r,4.1,D,4.1,v,4.1,i,4.1,r,5.1,D,5.1,v,5.1,i,5.1,r,6.1,D,6.1,v,6.1,i,6.1,r,")
                .CHECK_OUTPUT (iterable_to_string(proudct3),"y,d,y,v,y,i,y,r,u,d,u,v,u,i,u,r,v,d,v,v,v,i,v,r,a,d,a,v,a,i,a,r,l,d,l,v,l,i,l,r,");

        grade = testcase.grade();
    } else {
        testcase.print_signal(signal);
        grade = 0;
    }
    cout << "Your grade is: " << grade << endl;
    return 0;
}