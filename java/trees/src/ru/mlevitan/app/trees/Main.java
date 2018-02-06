package ru.mlevitan.app.trees;

import java.util.Random;

public class Main {

    private static Random random = new Random(System.currentTimeMillis());

    public static void main(String[] args) {
        int noBalanceCount = 0;

        for (int i = 0; i < 20; i++) {
            Tree<Integer> someTree = generateTree(18, -100, 100);

            //System.out.println("Tree height: " + someTree.getHeight());
            //System.out.println("Tree is balanced: " + someTree.isBalanced());

            if (!someTree.isBalanced()) {
                noBalanceCount++;
            }
        }

        System.out.println("Процент несбалансированных деревьев: " + (noBalanceCount * 100 / 20) + "%");
    }

    private static Tree<Integer> generateTree(int size, int from, int to) {
        Tree<Integer> tree = new Tree<>();

        for (int i = 0; i < size; i++) {
            tree.insert(rand(from, to));
        }

        return tree;
    }

    private static int rand(int min, int max) {
        return min + random.nextInt(max - min + 1);
    }

}
