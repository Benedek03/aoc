import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

public class Main {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner scanner = new Scanner(new File("2024/06/input.txt"));
        List<List<Character>> map = new ArrayList<>();
        while (scanner.hasNextLine()) {
            String line = scanner.nextLine();
            List<Character> row = new ArrayList<>();
            for (int i = 0; i < line.length(); i++) {
                row.add(line.charAt(i));
            }
            map.add(row);
        }
        scanner.close();

        System.out.println("2024/06:");
        List<List<Character>> copy = new ArrayList<>();
        for (List<Character> row : map) {
            copy.add(new ArrayList<>(row));
        }
        System.out.println("part1: " + part1(copy));
        System.out.println("part2: " + part2(map));
    }

    public enum Direction {
        UP, RIGHT, LEFT, DOWN
    }

    public static int part1(List<List<Character>> map) {
        final int height = map.size();
        final int width = map.get(0).size();

        int x = -1;
        int y = -1;
        Direction direction = Direction.UP;

        for (int i = 0; x == -1 && i < height; i++) {
            for (int j = 0; x == -1 && j < width; j++) {
                if (map.get(i).get(j) == '^') {
                    x = i;
                    y = j;
                }
            }
        }
        
        boolean done = false;
        while (!done) {
            switch (direction) {
                case UP:
                    if (x - 1 >= 0) {
                        if (map.get(x - 1).get(y) == '#') {
                            direction = Direction.RIGHT;
                        } else {
                            map.get(x).set(y, 'X');
                            x--;
                        }
                    }
                    else {
                        map.get(x).set(y, 'X');
                        done = true;
                    }
                    break;
                case DOWN:
                    if (x + 1 < height) {
                        if (map.get(x + 1).get(y) == '#') {
                            direction = Direction.LEFT;
                        } else {
                            map.get(x).set(y, 'X');
                            x++;
                        }
                    }
                    else {
                        map.get(x).set(y, 'X');
                        done = true;
                    }
                    break;
                case LEFT:
                    if (y - 1 >= 0) {
                        if (map.get(x).get(y - 1) == '#') {
                            direction = Direction.UP;
                        } else {
                            map.get(x).set(y, 'X');
                            y--;
                        }
                    }
                    else {
                        map.get(x).set(y, 'X');
                        done = true;
                    }
                    break;
                case RIGHT:
                    if (y + 1 < width) {
                        if (map.get(x).get(y + 1) == '#') {
                            direction = Direction.DOWN;
                        } else {
                            map.get(x).set(y, 'X');
                            y++;
                        }
                    }
                    else {
                        map.get(x).set(y, 'X');
                        done = true;
                    }   
                    break;
            }
        }
        
        int count = 0;
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (map.get(i).get(j) == 'X') {
                    count++;
                }
            }
        }
        return count;
    }

    private static boolean causesLoop(List<List<Character>> map, int startX, int startY, Direction startDirection) {
        int x = startX, y = startY;
        Direction direction = startDirection;
        Set<String> visited = new HashSet<>();

        while (true) {
            String state = x + "," + y + "," + direction;
            if (visited.contains(state)) {
                return true;
            }
            visited.add(state);

            switch (direction) {
                case UP:
                    if (x - 1 >= 0) {
                        if (map.get(x - 1).get(y) == '#') {
                            direction = Direction.RIGHT;
                        } else {
                            x--;
                        }
                    } else {
                        return false;
                    }
                    break;
                case RIGHT:
                    if (y + 1 < map.get(0).size()) {
                        if (map.get(x).get(y + 1) == '#') {
                            direction = Direction.DOWN;
                        } else {
                            y++;
                        }
                    } else {
                        return false;
                    }
                    break;
                case DOWN:
                    if (x + 1 < map.size()) {
                        if (map.get(x + 1).get(y) == '#') {
                            direction = Direction.LEFT;
                        } else {
                            x++;
                        }
                    } else {
                        return false;
                    }
                    break;
                case LEFT:
                    if (y - 1 >= 0) {
                        if (map.get(x).get(y - 1) == '#') {
                            direction = Direction.UP;
                        } else {
                            y--;
                        }
                    } else {
                        return false;
                    }
                    break;
            }
        }
    }

    public static int part2(List<List<Character>> map) {
        final int height = map.size();
        final int width = map.get(0).size();

        int startx = -1;
        int starty = -1;

        for (int i = 0; startx == -1 && i < height; i++) {
            for (int j = 0; startx == -1 && j < width; j++) {
                if (map.get(i).get(j) == '^') {
                    startx = i;
                    starty = j;
                }
            }
        }

        int counter = 0;
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (i == startx && j == starty) continue;
                if (map.get(i).get(j) == '#') continue;

                List<List<Character>> copy = new ArrayList<>();
                for (List<Character> row : map) {
                    copy.add(new ArrayList<>(row));
                }
                copy.get(i).set(j, '#');
                copy.get(startx).set(starty, '.');

                if (causesLoop(copy, startx, starty, Direction.UP)) {
                    counter++;
                }
            }
        }
        return counter;
    }
}
