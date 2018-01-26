package ru.mlevitan.app.stack_queue_dequeue;

public class Deque<T> {

    private int maxSize;

    private T[] container;

    private int size;
    private int head;
    private int tail;

    public Deque(int maxSize) {
        if (maxSize < 1 || maxSize > Integer.MAX_VALUE - 1000) {
            throw new RuntimeException("Impossible dequeue size " + maxSize);
        }

        this.maxSize = maxSize;
        this.container = (T[]) (new Object[maxSize]);
        this.head = maxSize / 2;
        this.tail = this.head - 1;
        this.size = 0;
    }

    public boolean isEmpty() {
        return size == 0;
    }

    public boolean isFull() {
        return (head == 0 || tail == maxSize - 1);
    }

    public int getSize() {
        return size;
    }

    public void addLast(T value) {
        if (isFull()) {
            resize();
        }

        container[++tail] = value;
        size++;
    }

    public void addFirst(T value) {
        if (isFull()) {
            resize();
        }

        container[--head] = value;
        size++;
    }

    public T removeFirst() {
        if (isEmpty()) {
            throw new RuntimeException("Deque is empty");
        }

        T next = container[head];
        head++;
        size--;

        return next;
    }

    public T removeLast() {
        if (isEmpty()) {
            throw new RuntimeException("Deque is empty");
        }

        T previous = container[tail];
        tail--;
        size--;

        return previous;
    }

    public T peekFirst() {
        return container[head];
    }

    public T peekLast() {
        return container[tail];
    }

    private void resize() {
        maxSize *= 2;
        if (maxSize > Integer.MAX_VALUE - 1000) {
            throw new RuntimeException("Impossible dequeue size " + size);
        }

        T[] newContainer = (T[]) (new Object[maxSize]);

        int newMiddle = maxSize / 2;

        System.arraycopy(container, 0, newContainer, newMiddle - container.length / 2, container.length);
        head = newMiddle - (container.length / 2 - head);
        tail = head + size - 1;

        container = newContainer;
    }

}
