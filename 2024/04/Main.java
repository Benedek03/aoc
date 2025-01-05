import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner scanner = new Scanner(new File("2024/04/input.txt"));
        List<String> input = new ArrayList<>();
        while (scanner.hasNextLine()) {
            input.add(scanner.nextLine());
        }
        scanner.close();

        System.out.println("2024/04:");
        System.out.println("part1: " + part1(input));
        System.out.println("part2: " + part2(input));
    }

    public static int part1(List<String> input) {
        final int l = input.size();
        final int k = input.get(0).length();
        
        int count = 0;
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < k; j++) {
                // right
                if (j + 3 < k && input.get(i).charAt(j) == 'X' && input.get(i).charAt(j + 1) == 'M' && input.get(i).charAt(j + 2) == 'A' && input.get(i).charAt(j + 3) == 'S') {
                    count++;
                }
                // left
                if (j - 3 >= 0 && input.get(i).charAt(j) == 'X' && input.get(i).charAt(j - 1) == 'M' && input.get(i).charAt(j - 2) == 'A' && input.get(i).charAt(j - 3) == 'S') {
                    count++;
                }
                // up
                if (i - 3 >= 0 && input.get(i).charAt(j) == 'X' && input.get(i - 1).charAt(j) == 'M' && input.get(i - 2).charAt(j) == 'A' && input.get(i - 3).charAt(j) == 'S') {
                    count++;
                }
                // down
                if (i + 3 < l && input.get(i).charAt(j) == 'X' && input.get(i + 1).charAt(j) == 'M' && input.get(i + 2).charAt(j) == 'A' && input.get(i + 3).charAt(j) == 'S') {
                    count++;
                }
                // right-up
                if (j + 3 < k && i - 3 >= 0 && input.get(i).charAt(j) == 'X' && input.get(i - 1).charAt(j + 1) == 'M' && input.get(i - 2).charAt(j + 2) == 'A' && input.get(i - 3).charAt(j + 3) == 'S') {
                    count++;
                }
                // right-down
                if (j + 3 < k && i + 3 < l && input.get(i).charAt(j) == 'X' && input.get(i + 1).charAt(j + 1) == 'M' && input.get(i + 2).charAt(j + 2) == 'A' && input.get(i + 3).charAt(j + 3) == 'S') {
                    count++;
                }
                // left-up
                if (j - 3 >= 0 && i - 3 >= 0 && input.get(i).charAt(j) == 'X' && input.get(i - 1).charAt(j - 1) == 'M' && input.get(i - 2).charAt(j - 2) == 'A' && input.get(i - 3).charAt(j - 3) == 'S') {
                    count++;
                }
                // left-down
                if (j - 3 >= 0 && i + 3 < l && input.get(i).charAt(j) == 'X' && input.get(i + 1).charAt(j - 1) == 'M' && input.get(i + 2).charAt(j - 2) == 'A' && input.get(i + 3).charAt(j - 3) == 'S') {
                    count++;
                }
            }
        }
        return count;
    }

    public static int part2(List<String> input) {
        final int l = input.size();
        final int k = input.get(0).length();
        
        int count = 0;
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < k; j++) {
                // horizontal vertical
                if ( j - 1 >= 0 && j + 1 < k && i - 1 >= 0 && i + 1 < l && 
                    (
                        (input.get(i).charAt(j - 1) == 'M' && input.get(i).charAt(j) == 'A' && input.get(i).charAt(j + 1) == 'S')
                        ||
                        (input.get(i).charAt(j - 1) == 'S' && input.get(i).charAt(j) == 'A' && input.get(i).charAt(j + 1) == 'M')
                    )
                    &&
                    (
                        (input.get(i - 1).charAt(j) == 'M' && input.get(i).charAt(j) == 'A' && input.get(i - 1).charAt(j) == 'S')
                        ||
                        (input.get(i - 1).charAt(j) == 'S' && input.get(i).charAt(j) == 'A' && input.get(i - 1).charAt(j) == 'M')
                    )
                ) count++;
                // diagonal
                if (j - 1 >= 0 && j + 1 < k && i - 1 >= 0 && i + 1 < l && 
                    (
                        (input.get(i - 1).charAt(j + 1) == 'M' && input.get(i).charAt(j) == 'A' && input.get(i + 1).charAt(j - 1) == 'S')
                        ||
                        (input.get(i - 1).charAt(j + 1) == 'S' && input.get(i).charAt(j) == 'A' && input.get(i + 1).charAt(j - 1) == 'M')
                    )
                    &&
                    (
                        (input.get(i - 1).charAt(j - 1) == 'M' && input.get(i).charAt(j) == 'A' && input.get(i + 1).charAt(j + 1) == 'S')
                        ||
                        (input.get(i - 1).charAt(j - 1) == 'S' && input.get(i).charAt(j) == 'A' && input.get(i + 1).charAt(j + 1) == 'M')
                    )
                ) count++;
            }
        }
        return count;
    }
}
