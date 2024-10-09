//declaraçâo da classe
#pragma once

class MinhaString
{
private:
    char* string;
public:
    MinhaString(/* args */);
    MinhaString(const char*);
    ~MinhaString();

    void concatenacao(MinhaString&);
    void concatenacao(const char*);

    void upper();
    void lower();
    void title();
    void snake_case();
    void camelCase();

    int str_to_int();
    float str_to_float();

    const char* retornaString();
};

