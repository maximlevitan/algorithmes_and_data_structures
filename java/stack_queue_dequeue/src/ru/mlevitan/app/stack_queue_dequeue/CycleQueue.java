package ru.mlevitan.app.stack_queue_dequeue;

public class CycleQueue<T> {

    private int maxSize;

    private T[] queue;

    private int size;
    private int head;
    private int tail;

    public CycleQueue(int maxSize) {
        if (maxSize < 1 || maxSize > Integer.MAX_VALUE - 1000) {
            throw new RuntimeException("Impossible queue size " + maxSize);
        }

        this.maxSize = maxSize;
        this.queue = (T[]) (new Object[maxSize]);
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

    public void enqueue(T value) {
        if (isFull()) {
            maxSize *= 2;
            if (maxSize > Integer.MAX_VALUE - 1000) {
                throw new RuntimeException("Impossible queue size " + size);
            }

            T[] newQueue = (T[]) (new Object[maxSize]);

            System.arraycopy(queue, 0, newQueue, 0, queue.length);
            queue = newQueue;
        }

        if (tail == maxSize - 1) {
            tail = -1;
        }

        queue[++tail] = value;
        size++;

    }

    public T dequeue() {
        if (isEmpty()) {
            throw new RuntimeException("CycleQueue is empty");
        }

        T next = queue[head++];
        if (head == maxSize) {
            head = 0;
        }

        size--;

        return next;
    }

    public T peek() {
        return queue[head];
    }

    public T[] toArray() {
        return queue;
    }

}
