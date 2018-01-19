package ru.mlevitan.algorithm;

public class Main {

    public static void main(String[] args) {

        // Возведение в степень
        calcPow(2, 16);
        calcPow(3, 9);

        // Поиск минимального элемента в массиве
        findMinInArray(new Integer[]{ 1, 2, 3, 4, 5, 6, 7 });
        findMinInArray(new Integer[]{ 7, 2, 5, 1, 6, 3, 4 });
        findMinInArray(new Double[]{ 7.0, 2.2, 5.1, 1.4, 6.2, 3.0, 4.1 });

        // Нахождение среднего арифметического элементов массива
        calcAvgInArray(new Integer[]{ 1, 2, 3, 4, 5, 6, 7 });
        calcAvgInArray(new Double[]{ 7.0, 2.2, 5.1, 1.4, 6.2, 3.0, 4.1 });
    }

    private static void calcPow(int value, int power) {
        IntMath math = new IntMath();

        int result = math.pow(value, power);

        System.out.printf("Result: %d pow %d = %d, operations count: %d.\n", value, power, result, math.operationCount);
    }


    private static <T extends Number & Comparable<T>> void findMinInArray(T[] array) {
        ArrayNumberMath arrayNumberMath = new ArrayNumberMath();

        T result = arrayNumberMath.min(array);

        System.out.printf(
                "Result: min value = %s, in array with elements count: %d, operations count: %d.\n",
                result.toString(),
                array.length,
                arrayNumberMath.operationCount
        );
    }

    private static <T extends Number & Comparable<T>> void calcAvgInArray(T[] array) {
        ArrayNumberMath arrayNumberMath = new ArrayNumberMath();

        double result = arrayNumberMath.avg(array);

        System.out.printf(
                "Result: avg value = %f, in array with elements count: %d, operations count: %d.\n",
                result,
                array.length,
                arrayNumberMath.operationCount
        );
    }

}
