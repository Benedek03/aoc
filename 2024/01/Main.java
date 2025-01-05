import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.function.Function;
import java.util.stream.Collectors;

class Main {
    public static void main(String[] args) throws FileNotFoundException  {
        Scanner scanner = new Scanner(new File("2024/01/input.txt"));
        List<Integer> list1 = new ArrayList<>();
        List<Integer> list2 = new ArrayList<>();
        while (scanner.hasNextInt()) {
            list1.add(scanner.nextInt());
            list2.add(scanner.nextInt());
        }
        scanner.close();

        System.out.println("2024/01:");
        System.out.println("part1: " + part1(new ArrayList<>(list1), new ArrayList<>(list2)));
        System.out.println("part2: " + part2(new ArrayList<>(list1), new ArrayList<>(list2)));
    }
    
    public static int part1(List<Integer> list1, List<Integer> list2) {
        Collections.sort(list1);
        Collections.sort(list2);

        int sum = 0;
        for (int i = 0; i < list1.size(); i++) {
            sum += Math.abs(list1.get(i) - list2.get(i));
        }

        return sum;
    }

    public static long part2(List<Integer> list1, List<Integer> list2) {
        Map<Integer, Long> occurences = list2.stream().collect(Collectors.groupingBy(Function.identity(), Collectors.counting()));

        long sum = 0;
        for (Integer i : list1) {
            Long o = occurences.get(i);
            if (o != null)
                sum += i * o;
        }
        return sum;
    }
}