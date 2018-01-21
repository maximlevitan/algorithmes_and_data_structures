package ru.mlevitan.app.dynamic_array;

import java.util.Arrays;

public class Main {

    public static void main(String[] args) {
        DynamicArray<Integer> test = new DynamicArray<>();

        for (int i = 0; i < 100; i++) {
            test.add(i + 1);
        }

        for (int i = 19; i < 50; i++) {
            test.remove(i + 1);
        }

        System.out.println(test);
    }

}
