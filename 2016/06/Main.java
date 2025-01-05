import java.io.File;
import java.util.Scanner;

public class Main {
    static Scanner reader;
    public static void main(String[] args) throws Exception {
        System.out.println("2016/06:");
        reader = new Scanner(new File("2016/06/input.txt"));
        System.out.println("part1: " + part1());
        reader.close();
        reader = new Scanner(new File("2016/06/input.txt"));
        System.out.println("part2: " + part2());
        reader.close();
    }

    static String part1() {
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

    static String part2() {
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