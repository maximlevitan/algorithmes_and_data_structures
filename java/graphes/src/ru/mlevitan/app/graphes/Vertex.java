package ru.mlevitan.app.graphes;

public class Vertex {

    public char label;
    public boolean wasVisited;

    public Vertex(char label) {
        this.label = label;
        this.wasVisited = false;
    }

    @Override
    public String toString() {
        return "Vertex: " + label;
    }

}
