package year2016;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

import common.puzzle;

public class day01 extends puzzle {
    public day01() {
        super("./inputs/2016/1.txt");
    }

    public static void main(String[] args) {
        new day01().solve();
    }

    int directions[][] = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };

    protected String part1() {
        Scanner reader = getScanner();

        int dir = 0;
        int pos[] = { 0, 0 };

        String instuctions[] = reader.nextLine().split(", ");

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

    protected String part2() {
        Scanner reader = getScanner();

        int dir = 0;

        String instuctions[] = reader.nextLine().split(", ");
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
