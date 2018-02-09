package ru.mlevitan.app.graphes;

import java.util.NoSuchElementException;

public class DoublyLinkedList<T> {

    private DoublyNode<T> head;

    private DoublyNode<T> tail;

    private int size;

    public DoublyLinkedList() {
        size = 0;
    }

    public int getSize() {
        return size;
    }

    public boolean isEmpty() {
        return size == 0;
    }

    public void addFirst(T value) {
        DoublyNode<T> newNode = new DoublyNode<>(value);

        if (head != null) {
            newNode.setNext(head);
            head.setPrev(newNode);
        }

        head = newNode;
        if (tail == null) {
            tail = head;
        }

        size++;
    }

    public void addLast(T value) {
        DoublyNode<T> newNode = new DoublyNode<>(value);

        if (tail != null) {
            newNode.setPrev(tail);
            tail.setNext(newNode);
        }

        tail = newNode;
        if (head == null) {
            head = tail;
        }

        size++;
    }

    public T removeFirst() {
        if (isEmpty()) {
            throw new NoSuchElementException();
        }

        T value = head.getValue();

        head = head.getNext();
        if (head != null) {
            head.setPrev(null);
        }
        size--;

        return value;
    }

    public T removeLast() {
        if (isEmpty()) {
            throw new NoSuchElementException();
        }

        T value = tail.getValue();

        tail = tail.getPrev();
        if (tail != null) {
            tail.setNext(null);
        }
        size--;

        return value;
    }

    public DoublyNode<T> removeNode(T value) {
        DoublyNode<T> node = findNode(value);
        deleteNode(node);

        return node;
    }

    public DoublyNode<T> getFirstNode() {
        return head;
    }

    public DoublyNode<T> getLastNode() {
        return tail;
    }

    public DoublyNode<T> findNode(T value) {
        DoublyNode<T> current = head;

        while (!current.getValue().equals(value)) {
            if(current.getNext() == null) {
                return null;
            } else {
                current = current.getNext();
            }
        }

        return current;
    }

    public void deleteNode(DoublyNode<T> node) {
        if (node == null || isEmpty()) {
            throw new NoSuchElementException();
        }

        if (node == head) {
            head = head.getNext();
            if (head != null) {
                head.setPrev(null);
            }

            node = head;
        } else if (node == tail) {
            tail = node.getPrev();
            if (tail != null) {
                tail.setNext(null);
            }
            node = tail;
        } else {
            DoublyNode<T> next = node.getNext();
            node = node.getPrev();

            node.setNext(next);
            next.setPrev(node);
        }

        size--;
    }

    @Override
    public String toString() {
        DoublyNode<T> current = head;
        StringBuilder buffer = new StringBuilder("[ ");

        while (current != null) {
            buffer.append(current.getValue().toString());
            current = current.getNext();

            buffer.append((current == null) ? " ]" : ", ");
        }

        return buffer.toString();
    }

}
