import java.io.File;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;


public class Main {
    static String instuctions[];
    public static void main(String[] args) throws Exception {
        Scanner reader = new Scanner(new File("2016/01/input.txt"));
        instuctions = reader.nextLine().split(", ");
        reader.close();
        System.out.println("2016/01:");
        System.out.println("part1: " + part1());
        System.out.println("part2: " + part2());
    }

    static int directions[][] = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };

    static String part1() {
        int dir = 0;
        int pos[] = { 0, 0 };

        for (String instuction : instuctions) {
            if (instuction.charAt(0) == 'R') {
                dir = (dir + 1) % 4;
            } else if (instuction.charAt(0) == 'L') {
                dir = dir - 1;
                if (dir == -1)
                    dir = 3;
            }
            pos[0] += directions[dir][0] * Integer.parseInt(instuction.substring(1));
            pos[1] += directions[dir][1] * Integer.parseInt(instuction.substring(1));
        }

        return Integer.toString(Math.abs(pos[0]) + Math.abs(pos[1]));
    }

    static String part2() {
        int dir = 0;

        List<Integer[]> history = new ArrayList<Integer[]>();

        Integer pos[] = { 0, 0 };
        history.add(pos.clone());
        for (String instuction : instuctions) {
            if (instuction.charAt(0) == 'R') {
                dir = (dir + 1) % 4;
            } else if (instuction.charAt(0) == 'L') {
                dir = dir - 1;
                if (dir == -1)
                    dir = 3;
            }

            for (int i = 0; i < Integer.parseInt(instuction.substring(1)); i++) {
                pos[0] += directions[dir][0];
                pos[1] += directions[dir][1];

                for (Integer[] h : history)
                    if (h[0].equals(pos[0]) && h[1].equals(pos[1]))
                        return Integer.toString(Math.abs(pos[0]) + Math.abs(pos[1]));

                history.add(pos.clone());
            }
        }
        
        return "oops";
    }
}
