package ru.mlevitan.app.dynamic_array;

public class SimpleSort {

    public static <T extends Object & Comparable<T>> void bubbleSort(T[] array) {
        int size = array.length;

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                compareAndSwap(array, i, j);
            }
        }
    }

    private static <T extends Object & Comparable<T>> void compareAndSwap(T[] array, int index1, int index2) {
        if (array[index2] == null
            || array[index1] != null && array[index2] != null && array[index1].compareTo(array[index2]) < 0
        ) {
            T temp = array[index1];
            array[index1] = array[index2];
            array[index2] = temp;
        }
    }
}
