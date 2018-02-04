package ru.mlevitan.app.trees;

import java.util.Random;

public class Main {

    private static Random random = new Random(System.currentTimeMillis());

    public static void main(String[] args) {
        Tree<Integer> tree1 = generateTree(100, -100, 100);

        tree1.displayTree();
    }

    private static Tree<Integer> generateTree(int size, int from, int to) {
        Tree<Integer> tree = new Tree<>();

        for (int i = 0; i < size; i++) {
            ;
            tree.insert(rand(from, to));
        }

        return tree;
    }

    private static int rand(int min, int max) {
        return min + random.nextInt(max - min + 1);
    }

}
