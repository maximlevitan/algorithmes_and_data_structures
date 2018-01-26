package ru.mlevitan.app.stack_queue_dequeue;

public class PriorityCycleQueue<T extends Object & Comparable<T>> extends CycleQueue {

    public PriorityCycleQueue(int maxSize) {
        super(maxSize);
    }

    @Override
    public void enqueue(Object value) {
        super.enqueue(value);

        T[] containerQueue = (T[]) toArray();

        int idx;
        for (idx = 0; idx < getSize(); idx++) {
            if (containerQueue[idx].compareTo((T) value) > 0) {
                break;
            }
        }

        System.arraycopy(containerQueue, idx, containerQueue, idx + 1, getSize() - idx);

        containerQueue[idx] = (T) value;
    }

}
