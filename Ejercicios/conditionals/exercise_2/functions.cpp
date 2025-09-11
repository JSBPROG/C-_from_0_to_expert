#include "functions.h"

Functions::Functions(int minAge, int maxAge)
    : minAge_(minAge), maxAge_(maxAge) { }

const char* Functions::esAdult(int age) const {
    if (age < 0 || age > maxAge_) {
        return "Error: edad inválida";
    }
    return (age >= minAge_) ? "Es mayor de edad" : "Menor de edad";
}
