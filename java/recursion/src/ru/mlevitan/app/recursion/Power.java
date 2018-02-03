package ru.mlevitan.app.recursion;

public class Power {

    /**
     * Возведение числа в степень с помощью рекурсии.
     *
     * @param value
     * @param number
     * @return
     */
    public static double recPow(double value, double number) {
        if (number == 0 || value == 1) {
             return 1d;
        }

        if (value == 0) {
            return 0d;
        }

        if (number < 0) {
            value = 1 / value;

            number = Math.abs(number);
        }

        if ((number % 2) == 0) {
            return recPow(value * value, number / 2);
        }

        return value * recPow(value, number - 1);
    }

}
