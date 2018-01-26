package ru.mlevitan.app.stack_queue_dequeue;

import java.util.ArrayDeque;

/**
 * 1. Создать программу, которая переворачивает вводимые строки
 * 2. Создать класс для реализации дека
 * 3. Реализовать класс с реализацией приоритетной очереди
 */
public class Main {

    public static void main(String[] args) {
        String input = "Test string!";

        System.out.println("String before revert: " + input);
        System.out.println("String after revert: " + revertString(input));
    }

    public static String revertString(String input) {
        String result = null;
        StringBuilder buffer = new StringBuilder();

        int inputSize = (input != null) ? input.length() : 0;
        if (inputSize > 0) {
            Stack<Character> stack = new Stack<>(inputSize);
            int i;

            for (i = 0; i < inputSize; i++) {
                stack.push(input.charAt(i));
            }

            for (i = 0; i < inputSize; i++) {
                buffer.append(stack.pop());
            }

            result = buffer.toString();
        }

        return result;
    }

}
