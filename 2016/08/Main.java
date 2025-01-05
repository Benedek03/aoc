import java.io.File;
import java.util.Scanner;

public class Main {
    static Scanner reader;
    public static void main(String[] args) throws Exception {
        System.out.println("2016/08:");
        reader = new Scanner(new File("2016/08/input.txt"));
        System.out.println("part1: " + part1());
        System.out.println("part2: " + part2());
    }

    static boolean[][] screen = new boolean[6][50];

    static String part1() {
        while (reader.hasNextLine()) {
            String line = reader.nextLine();
            if (line.startsWith("rect ")) {
                String[] numbers = line.substring(5).split("x");
                int a = Integer.parseInt(numbers[0]);
                int b = Integer.parseInt(numbers[1]);

                for (int i = 0; i < b; i++) {
                    for (int j = 0; j < a; j++) {
                        screen[i][j] = true;
                    }
                }

            } else if (line.startsWith("rotate row y=")) {
                String[] numbers = line.substring(13).split(" by ");
                int a = Integer.parseInt(numbers[0]);
                int b = Integer.parseInt(numbers[1]);

                for (int i = 0; i < b; i++) {
                    boolean temp = screen[a][49];
                    for (int j = 49; j > 0; j--)
                        screen[a][j] = screen[a][j - 1];
                    screen[a][0] = temp;
                }
            } else if (line.startsWith("rotate column x=")) {
                String[] numbers = line.substring(16).split(" by ");
                int a = Integer.parseInt(numbers[0]);
                int b = Integer.parseInt(numbers[1]);

                for (int i = 0; i < b; i++) {
                    boolean temp = screen[5][a];
                    for (int j = 5; j > 0; j--)
                        screen[j][a] = screen[j - 1][a];
                    screen[0][a] = temp;
                }
            }
        }

        int counter = 0;
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 50; j++) {
                if (screen[i][j])
                    counter++;
            }
        }

        return Integer.toString(counter);
    }

    static String part2() {
        String result = "\n";
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 50; j++) {
                if (screen[i][j])
                    result += "#";
                else
                    result += " ";
            }
            result += "\n";
        }
        return result;
    }
}
