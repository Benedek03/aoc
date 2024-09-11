package year2016;

import java.util.Scanner;
import java.util.HashMap;
import java.util.Map;

import common.puzzle;

public class day06 extends puzzle {
    public day06() {
        super("./inputs/2016/6.txt");
    }

    public static void main(String[] args) {
        new day06().solve();
    }

    protected String part1() {
        Scanner reader = getScanner();
        int[][] counter = new int[8][26];
        while (reader.hasNextLine()) {
            char[] line = reader.nextLine().toCharArray();
            for (int i = 0; i < line.length; i++)
                counter[i][line[i] - 'a']++;
        }
        String result = "";
        for (int[] is : counter) {
            int maxIndex = 0;
            for (int i = 0; i < is.length; i++)
                if (is[maxIndex] < is[i])
                    maxIndex = i;
            result += (char) (maxIndex + 'a');
        }
        return result;
    }

    protected String part2() {
        Scanner reader = getScanner();
        int[][] counter = new int[8][26];
        while (reader.hasNextLine()) {
            char[] line = reader.nextLine().toCharArray();
            for (int i = 0; i < line.length; i++)
                counter[i][line[i] - 'a']++;
        }
        String result = "";
        for (int[] is : counter) {
            int minIndex = 0;
            for (int i = 0; i < is.length; i++)
                if (is[minIndex] > is[i])
                    minIndex = i;
            result += (char) (minIndex + 'a');
        }
        return result;
    }
}