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


//  ===========RANGE ==============

        range<int> intRange(3,7);
        range<int> intRange2(-4,3);
        auto intI1  = intRange.begin();
        auto intI2 = intRange.begin();

        testcase.setname("test range INT")

        .CHECK_OUTPUT (intRange.a, "3")
        .CHECK_OUTPUT (intRange.b, "7")
        .CHECK_OUTPUT (intRange2.a, "-4")
        .CHECK_OUTPUT (intRange2.b, "3")
        .CHECK_EQUAL (intI1 != intI2, false);

        intI1++;
        intI2++;

        testcase.setname("check iterators INT")
        .CHECK_EQUAL (intI1 == intI2, true);

        string result1 = "";
        string result2 = "";
        for(int i : intRange){
            result1 = result1 + to_string(i);
        }
        for(int i : intRange2){
            result2 = result2 + to_string(i);
        }
        testcase.setname("test range OUTPUT - INT ")
        .CHECK_EQUAL ( result1=="3456", true)
        .CHECK_EQUAL ( result2=="-4-3-2-1012", true)
        ;

        range<double> doubleRange(4.4,10.4);
        auto doubleI1  = doubleRange.begin();
        auto doubleI2 = doubleRange.begin();
        doubleI1++;
        doubleI1++;

        testcase.setname("test range DOUBLE")

        .CHECK_OUTPUT (doubleRange.a, "4.4")
        .CHECK_OUTPUT (doubleRange.b, "10.4");


        testcase.setname("check iterators DOUBLE")
        .CHECK_EQUAL (doubleI1 == doubleI1, true);

        string resultDouble = "";
        for(double i : doubleRange){
            resultDouble = resultDouble + to_string(i);
        }
        cout << resultDouble;
        testcase.setname("test range OUTPUT - DOUBLE")
        .CHECK_EQUAL (resultDouble == "4.45.46.47.48.49.4", true);



       testcase.setname("test range CHAR");

        char x = 'd';
        char y = 'h';
        range<char> charRange(x,y);
        auto charI1 = charRange.begin();
        auto charI2 = charRange.begin();
        charI2++;

        testcase.setname("test range CHAR")
        .CHECK_OUTPUT (charRange.a, "d")
        .CHECK_OUTPUT (charRange.b, "h")
        .CHECK_EQUAL (charI1 != charI2, true);

        testcase.setname("check iterators CHAR")
        .CHECK_EQUAL (charI1 == charI2, false);

        string resultChar = "";
        for(char i : charRange){
            resultChar = resultChar + i;
        }
        testcase.setname("test range OUTPUT - CHAR")
                .CHECK_EQUAL (resultChar == "defg", true);































        grade = testcase.grade();
    } else {
        testcase.print_signal(signal);
        grade = 0;
    }
    cout << "Your grade is: "  << grade << endl;
    return 0;
}