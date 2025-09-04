#ifndef THREE_NUMBERS_H
#define THREE_NUMBERS_H

/**
 * @class ThreeNumbers
 * @brief Representa tres números enteros y permite determinar el mayor.
 *
 * Esta clase almacena tres enteros y proporciona un método para encontrar
 * el mayor de ellos.
 */
class ThreeNumbers {
private:
    int number1;
    int number2;
    int number3;

public:
    /**
     * @brief Constructor que inicializa los tres números.
     * @param num1 Primer número.
     * @param num2 Segundo número.
     * @param num3 Tercer número.
     */
    ThreeNumbers(int num1, int num2, int num3);

    /**
     * @brief Devuelve el mayor de los tres números.
     * @return El número más grande.
     */
    int findLargest() const;
};

#endif 
