#include <iostream>
#include <C:\Users\Chris Gargoyle\Desktop\Svetlikova_LR5\Svetlikova_LR5_part1\Svetlikova_Math_Task.h>
double a;
double b;
using namespace std;



int main(){
    
    string str_input;
    cout<<"введите целую часть комсплексного числа - а "<<endl;
    getline(cin,str_input);

    while(!user_input(str_input)){
        cout<<"введите целую часть комсплексного числа - а "<<endl;
        getline(cin,str_input);
    }
    double a = stod(str_input);

    cout<<"введите мнимую часть комсплексного числа - b "<<endl;
    getline(cin,str_input);

    while(!user_input(str_input)){
        cout<<"введите мнимую часть комсплексного числа - b "<<endl;
        getline(cin,str_input);
    }
    double b = stod(str_input);
    
    double modul_of_complex = modul(a,b);
    cout<<"модуль комплексного числа: "<< modul_of_complex <<endl;

    double argument_of_complex = argument(a,b);
    cout<<"aргумент комплексного числа: "<<argument_of_complex<<endl;
    return 0;
}