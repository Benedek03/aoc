package year2016;

import java.util.Scanner;

import common.puzzle;

public class day08 extends puzzle {
    public day08() {
        super("./inputs/2016/8.txt");
    }

    public static void main(String[] args) {
        new day08().solve();
    }

    boolean[][] screen = new boolean[6][50];

    protected String part1() {
        Scanner reader = getScanner();

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

    protected String part2() {
        String result = "\n";
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 50; j++) {
                if (screen[i][j])
                    result += "#";
                else
                    result += ".";
            }
            result += "\n";
        }
        return result;
    }
}
