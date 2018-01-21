package ru.mlevitan.app.dynamic_array;

import java.util.Arrays;

/**
 * Создать массив большого размера (миллион элементов).
 * Написать методы удаления, добавления, поиска элемента массива.
 * Заполнить массив случайными числами.
 * Написать методы, сортировок и вывести на экран скорость выполнения каждой, используя метод System.nanoTime().
 *
 * @param <T>
 */
public class DynamicArray<T extends Object> {

    private int size = 0;

    private int capacity = 10;

    private double increaseFactor = 0.5;

    private static final int MAX_ARRAY_SIZE = (2 << 29);

    private T[] dataContainer;

    public DynamicArray() {
        this(10);
    }

    public DynamicArray(int capacity) {
        if (capacity > MAX_ARRAY_SIZE || capacity < 1) {
            throw new RuntimeException("Wrong array size");
        }

        if (capacity > this.capacity) {
            this.capacity = capacity;
        }

        dataContainer = (T[]) (new Object[this.capacity]);
    }

    public int size() {
        return size;
    }

    public DynamicArray add(T element) {
        if (size >= dataContainer.length) {
            T[] tempContainer = dataContainer;
            dataContainer = (T[]) (new Object[getNewIncreasedSize()]);

            System.arraycopy(tempContainer, 0, dataContainer, 0, size);
        }

        dataContainer[size++] = element;

        return this;
    }

    public T remove(T element) {
        T removedElement = null;

        int index = getIndex(element);
        if (index != -1) {
            removedElement = dataContainer[index];

            System.arraycopy(dataContainer, index + 1, dataContainer, index, size - index);
            this.size--;
        }

        return removedElement;
    }

    public int getIndex(T element) {
        for (int i = 0; i < size; i++) {
            if (element == null && dataContainer[i] == null
                || dataContainer[i].equals(element)
            ) {
                return i;
            }
        }

        return -1;
    }

    public T find(T element) {
        T findElement = null;

        int index = getIndex(element);
        if (index != -1) {
            findElement = dataContainer[index];
        }

        return findElement;
    }

    public void randomFill() {
        // @todo
    }

    public T[] toArray() {
        return dataContainer;
    }

    @Override
    public String toString() {
        return Arrays.toString(dataContainer);
    }

    private int getNewIncreasedSize() {
        return (int) (size * (1 + increaseFactor));
    }

}
