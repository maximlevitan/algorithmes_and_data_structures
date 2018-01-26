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
        this.head = 0;
        this.tail = -1;
        this.size = 0;
    }

    public boolean isEmpty() {
        return size == 0;
    }

    public boolean isFull() {
        return size == maxSize;
    }

    public int getSize() {
        return size;
    }

    public void addLast(T value) {
        if (isFull()) {
            maxSize *= 2;
            if (maxSize > Integer.MAX_VALUE - 1000) {
                throw new RuntimeException("Impossible dequeue size " + size);
            }

            T[] newContainer = (T[]) (new Object[maxSize]);

            System.arraycopy(container, 0, newContainer, 0, container.length);
            container = newContainer;
        }

        container[++tail] = value;
        size++;

    }

    public T removeFirst() {
        if (isEmpty()) {
            throw new RuntimeException("Deque is empty");
        }

        T next = container[head++];
        if (head == maxSize) {
            head = 0;
        }

        size--;

        return next;
    }

    public T peekFirst() {
        return container[head];
    }

    public T peekLast() {
        return container[tail];
    }

    private void resize() {
        if (isFull()) {
            maxSize *= 2;
            if (maxSize > Integer.MAX_VALUE - 1000) {
                throw new RuntimeException("Impossible dequeue size " + size);
            }

            T[] newContainer = (T[]) (new Object[maxSize]);

            System.arraycopy(container, 0, newContainer, 0, container.length);
            container = newContainer;
        }

        size++;
    }

}
