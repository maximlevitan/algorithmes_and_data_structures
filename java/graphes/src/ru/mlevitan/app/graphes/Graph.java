package ru.mlevitan.app.graphes;

public class Graph {

    private static final int MAX_VERTS = 32;
    private Vertex[] vertices;
    private int[][] adjMatrix;
    private int size;

    Graph() {
        vertices = new Vertex[MAX_VERTS];
        adjMatrix = new int[MAX_VERTS][MAX_VERTS];
        this.size = 0;
    }

    public void addVertex(char label) {
        vertices[size++] = new Vertex(label);
    }

    public void addEdge(int start, int end) {
        adjMatrix[start][end] = 1;
        adjMatrix[end][start] = 1;
    }

    public void showVertex(int vertex) {
        System.out.println(vertices[vertex]);
    }

    private int getUncheckedVertex(int ver) {
        for (int i = 0; i < size; i++) {
            if (adjMatrix[ver][i] == 1 &&
                    !vertices[i].wasVisited)
                return i;
        }
        return -1;
    }

    /**
     * Обход графа в глубину DFS (depth-first search)
     */
    public void depthTravers() {
        DoublyLinkedList<Integer> stack = new DoublyLinkedList<>();

        vertices[0].wasVisited = true;
        showVertex(0);
        stack.addFirst(0);

        while (!stack.isEmpty()) {
            int v = getUncheckedVertex(stack.getFirstNode().getValue());
            if (v == -1) {
                stack.removeFirst();
            } else {
                vertices[v].wasVisited = true;
                showVertex(v);
                stack.addFirst(v);
            }
        }

        for (int i = 0; i < size; i++) {
            vertices[i].wasVisited = false;
        }
    }

    /**
     * Обход графа в ширину BFS (breadth-first search)
     */
    public void widthTravers() {
        DoublyLinkedList<Integer> queue = new DoublyLinkedList<>();

        vertices[0].wasVisited = true;
        showVertex(0);
        queue.addLast(0);

        while (!queue.isEmpty()) {
            int v1 = queue.removeLast();
            int v2;
            while ((v2 = getUncheckedVertex(v1)) != -1) {
                vertices[v2].wasVisited = true;
                showVertex(v2);
                queue.addLast(v2);
            }
        }

        for (int i = 0; i < size; i++) {
            vertices[i].wasVisited = false;
        }
    }

}
