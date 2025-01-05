import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner scanner = new Scanner(new File("2024/08/input.txt"));
        List<List<Character>> map = new ArrayList<>();
        while (scanner.hasNextLine()) {
            List<Character> row = new ArrayList<>();
            for (char c : scanner.nextLine().toCharArray()) {
                row.add(c);
            }
            map.add(row);
        }
        scanner.close();
        
        System.out.println("2024/08: ");
        System.out.println("part1: " + part1(map));
        System.out.println("part2: " + part2(map));
    }

    protected static class Pos {
        public int row;
        public int col;
        public Pos(int row, int col) {
            this.row = row;
            this.col = col;
        }

        @Override
        public String toString() {
            return "(" + row + ", " + col + ")";
        }

        @Override
        public boolean equals(Object obj) {
            if (obj == this) {
                return true;
            }
            if (obj == null || obj.getClass() != this.getClass()) {
                return false;
            }
            Pos pos = (Pos) obj;
            return pos.row == this.row && pos.col == this.col;
        }
    }

    public static int part1(List<List<Character>> map) {
        String antennaCharacters = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
        int rows = map.size();
        int cols = map.get(0).size();
        List<Pos> antinodeList = new ArrayList<>();
        for (int i = 0; i < antennaCharacters.length(); i++) {
            List<Pos> antennas = new ArrayList<>();
            for (int r = 0; r < rows; r++) {
                for (int c = 0; c < cols; c++) {
                    if (map.get(r).get(c) == antennaCharacters.charAt(i)) {
                        antennas.add(new Pos(r, c));
                    }
                }
            }
            for (int a = 0; a < antennas.size() - 1; a++) {
                for (int b = a + 1; b < antennas.size(); b++) {
                    int rowDiff = antennas.get(a).row - antennas.get(b).row;
                    int colDiff = antennas.get(a).col - antennas.get(b).col;
                    Pos antinode1 = new Pos(antennas.get(a).row + rowDiff, antennas.get(a).col + colDiff);
                    if (antinode1.row >= 0 && antinode1.row < rows && antinode1.col >= 0 && antinode1.col < cols && !antinodeList.contains(antinode1)) {
                        antinodeList.add(antinode1);
                    }
                    Pos antinode2 = new Pos(antennas.get(b).row - rowDiff, antennas.get(b).col - colDiff);
                    if (antinode2.row >= 0 && antinode2.row < rows && antinode2.col >= 0 && antinode2.col < cols && !antinodeList.contains(antinode2)) {
                        antinodeList.add(antinode2);
                    }
                }
            }
        }
        return antinodeList.size();
    }

    public static int part2(List<List<Character>> map) {
        String antennaCharacters = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
        int rows = map.size();
        int cols = map.get(0).size();
        List<Pos> antinodeList = new ArrayList<>();
        for (int i = 0; i < antennaCharacters.length(); i++) {
            List<Pos> antennas = new ArrayList<>();
            for (int r = 0; r < rows; r++) {
                for (int c = 0; c < cols; c++) {
                    if (map.get(r).get(c) == antennaCharacters.charAt(i)) {
                        antennas.add(new Pos(r, c));
                    }
                }
            }
            for (Pos pos : antennas) {
                if (!antinodeList.contains(pos)) antinodeList.add(pos);
            }
            for (int a = 0; a < antennas.size() - 1; a++) {
                for (int b = a + 1; b < antennas.size(); b++) {
                    int rowDiff = antennas.get(a).row - antennas.get(b).row;
                    int colDiff = antennas.get(a).col - antennas.get(b).col;
                    int multiplier = 1;
                    while (true) {
                        Pos antinode = new Pos(antennas.get(a).row + rowDiff * multiplier, antennas.get(a).col + colDiff * multiplier);
                        multiplier++;
                        if (antinode.row >= 0 && antinode.row < rows && antinode.col >= 0 && antinode.col < cols) {
                            if (!antinodeList.contains(antinode)) antinodeList.add(antinode);
                        } else {
                            break;
                        }
                    }
                    multiplier = 1;
                    while (true) {
                        Pos antinode = new Pos(antennas.get(b).row - rowDiff * multiplier, antennas.get(b).col - colDiff * multiplier);
                        multiplier++;
                        if (antinode.row >= 0 && antinode.row < rows && antinode.col >= 0 && antinode.col < cols) {
                            if (!antinodeList.contains(antinode)) antinodeList.add(antinode);
                        } else {
                            break;
                        }
                    }
                }
            }
        }
        return antinodeList.size();
    }
}