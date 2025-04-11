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
// для каждого случая аргумента прописать отдельные переменные и прогнать тест
void test_argument(){
    // a и b >0
    double a=5.0;
    double b=1.0;
    double expected= atan2(b,a);
    double actual=argument(a,b);
    ASSERT_EQUAL(expected,actual);

}
void test_argument1(){
    // a<0 b>0
    double c=-5.0;
    double d=1.0;
    double expected= atan2(d,c)+acos(-1.0);
    double actual=argument(c,d);
    ASSERT_EQUAL(expected,actual);
}
void test_argument2(){
    // a<0 b<0
    double e=-5.0;
    double f=-1.0;
    double expected= atan2(f,e)-acos(-1.0);
    double actual=argument(e,f);
    ASSERT_EQUAL(expected,actual);
}
void test_argument3(){
    // a=0 b>0
    double g=0.0;
    double h=1.0;
    double expected= acos(-1.0)/2;
    double actual=argument(g,h);
    ASSERT_EQUAL(expected,actual);
}
void test_argument4(){
    // a=0 b<0
    double i=0.0;
    double j=-1.0;
    double expected= -acos(-1.0)/2;
    double actual=argument(i,j);
    ASSERT_EQUAL(expected,actual);
}
void test_argument5(){
    // a=0 b=0
    double r=0.0;
    double s=0.0;
    double expected= 0.0;
    double actual=argument(r,s);
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
    s.push_back(CUTE(test_argument));
    s.push_back(CUTE(test_argument1));
    s.push_back(CUTE(test_argument2));
    s.push_back(CUTE(test_argument3));
    s.push_back(CUTE(test_argument4));
    s.push_back(CUTE(test_argument5));
    ide_listener<> listener;
    makeRunner(listener)(s,"Test modul of complex number");
    return 0;
}