package year2016;

import java.util.Scanner;

import common.puzzle;

public class day02 extends puzzle {
    public day02() {
        super("./inputs/2016/2.txt");
    }

    public static void main(String[] args) {
        new day02().solve();
    }

    protected String part1() {
        Scanner reader = getScanner();
        char numbers[][] = {
                { '1', '2', '3' },
                { '4', '5', '6' },
                { '7', '8', '9' }
        };
        String result = "";
        int pos[] = { 1, 1 };
        while (reader.hasNextLine()) {
            String line = reader.nextLine();
            for (int i = 0; i < line.length(); i++) {
                char c = line.charAt(i);
                switch (c) {
                    case 'U':
                        if (pos[0] > 0)
                            pos[0]--;
                        break;
                    case 'D':
                        if (pos[0] < 2)
                            pos[0]++;
                        break;
                    case 'L':
                        if (pos[1] > 0)
                            pos[1]--;
                        break;
                    case 'R':
                        if (pos[1] < 2)
                            pos[1]++;
                        break;
                    default:
                        break;
                }
            }
            result += numbers[pos[0]][pos[1]];
        }
        return result;
    }

    protected String part2() {
        Scanner reader = getScanner();
        char digits[][] = {
                { 'x', 'x', 'x', 'x', 'x', 'x', 'x' },
                { 'x', 'x', 'x', '1', 'x', 'x', 'x' },
                { 'x', 'x', '2', '3', '4', 'x', 'x' },
                { 'x', '5', '6', '7', '8', '9', 'x' },
                { 'x', 'x', 'A', 'B', 'C', 'x', 'x' },
                { 'x', 'x', 'x', 'D', 'x', 'x', 'x' },
                { 'x', 'x', 'x', 'x', 'x', 'x', 'x' },
        };

        String result = "";
        int pos[] = { 3, 1 };
        while (reader.hasNextLine()) {
            String line = reader.nextLine();
            for (int i = 0; i < line.length(); i++) {
                char c = line.charAt(i);
                switch (c) {
                    case 'U':
                        if (digits[pos[0] - 1][pos[1]] != 'x')
                            pos[0]--;
                        break;
                    case 'D':
                        if (digits[pos[0] + 1][pos[1]] != 'x')
                            pos[0]++;
                        break;
                    case 'L':
                        if (digits[pos[0]][pos[1] - 1] != 'x')
                            pos[1]--;
                        break;
                    case 'R':
                        if (digits[pos[0]][pos[1] + 1] != 'x')
                            pos[1]++;
                        break;
                    default:
                        break;
                }
            }
            result += digits[pos[0]][pos[1]];
        }
        return result;
    }
}