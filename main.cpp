//testes manuais
#include "minhaString.hpp"
#include <iostream>
using namespace std;

int main(){
    MinhaString string1;
    cout << string1.retornaString() << "\n";
    string1.concatenacao("ola mundo");
    cout << string1.retornaString() << "\n";
    string1.upper();
    cout << string1.retornaString() << "\n";
    string1.lower();
    cout << string1.retornaString() << "\n";
    string1.title();
    cout << string1.retornaString() << "\n";

    MinhaString string2("snake_case");
    cout << string2.retornaString() << "\n";
    string2.camelCase();
    cout << string2.retornaString() << "\n";
    string2.snake_case();
    cout << string2.retornaString() << "\n";

    MinhaString num_int("124");
    cout << num_int.verifica_num() << "\n";
    int num = num_int.str_to_int();

    MinhaString num_float("124.76");
    cout << num_float.verifica_num() << "\n";
    float num2 = num_float.str_to_float();


    return 0;
}