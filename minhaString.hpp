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

    bool verifica_num() const;
    int str_to_int() const;
    float str_to_float() const;

    const char* retornaString() const;
};

