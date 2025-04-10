#include "CUTE/cute/cute.h"
#include "CUTE/cute/ide_listener.h"
#include "CUTE/cute/cute_runner.h"
#include "Svetlikova_Math_Task.h"

using namespace cute;

void test_modul(){
    double a=3.0;
    double b=5.0;
    double expected= pow(34.0,0.5);
    double actual=modul(a,b);
    ASSERT_EQUAL(expected,actual);

}
// тест на отсев пустых значений
void test_user_input_empty(){
    string str="";
    bool expected=false;
    bool actual=user_input(str);
    ASSERT_EQUAL(expected,actual);
}
// тест на отсев буквенных значений
void test_user_input_letter(){
    string str="b";
    bool expected=false;
    bool actual=user_input(str);
    ASSERT_EQUAL(expected,actual);
}
// тест на отсев буквенно-числовых значений
void test_user_input_digit_letter(){
    string str="5g";
    bool expected=false;
    bool actual=user_input(str);
    ASSERT_EQUAL(expected,actual);
}
// тест на отсев отрицательных значений
void test_user_input_negative_value(){
    string str="-18";
    bool expected=false;
    bool actual=user_input(str);
    ASSERT_EQUAL(expected,actual);
}



int main(){
    suite s;
    s.push_back(CUTE(test_modul));
    s.push_back(CUTE(test_user_input_empty));
    s.push_back(CUTE(test_user_input_letter));
    s.push_back(CUTE(test_user_input_digit_letter));
    s.push_back(CUTE(test_user_input_negative_value));
    ide_listener<> listener;
    makeRunner(listener)(s,"Test modul of complex number");
    return 0;
}