package ru.mlevitan.app.dynamic_array;

public class Main {

    public static void main(String[] args) {
        DynamicArray<Integer> test = new DynamicArray<>();

        test.randomFill(1000000, 1, 10000);

        SimpleSort.bubbleSort(test.toArray());

        System.out.println(test.size());

        //System.out.println(test);
    }

}
