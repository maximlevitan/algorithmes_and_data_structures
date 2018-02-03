package ru.mlevitan.app.recursion;

public class Main {

    public static void main(String[] args) {
        double value = 2;
        double number = 10;
        double result = Power.recPow(value, number);
        System.out.printf("Calc power: %.2f ** %.2f = %.4f\n\n\n", value, number, result);

        KnapsackProblem bagTask = new KnapsackProblem();

        bagTask.putToAllSubjectsSet(1, 30);
        bagTask.putToAllSubjectsSet(3, 40);
        bagTask.putToAllSubjectsSet(7, 20);
        bagTask.putToAllSubjectsSet(2, 50);
        bagTask.putToAllSubjectsSet(4, 10);
        bagTask.putToAllSubjectsSet(8, 30);
        bagTask.putToAllSubjectsSet(10, 10);
        bagTask.putToAllSubjectsSet(9, 100);
        bagTask.putToAllSubjectsSet(4, 10);
        bagTask.putToAllSubjectsSet(8, 30);

        int maxPrice = bagTask.getMaxSubjectsPrice(100);

        System.out.println("Max knapsack price: " + maxPrice);
        System.out.println("Subjects in knapsack after filling:\n" + bagTask);
    }

}
