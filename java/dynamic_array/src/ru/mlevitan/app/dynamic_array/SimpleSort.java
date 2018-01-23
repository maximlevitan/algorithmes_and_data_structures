package ru.mlevitan.app.dynamic_array;

public class SimpleSort {

    private static long startedNanoTime;

    public static <T extends Object & Comparable<T>> void sortBubble(T[] array) {
        int size = array.length;
        int j;

        for (int i = 0; i < size; i++) {
            for (j = i; j < size - 1; j++) {
                compareAndSwap(array, i, j + 1);
            }
        }
    }

    public static <T extends Object & Comparable<T>> void sortSelect(T[] array) {
        int size = array.length;
        int mark;
        int j;

        for (int i = 0; i < size - 1; i++) {
            mark = i;
            for (j = i + 1; j < size; j++) {
                if (array[j] != null && array[mark] != null && array[j].compareTo(array[mark]) < 0) {
                    mark = j;
                }
            }

            swap(array, i, mark);
        }
    }

    public static <T extends Object & Comparable<T>> void sortInsert(T[] array) {
        int size = array.length;
        int j;
        T temp;

        for (int i = 1; i < size; i++) {
            if (array[i] == null || array[i - 1] == null) {
                continue;
            }

            temp = array[i];
            for (j = i; j > 0 && array[j - 1].compareTo(temp) > 0; j--) {
                array[j] = array[j - 1];
            }

            array[j] = temp;
        }
    }

    public static void startTimer() {
        startedNanoTime = System.nanoTime();
    }

    public static long getResultTimeDiff() {
        return System.nanoTime() - startedNanoTime;
    }

    private static <T extends Object & Comparable<T>> void compareAndSwap(T[] array, int index1, int index2) {
        if (array[index1] != null && array[index2] != null && array[index1].compareTo(array[index2]) > 0) {
            T temp = array[index1];
            array[index1] = array[index2];
            array[index2] = temp;
        }
    }

    private static <T extends Object> void swap(T[] array, int index1, int index2) {
        T temp = array[index1];
        array[index1] = array[index2];
        array[index2] = temp;
    }
}
