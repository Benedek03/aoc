import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner scanner = new Scanner(new File("2024/05/input.txt"));
        Map<Integer, List<Integer>> rules = new HashMap<>();
        List<List<Integer>> updates = new ArrayList<>();
        while (true) {
            String line =  scanner.nextLine();
            if (line.matches("\\d+\\|\\d+")) {
                String[] parts = line.split("\\|");
                int a = Integer.parseInt(parts[0]);
                int b = Integer.parseInt(parts[1]);
                if (rules.containsKey(a)) {
                    rules.get(a).add(b);
                } else {
                    List<Integer> list = new ArrayList<>();
                    list.add(b);
                    rules.put(a, list);
                }
            }
            
            else break;
        }
        while (scanner.hasNextLine()) {
            List<Integer> update = new ArrayList<>();
            String line = scanner.nextLine();
            for (String u : line.split(","))
                update.add(Integer.parseInt(u));
            updates.add(update);
        }
        scanner.close();

        System.out.println("2024/05:");
        System.out.println("part1: " + part1(rules, updates));
        System.out.println("part2: " + part2(rules, updates));
    }

    public static int part1(Map<Integer, List<Integer>> rules, List<List<Integer>> updates) {
        int sum = 0;
        for (List<Integer> update : updates) {
            boolean valid = true;
            for (int i = 0; valid && i < update.size(); i++) {
                List<Integer> rule = rules.get(update.get(i));
                if (rule == null) continue;
                for (int j = 0; valid && j < i; j++) {
                    if (rule.contains(update.get(j))) {
                        valid = false;
                    }
                }
            }
            if (valid) {
                sum += update.get(update.size() / 2);
            }
        }
        return sum;
    }

    public static int part2(Map<Integer, List<Integer>> rules, List<List<Integer>> updates) {
        int sum = 0;
        for (List<Integer> update : updates) {
            boolean valid = true;
            for (int i = 0; valid && i < update.size(); i++) {
                List<Integer> rule = rules.get(update.get(i));
                if (rule == null) continue;
                for (int j = 0; valid && j < i; j++) {
                    if (rule.contains(update.get(j))) {
                        valid = false;
                    }
                }
            }
            if (!valid) {
                while (!valid) {
                    valid = true;
                    for (int i = 0; valid && i < update.size(); i++) {
                        List<Integer> rule = rules.get(update.get(i));
                        if (rule == null) continue;
                        for (int j = 0; valid && j < i; j++) {
                            if (rule.contains(update.get(j))) {
                                int temp = update.get(i);
                                update.set(i, update.get(j));
                                update.set(j, temp);
                                valid = false;
                            }
                        }
                    }
                }
                sum += update.get(update.size() / 2);
            }
        }
        return sum;
    }
}
