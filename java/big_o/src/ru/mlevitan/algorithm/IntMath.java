package ru.mlevitan.algorithm;

public class IntMath {

    public int operationCount = 0;

    /**
     * Возведение целого числа в степень целого неотрицательного числа
     *
     * Худший случай: O(n) - если степень не делится на 2
     * Лучший случай: O(log n) - достигается, когда степень кратна числу 2 и является степенью числа 2
     *
     * @param value
     * @param power
     * @return
     */
    public int pow(int value, int power) {
        int result = 1;

        operationCount = 1;

        if (power < 0) {
            throw new RuntimeException("Unexpected power value: less then 0");
        }

        if (power == 0) {
            result = 1;
        }

        if (value > 1 && power != 0) {
            while (power > 0) {
                // Операция аналогичная делению по модулю 2, проверяем первый бит
                if ((power & 1) == 0) {
                    power >>= 1; // делим на 2 посредством смещения битов вправо
                    value *= value;
                } else {
                    result *= value;
                    power--;
                }

                operationCount++;
            }
        }

        return result;
    }

}
