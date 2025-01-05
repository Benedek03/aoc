import java.util.Scanner;
import java.io.File;

public class Main {
    static Scanner reader;
    public static void main(String[] args) throws Exception {
        System.out.println("2016/03:");
        reader = new Scanner(new File("2016/03/input.txt"));
        System.out.println("part1: " + part1());
        reader.close();
        reader = new Scanner(new File("2016/03/input.txt"));
        System.out.println("part2: " + part2());
        reader.close();
    }

    static String part1() {
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

    static String part2() {
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