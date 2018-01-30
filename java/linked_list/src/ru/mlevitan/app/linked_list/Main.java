package ru.mlevitan.app.linked_list;

import java.util.Iterator;

/**
 * Реализовать двусвязный список
 * Реализовать класс итератора
 * Написать программу, использующую связанный список и все методы итератора
 */
public class Main {

    public static void main(String[] args) {
        DoublyLinkedList<Integer> dblLinkedList = new DoublyLinkedList<>();

        System.out.println("Добавляем и удаляем элементы для проверки корректности работы методов");
        dblLinkedList.addFirst(1);
        dblLinkedList.addFirst(2);
        dblLinkedList.addFirst(3);
        dblLinkedList.addFirst(4);
        dblLinkedList.addFirst(5);
        dblLinkedList.addLast(1);
        dblLinkedList.addLast(2);
        dblLinkedList.addLast(3);
        dblLinkedList.addLast(4);
        dblLinkedList.addLast(5);

        System.out.println(dblLinkedList.toString());

        dblLinkedList.removeFirst();
        dblLinkedList.removeLast();
        dblLinkedList.removeLast();

        System.out.println(dblLinkedList.toString());

        dblLinkedList.removeNode(1);
        dblLinkedList.removeNode(4);

        System.out.println(dblLinkedList.toString());

        dblLinkedList.addLast(4);

        System.out.println(dblLinkedList.toString());

        dblLinkedList.removeNode(4);

        System.out.println(dblLinkedList.toString());

        System.out.println("\nЦикл с использованием итератора и удалением элемента");
        System.out.print("[ ");
        Iterator<Integer> iterator = dblLinkedList.iterator();
        while (iterator.hasNext()) {
            Integer value = iterator.next();
            System.out.print(value + (iterator.hasNext() ? ", " : ""));
            if (value == 1) {
                iterator.remove();
            }
        }
        System.out.print(" ]\n");

        System.out.println("\nЦикл с использованием итератора для вывода элементов");
        System.out.print("[ ");
        int counter = 0;
        for (Integer value : dblLinkedList) {
            System.out.print((counter > 0 ? ", " : "") + value);
            counter++;
        }
        System.out.print(" ]\n");
    }

}
