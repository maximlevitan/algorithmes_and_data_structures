package ru.mlevitan.app.graphes;

public class Main {

    public static void main(String[] args) {
        Graph g = new Graph();

        g.addVertex('a');
        g.addVertex('b');
        g.addVertex('c');
        g.addVertex('d');
        g.addVertex('e');
        g.addVertex('f');
        g.addVertex('g');
        g.addVertex('h');
        g.addVertex('i');
        g.addVertex('j');

        g.addEdge(0, 1);
        g.addEdge(0, 2);
        g.addEdge(1, 7);
        g.addEdge(2, 8);
        g.addEdge(3, 4);
        g.addEdge(3, 8);
        g.addEdge(4, 5);
        g.addEdge(5, 6);
        g.addEdge(6, 9);
        g.addEdge(7, 9);
        g.addEdge(8, 9);

        /**
         * Graph:
         *
         *    a0 - b1
         *   /       \
         * c2        h7
         *  \        /
         *   I8 - J9
         *  /       \
         * d3       g6
         *  \       /
         *   e4 - f5
         *
         */

        // DFS
        g.depthTravers();
        System.out.println("--------------");

        // BFS
        g.widthTravers();
    }

}
