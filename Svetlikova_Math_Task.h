#ifndef SVETLIKOVA_MATHTASK_H
#define SVETLIKOVA_MATHTASK_H
#include <iostream>
#include <map>
#include <string>
#include <functional>
#include <cmath>

using namespace std;


bool user_input(string input){
    if (input.empty())return false;
    try{
        double number=stod(input);
        
    }
    catch(...)
    {return false;}
    return true;

}
//branch_func_0
function<void()>enter_choice(int&var_link,string label){
    return[&var_link,label](){
        string raw_input;
        cout<<label<<" = ";
        getline(cin,raw_input);
        while (!user_input(raw_input))
        {
            cout<<label<<" = ";
            getline(cin,raw_input);

        }
        var_link=stoi(raw_input);
    };

}
//branch_func_1
function<void()>enter_number(double&var_link,string label){
    return[&var_link,label](){
        string raw_input;
        cout<<label<<": ";
        getline(cin,raw_input);
        while (!user_input(raw_input))
        {
            cout<<label<<": ";
            getline(cin,raw_input);

        }
        var_link=stod(raw_input);
    };

}

double modul(double a,double b){
    
    //cout<<"комплексная часть числа а= "<<a<<"  комплексная часть числа b= "<<b<<endl;
    //branch_fun_2
    return pow((a*a+b*b),0.5);

}

double argument(double a,double b){
    //branch_fun_3
    //cout<<"комплексная часть числа а= "<<a<<"  комплексная часть числа b= "<<b<<endl;    
    if (a>0){
        return atan2(b,a);
    }
    if (a<0 && b>0){
        return atan2(b,a)+acos(-1.0);
    }if(a<0 && b<0){ 
        return atan2(b,a)-acos(-1.0);
    }if(a==0&&b>0){
        return acos(-1.0)/2;
    }
    if(a==0&&b<0){
        return - acos(-1.0)/2;
    }if (a==0 && b==0){
        return 0;
    }

}




#endif