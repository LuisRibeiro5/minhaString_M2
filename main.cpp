#include <iostream>
#include "minhaString.hpp"  // Incluindo a declaração da classe

int main() {
    // Teste do construtor vazio e retorno da string
    MinhaString str1;
    std::cout << "Teste 1 - Construtor vazio: " << str1.retornaString() << std::endl;

    // Teste do construtor com argumento
    MinhaString str2("Hello");
    std::cout << "Teste 2 - Construtor com string: " << str2.retornaString() << std::endl;

    // Teste de concatenação de duas strings
    MinhaString str3(" World");
    str2.concatenacao(str3);
    std::cout << "Teste 3 - Concatenação de duas strings: " << str2.retornaString() << std::endl;

    // Teste de concatenação de string literal
    str2.concatenacao("!!!");
    std::cout << "Teste 4 - Concatenação com string literal: " << str2.retornaString() << std::endl;

    // Teste de transformação para maiúsculas
    str2.upper();
    std::cout << "Teste 5 - Transformação para maiúsculas: " << str2.retornaString() << std::endl;

    // Teste de transformação para minúsculas
    str2.lower();
    std::cout << "Teste 6 - Transformação para minúsculas: " << str2.retornaString() << std::endl;

    // Teste de transformação para Title Case
    MinhaString str4("hello world");
    str4.title();
    std::cout << "Teste 7 - Transformação para Title Case: " << str4.retornaString() << std::endl;

    // Teste de transformação para snake_case
    MinhaString str5("helloWorld");
    str5.to_snake_case();
    std::cout << "Teste 8 - Transformação para snake_case: " << str5.retornaString() << std::endl;

    // Teste de transformação para camelCase
    MinhaString str6("hello_world_example");
    str6.to_camelCase();
    std::cout << "Teste 9 - Transformação para camelCase: " << str6.retornaString() << std::endl;

    // Teste de verificação se a string é um número
    MinhaString str7("12345");
    std::cout << "Teste 10 - Verificação se é um número (espera true): " << std::boolalpha << str7.verifica_num() << std::endl;

    MinhaString str8("Hello123");
    std::cout << "Teste 11 - Verificação se é um número (espera false): " << std::boolalpha << str8.verifica_num() << std::endl;

    // Teste de conversão de string para int
    MinhaString str9("12345");
    int valorInt = str9.str_to_int();
    std::cout << "Teste 12 - Conversão de string para int: " << valorInt << std::endl;

    // Teste de conversão de string para float
    MinhaString str10("123.45");
    float valorFloat = str10.str_to_float();
    std::cout << "Teste 13 - Conversão de string para float: " << valorFloat << std::endl;

    return 0;
}
