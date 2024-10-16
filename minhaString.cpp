//definiçâo da classe
#include "minhaString.hpp"
#include <cstring>
#include <iostream>
#include <cctype>
#include <cstdlib>

using namespace std;

MinhaString::MinhaString(){ 
    string = new char[1];
    const char* aux = "\0";
    strcpy(string,aux);
}

MinhaString::MinhaString(const char* other){ 
    string = new char[strlen(other) + 1];
    strcpy(string, other);
}

MinhaString::~MinhaString(){
    delete[] string;
}

const char* MinhaString::retornaString()const{
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
        if(string[i] >= 'A' &&  string[i] <= 'Z'){
            string[i] += 32;
        }
    }
}

void MinhaString::title(){
    if (string[0] >= 'a' && string[0] <= 'z'){
        string[0] -= 32;
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
            if(string[i] >= 'a' &&  string[i] <= 'z'){
                string[i] -= 32;
            }
            eh_espaco = false;
            continue;
        }

        if(string[i] >= 'A' &&  string[i] <= 'Z'){
            string[i] += 32;
        }
    }
}

void MinhaString::to_snake_case() {
    int cont = 0;
    for (int i = 0; i < strlen(string); i++) { 
        if (isupper(string[i])) { 
            cont++;
        }
    }

    char* nova_str = new char[strlen(string) + cont + 1];
    char* ini = nova_str;

    for (int i = 0; i < strlen(string); i++) {
        if (!isalpha(string[i])) {
            *nova_str++ = string[i]; 
            continue;
        }

        if (isupper(string[i])) { 
            if (i > 0) { 
                *nova_str++ = '_';
            }
            *nova_str++ = tolower(string[i]); 
        } else {
            *nova_str++ = string[i]; 
        }
    }
    *nova_str = '\0'; 

    delete[] string; 
    string = ini; 
}

void MinhaString::to_camelCase(){
    int cont = 0;
    for (int i = 0; i < strlen(string); i++)
    {
        if (string[i] == '_')
        {
            cont++;
        }
        
    }

    char* nova_str = new char[strlen(string) - cont + 1];
    char* ini = nova_str;

    for (int i = 0; i < strlen(string); i++)
    {
        if(string[i] == '_')
        {
            *nova_str = toupper(string[i + 1]);
            nova_str++;
            i++;
            continue;
        }

        *nova_str = string[i];
        nova_str++;

    }
    *nova_str = '\0';
    delete[] string;
    string = ini;
}

bool MinhaString::verifica_num() const {
    int cont = 0;
    for (int i = 0; i < strlen(string); i++) {
        if (!isdigit(string[i]) && string[i] != '.') {
            return false;
        }

        if (string[i] == '.') {
            cont++;
        }
    }
    return (cont <= 1);
}


int MinhaString::str_to_int()const{
    int num = 0;
    if (this->verifica_num()){
        num = atoi(string);
        return num;
    }
    return 0;

}

float MinhaString::str_to_float() const{
    float num = 0;
    if (verifica_num()){
        num = atof(string);
        return num;
    }
    return 0;

}

