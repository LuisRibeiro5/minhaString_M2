//definiçâo da classe
#include "minhaString.hpp"
#include <cstring>
#include <cctype>

using namespace std;

MinhaString::MinhaString(){ 
    string = new char[1];
}

MinhaString::MinhaString(const char* other){ 
    char* string = new char[strlen(other) + 1];
    strcpy(string,other);
}

MinhaString::~MinhaString(){
    delete[] string;
}

const char* MinhaString::retornaString(){
    return this->string;
}

void MinhaString::concatenacao(MinhaString& other){
    const char* str_other = other.retornaString();
    char* nova_string = new char[strlen(str_other) + strlen(string) + 1];
    strcpy(nova_string, string);
    strcat(nova_string, str_other);

    delete[] string;
    string = nova_string;
}

void MinhaString::concatenacao(const char* other){
    char* nova_string = new char[strlen(other) + strlen(string) + 1];
    strcpy(nova_string, string);
    strcat(nova_string, other);

    delete[] string;
    string = nova_string;
}

void MinhaString::upper(){
    for (int i = 0; i <= strlen(string); i++)
    {
        if(string[i] >= 'a' &&  string[i] <= 'z'){
            string[i] -= 32;
        }
    }
}

void MinhaString::lower(){
    for (int i = 0; i <= strlen(string); i++)
    {
        if(string[i] >= 'a' &&  string[i] <= 'z'){
            string[i] + 32;
        }
    }
}

void MinhaString::title(){
    if (string[0] >= 'a' && string[0] <= 'z'){
        string[0] - 32;
    }

    bool eh_espaco = false;
    for (int i = 1; i <= strlen(string); i++)
    {
        if(string[i] == ' '){
            eh_espaco = true;
            continue;
        }

        if (!isalpha(string[i])){
            continue;
        }

        if(eh_espaco){
            string[i] - 32;
            continue;
        }

        string[i] + 32;
    }
}

void MinhaString::snake_case(){
    int cont = 0;
    for (int i = 0; i <= strlen(string); i++)
    {
        if (string[i] == string[i] - 32)
        {
            cont++;
        }
        
    }

    char* nova_str = new char[strlen(string) + cont + 1];
    char* ini = nova_str;

    for (int i = 1; i <= strlen(string); i++)
    {
        if(!isalpha(string[i]))
        {
            *nova_str++ = string[i];
            continue;
        }

        if(string[i] == string[i] - 32){
            *nova_str++ = '_';
            *nova_str = string[i] + 32; 
        }else{
            *nova_str = string[i] + 32;
        }

        nova_str++;
    }
    *nova_str = '\0';

    delete[] string;
    string = ini;
}

void MinhaString::camelCase(){
    int cont = 0;
    for (int i = 0; i <= strlen(string); i++)
    {
        if (string[i] == '_')
        {
            cont++;
        }
        
    }

    char* nova_str = new char[strlen(string) - cont + 1];
    char* ini = nova_str;

    for (int i = 0; i <= strlen(string); i++)
    {
        if(string[i] == '_')
        {
            *nova_str = string[i + 1] + 32;
            nova_str++;
            i++;
            continue;
        }

        *nova_str = string[i];
        nova_str++;

    }

    delete[] string;
    string = ini;
}


