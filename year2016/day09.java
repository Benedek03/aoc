package year2016;

import java.util.Scanner;

import common.puzzle;

public class day09 extends puzzle {
    public day09() {
        super("./inputs/2016/9.txt");
    }

    public static void main(String[] args) {
        new day09().solve();
    }

    protected String part1() {
        Scanner reader = getScanner();
        String input = "";
        while (reader.hasNextLine())
            input += reader.nextLine();

        String decompressed = "";
        int i = 0;

        while (i < input.length()) {
            if (input.substring(i).matches("\\(\\d+x\\d+\\).*")) {
                int xi = input.indexOf('x', i);
                int ci = input.indexOf(')', i);
                int a = Integer.parseInt(input.substring(i + 1, xi));
                int b = Integer.parseInt(input.substring(xi + 1, ci));

                if (ci + 1 + a > input.length())
                    a = input.length() - ci - 1;

                for (int j = 0; j < b; j++)
                    decompressed += input.substring(ci + 1, ci + 1 + a);

                i = ci + 1 + a;
            } else {
                decompressed += input.charAt(i++);
            }
        }
        return Integer.toString(decompressed.length());
    }

    protected long decompress(String input, int a, int b) {
        int i = 0;
        long decompressed = 0;
        while (i < input.length()) {
            if (input.substring(i).matches("\\(\\d+x\\d+\\).*")) {
                int xi = input.indexOf('x', i);
                int ci = input.indexOf(')', i);
                int aa = Integer.parseInt(input.substring(i + 1, xi));
                int bb = Integer.parseInt(input.substring(xi + 1, ci));

                decompressed += bb * decompress(input.substring(ci + 1, ci + 1 + aa), aa, bb);
                i = ci + 1 + aa;
            } else {
                decompressed += 1;
                i++;
            }
        }
        return decompressed;
    }

    protected String part2() {
        Scanner reader = getScanner();
        String input = "";
        while (reader.hasNextLine())
            input += reader.nextLine();

        long decompressed = decompress(input, input.length(), 1);

        return Long.toString(decompressed);
    }
}
