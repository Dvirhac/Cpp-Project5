#include <iostream>
using namespace std;

#include "chain.hpp"
#include "powerset.hpp"
#include "product.hpp"
#include "range.hpp"
#include "zip.hpp"
#include "badkan.h"

#define COMMA ,

using namespace itertools;

int main() {

    badkan::TestCase testcase;
    int grade=0;
    int signal = setjmp(badkan::longjmp_buffer);
    if (signal == 0) {


//              ===========RANGE ==============

        itRange intRange(3,7);
        itRange intRange2(-4,3);
        auto intI1  = intRange.begin();
        auto intI2 = intRange.begin();
        string result1 = "";
        string result2 = "";
        for(int i : intRange){
            result1 = result1 + to_string(i);
        }
        for(int i : intRange2){
            result2 = result2 + to_string(i);
        }
        itRange doubleRange(4.4,10.4);
        auto doubleI1  = doubleRange.begin();
        auto doubleI2 = doubleRange.begin();
        doubleI1++;
        doubleI1++;
        char x = 'd';
        char y = 'h';
        itRange charRange(x,y);
        auto charI1 = charRange.begin();
        auto charI2 = charRange.begin();
        charI2++;
        string resultChar = "";
        for(char i : charRange){
            resultChar = resultChar + i;
        }
        string resultDouble = "";
        for(double i : doubleRange){

            resultDouble = resultDouble + to_string(i);
        }
        cout<<resultDouble<<endl;

        testcase.setname("test RANGE")
                .CHECK_OUTPUT (intRange.a, "3")
                .CHECK_OUTPUT (intRange.b, "7")
                .CHECK_OUTPUT (intRange2.a, "-4")
                .CHECK_OUTPUT (intRange2.b, "3")
                .CHECK_EQUAL (intI1 != intI2, false)
                .CHECK_EQUAL ( result1=="3456", true)
                .CHECK_EQUAL ( result2=="-4-3-2-1012", true)
                .CHECK_OUTPUT (doubleRange.a, "4.4")
                .CHECK_OUTPUT (doubleRange.b, "10.4")
                .CHECK_EQUAL (doubleI1 == doubleI1, true)
                .CHECK_EQUAL (resultDouble == "4.45.46.47.48.49.4", true)
                .CHECK_OUTPUT (charRange.a, "d")
                .CHECK_OUTPUT (charRange.b, "h")
                .CHECK_EQUAL (charI1 != charI2, true)
                .CHECK_EQUAL (charI1 == charI2, false)
                .CHECK_EQUAL (resultChar == "defg", true)

                ;

/*//              ===========CHAIN ==============

        itChain c1 (itRange(1,9),"yuval")
        string resultC1 = "";
        for(auto i : c1){resultC1 = resultC1 + to_string(i);}//"12345678yuval"


        itChain c2 (itRange(-3,7),itRange(9,12))
        string resultC2 = "";
        for(auto i : c2){resultC2 = resultC2 + to_string(i);}//"-3-2-1012345691011"

        itChain c3(itRange(a,f),itRange(1.1,5.1))
        string resultC3 = "";
        for(auto i : c3){resultC3 = resultC3 + to_string(i);}//"abcde1.12.13.14.1"


        testcase.setname("test RANGE")
              //  .CHECK_OUTPUT (c1.a, "1")
               // .CHECK_OUTPUT (c1.b, "y")
                .CHECK_EQUAL (resultC1, "12345678yuval")
                .CHECK_EQUAL (resultC2, "-3-2-1012345691011")
                .CHECK_EQUAL (resultC3 , "abcde1.12.13.14.1")


        ;*/

























        grade = testcase.grade();
    } else {
        testcase.print_signal(signal);
        grade = 0;
    }
    cout << "Your grade is: "  << grade << endl;
    return 0;
}