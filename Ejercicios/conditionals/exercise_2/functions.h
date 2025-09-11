#ifndef FUNCTIONS_H
#define FUNCTIONS_H

class Functions {
public:
    Functions(int minAge = 18, int maxAge = 120);

    // Devuelve un mensaje sobre la edad
    const char* esAdult(int age) const;

private:
    int minAge_;
    int maxAge_;
};

#endif // FUNCTIONS_H
