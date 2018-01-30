package ru.mlevitan.app.linked_list;

import java.util.Iterator;

public class DoublyLinkedListIterator<T> implements Iterator<T> {

    private DoublyLinkedList<T> list;

    private DoublyNode<T> currentNode;

    private int index = -1;

    public DoublyLinkedListIterator(DoublyLinkedList<T> list) {
        this.list = list;
        reset();
    }

    public void reset() {
        index = -1;
        currentNode = list.getFirstNode();
    }

    @Override
    public boolean hasNext() {
        return (currentNode.getNext() != null);
    }

    @Override
    public T next() {
        T result = null;
        if (index < 0) {
            result = currentNode.getValue();
            index++;
        } else if (hasNext()) {
            currentNode = currentNode.getNext();
            result = currentNode.getValue();
            index++;
        }

        return result;
    }

    @Override
    public void remove() {
        list.deleteNode(currentNode);
    }

    public DoublyNode getCurrent() {
        return currentNode;
    }

}
