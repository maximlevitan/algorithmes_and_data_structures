package ru.mlevitan.algorithm;


public class ArrayNumberMath {

    public int operationCount = 0;

    /**
     * Получить максимальный элемент массива
     *
     * Сложность алгоритма: O(n)
     *
     * @param array
     * @param <T>
     * @return min
     */
    public <T extends Number & Comparable<T>> T min(T[] array) {
        T min = null;
        operationCount = 1;

        int size = array.length;

        if (size < 1) {
            throw new RuntimeException("Can`t find min value in empty array");
        }

        min = array[0];
        for (int i = 1; i < size; i++) {
            if (array[i].compareTo(min) < 0) {
                min = array[i];
            }

            operationCount++;
        }

        return (T) min;
    }

    /**
     * Получить среднее арифметическое двух чисел
     *
     * Сложность алгоритма: O(n)
     *
     * @param array
     * @param <T>
     * @return avg
     */
    public <T extends Number> double avg(T[] array) {
        double avg = 0.0;
        double sum = 0.0;

        operationCount = 1;

        int size = array.length;

        if (size < 1) {
            throw new RuntimeException("Can`t find min value in empty array");
        }

        sum = array[0].doubleValue();
        for (int i = 1; i < size; i++) {
            sum += array[i].doubleValue();

            operationCount++;
        }

        avg = sum / size;

        operationCount++;

        return avg;
    }

}
