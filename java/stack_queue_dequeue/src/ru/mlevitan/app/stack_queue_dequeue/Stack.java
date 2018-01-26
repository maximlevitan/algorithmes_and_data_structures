package ru.mlevitan.app.stack_queue_dequeue;

public class Stack<T> {

    private T[] stack;
    private int head;
    private int size;

    public Stack(int size) {
        if (size < 1 || size > Integer.MAX_VALUE - 1000) {
            throw new RuntimeException("Impossible stack size " + size);
        }

        this.size = size;
        this.stack = (T[]) (new Object[size]);
        this.head = -1;
    }

    public boolean isEmpty() {
        return head == -1;
    }

    public boolean isFull() {
        return size - 1 == head;
    }

    public void push(T value) {
        if (isFull()) {
            size *= 2;
            if (size > Integer.MAX_VALUE - 1000) {
                throw new RuntimeException("Impossible stack size " + size);
            }

            T[] newStack = (T[]) (new Object[size]);

            System.arraycopy(stack, 0, newStack, 0, stack.length);
            stack = newStack;
        }

        stack[++head] = value;
    }

    public T pop() {
        if (isEmpty()) {
            throw new RuntimeException("Stack is empty!");
        }

        return stack[head--];
    }

    public T peek() {
        if (isEmpty()) {
            throw new RuntimeException("Stack is empty!");
        }

        return stack[head];
    }

}
