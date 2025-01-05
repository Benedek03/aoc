import java.io.FileNotFoundException;
import java.io.File;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws FileNotFoundException  {
        Scanner scanner = new Scanner(new File("2024/07/input.txt"));
        List<List<Long>> equations = new ArrayList<>();
        while (scanner.hasNextLine()) {
            List<Long> equation = new ArrayList<>();
            String[] parts = scanner.nextLine().replace(": ", " ").split(" ");
            for (String part : parts) {
                equation.add(Long.parseLong(part));
            }
            equations.add(equation);
        }
        scanner.close();

        System.out.println("2024/07:");
        System.out.println("part1: " + part1(equations));
        System.out.println("part2: " + part2(equations));
    }

    public static long part1(List<List<Long>> equations) {
        long sum = 0;
        for (List<Long> equation : equations) {
            int operators = equation.size() - 2;
            for (int i = 0; i < Math.pow(2, operators); i++) {
                long res = equation.get(1);
                for (int j = 0; j < operators; j++) {
                    if (((i >> j) & 1) == 1) {
                        res *= equation.get(j + 2);
                    } else {
                        res += equation.get(j + 2);
                    }
                }
                if (res == equation.get(0)) {
                    sum += res;
                    break;
                }
            }
        }
        return sum;
    }

    public static long part2(List<List<Long>> equations) {
        long sum = 0;
        for (List<Long> equation : equations) {
            List<Long> results = new ArrayList<>();
            results.add(equation.get(1));
            for (int i = 2; i < equation.size(); i++) {
                List<Long> newResults = new ArrayList<>();
                for (long res : results) {
                    newResults.add(res + equation.get(i));
                    newResults.add(res * equation.get(i));
                    newResults.add(Long.parseLong("" + res + equation.get(i)));
                }
                results = newResults;
            }
            if (results.contains(equation.get(0))) {
                sum += equation.get(0);
            }
        }
        return sum;
    }
}