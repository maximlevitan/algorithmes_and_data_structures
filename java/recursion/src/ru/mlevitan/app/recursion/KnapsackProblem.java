package ru.mlevitan.app.recursion;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.TreeSet;

/**
 * Написать программу «Задача о рюкзаке» с помощью рекурсии.
 * Вывести итоговую стоимость "рюкзака".
 * Нерекурсивное решение и рекуррентные соотношения.
 *
 * Задача о рюкзаке: NP-полная задача комбинаторной оптимизации.
 * С различными вариациями задачи о ранце можно столкнуться в экономике,
 * прикладной математике, криптографии и логистике.
 *
 * Цель: уложить как можно большее число ценных вещей в рюкзак при условии, что вместимость рюкзака ограничена.
 *
 * В общем виде задачу можно сформулировать так:
 * из заданного множества предметов со свойствами «стоимость» и «вес»
 * требуется отобрать подмножество с максимальной полной стоимостью,
 * соблюдая при этом ограничение на суммарный вес.
 */
public class KnapsackProblem {

    private static int uid = 0;

    private class Subject {

        int number;
        int weight;
        int price;

        Subject(int number, int price, int weight) {
            this.number = number;
            this.price = price;
            this.weight = weight;
        }

        @Override
        public String toString() {
            return "{number: " + number + ", price: " + price + ", weight: " + weight + "}";
        }
    }

    private TreeSet<Subject> allSubjectsSet = new TreeSet<>(new Comparator<Subject>() {
        @Override
        public int compare(Subject o1, Subject o2) {
            if (o1.price == o2.price) {
                if (o1.number == o2.number) {
                    return 0;
                }

                return (o1.number < o2.number) ? -1 : 1;
            }

            return (o1.price < o2.price) ? 1 : -1;
        }
    });

    private ArrayList<Subject> knapsackList = new ArrayList<>();

    public void putToAllSubjectsSet(int price, int weight) {
        allSubjectsSet.add(new Subject(++uid, price, weight));
    }

    /**
     * Получить максимальную ценность предметов,
     * которые можно поместить в рюкзак грузоподъемностью w.
     *
     * Метод рекурсивно складывает предметы в рюкзак,
     * рассчитывает и возвращает суммарную ценность всех предметов,
     * помещенных в рюкзак.
     *
     * Рекуррентное соотношение:
     *        |  0,              w = 0
     * f(w) = |  f(w),           vi is max, wi > w
     *        |  vi + f(w - wi), vi is max, wi <= w
     *
     * @param maxWeight
     * @return
     */
    public int getMaxSubjectsPrice(int maxWeight) {
        if (maxWeight <= 0 || allSubjectsSet.isEmpty()) {
            return 0;
        }

        Subject subjectWithMaxPrice = allSubjectsSet.first();
        allSubjectsSet.remove(subjectWithMaxPrice);

        if (subjectWithMaxPrice.weight > maxWeight) {
            return getMaxSubjectsPrice(maxWeight);
        }

        // Put subject to bag
        knapsackList.add(subjectWithMaxPrice);

        return subjectWithMaxPrice.price + getMaxSubjectsPrice(maxWeight - subjectWithMaxPrice.weight);
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();

        int size = knapsackList.size();

        sb.append("[");
        for (int i = 0; i < size; i++) {
            sb.append(i == 0 ? "\n    " : "    ");
            sb.append(i);
            sb.append(": ");
            sb.append(knapsackList.get(i).toString());
            sb.append(i < size - 1 ? ",\n" : "\n");
        }
        sb.append("]");

        return sb.toString();
    }

}
