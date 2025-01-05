import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner scanner = new Scanner(new File("2024/02/input.txt"));
        List<List<Integer>> reports = new ArrayList<>();
        while (scanner.hasNextLine()) {
            List<Integer> report = new ArrayList<>();
            Scanner lineScanner = new Scanner(scanner.nextLine());
            while (lineScanner.hasNextInt()) {
                report.add(lineScanner.nextInt());
            }
            reports.add(report);
            lineScanner.close();
        }
        scanner.close();

        System.out.println("2024/02:");
        System.out.println("part1: " + part1(new ArrayList<>(reports)));
        System.out.println("part2: " + part2(new ArrayList<>(reports)));
    }

    public static boolean safe(List<Integer> report) {
        boolean increasing = report.get(0) < report.get(1);
        for (int i = 0; i < report.size() - 1; i++) {
            int diff = Math.abs(report.get(i) - report.get(i + 1));
            if (increasing != (report.get(i) < report.get(i + 1)) || diff < 1 || diff > 3)
                return false;
        }
        return true;
    }

    public static int part1(List<List<Integer>> reports) {
        int count = 0;
        for (List<Integer> report : reports) {
            if (safe(new ArrayList<>(report))) count++;
        }
        return count;
    }

    public static int part2(List<List<Integer>> reports) {
        int count = 0;
        for (List<Integer> report : reports) {
            if (safe(new ArrayList<>(report))) count++;
            else for (int i = 0; i < report.size(); i++) {
                List<Integer> newReport = new ArrayList<>(report);
                newReport.remove(i);
                if (safe(newReport)) {
                    count++;
                    break;
                }
            }
        }
        return count;
    }
}
