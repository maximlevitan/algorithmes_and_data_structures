package ru.mlevitan.app.dynamic_array;

/**
 * - Создать массив большого размера (миллион элементов).
 * - Написать методы удаления, добавления, поиска элемента массива.
 * - Заполнить массив случайными числами.
 * - Написать методы, сортировок и вывести на экран скорость выполнения каждой, используя метод System.nanoTime().
 */
public class Main {

    public static void main(String[] args) {
        int testArraySize = 100000;

        DynamicArray<Integer> test = new DynamicArray<>();

        test.randomFill(100000, 1, 10000);

        // Сортировка пузырьком 100К элементов выполнялась 29251141465 наносекунд
        SimpleSort.startTimer();
        SimpleSort.sortBubble(test.toArray());
        System.out.printf("Bubble sort array N = %d time (nanosec.): %d",
                testArraySize, SimpleSort.getResultTimeDiff());

        test = new DynamicArray<>();
        test.randomFill(100000, 1, 10000);

        // Сортировка выбором 100К элементов выполнялась 9671751959 наносекунд
        SimpleSort.startTimer();
        SimpleSort.sortSelect(test.toArray());
        System.out.printf("Select sort array N = %d time (nanosec.): %d",
                testArraySize, SimpleSort.getResultTimeDiff());

        test = new DynamicArray<>();
        test.randomFill(100000, 1, 10000);

        // Сортировка вставками 100К элементов выполнялась 7708532459 наносекунд
        SimpleSort.startTimer();
        SimpleSort.sortInsert(test.toArray());
        System.out.printf("Insert sort array N = %d time (nanosec.): %d",
                testArraySize, SimpleSort.getResultTimeDiff());
    }

}
