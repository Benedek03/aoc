package year2016;

import java.util.Scanner;

import common.puzzle;

public class day03 extends puzzle {
    public day03() {
        super("./inputs/2016/3.txt");
    }

    public static void main(String[] args) {
        new day03().solve();
    }

    protected String part1() {
        Scanner reader = getScanner();
        int counter = 0;
        while (reader.hasNextLine()) {
            String s[] = reader.nextLine().trim().split("\\s+");
            int a = Integer.parseInt(s[0]);
            int b = Integer.parseInt(s[1]);
            int c = Integer.parseInt(s[2]);
            if (a + b > c && a + c > b && c + b > a)
                counter++;
        }
        return Integer.toString(counter);
    }

    protected String part2() {
        Scanner reader = getScanner();
        int counter = 0;
        while (reader.hasNextLine()) {
            String s1[] = reader.nextLine().trim().split("\\s+");
            String s2[] = reader.nextLine().trim().split("\\s+");
            String s3[] = reader.nextLine().trim().split("\\s+");
            for (int i = 0; i < 3; i++) {
                int a = Integer.parseInt(s1[i]);
                int b = Integer.parseInt(s2[i]);
                int c = Integer.parseInt(s3[i]);
                if (a + b > c && a + c > b && c + b > a)
                    counter++;
            }
        }
        return Integer.toString(counter);
    }
}