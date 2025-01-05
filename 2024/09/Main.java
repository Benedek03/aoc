import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner scanner = new Scanner(new File("2024/09/input.txt"));
        String line = scanner.nextLine();
        scanner.close();

        System.out.println("2024/09: Java");
        System.out.println("part1: " + part1(line));
        System.out.println("part2: " + part2(line));
    }

    public static long part1(String line) {
        List<Integer> disc = new ArrayList<>();

        int id = 0;
        for (int i = 0; i < line.length(); i++) {
            boolean file = i % 2 == 0;
            int length = Integer.parseInt(line.substring(i, i + 1));

            for (int j = 0; j < length; j++) disc.add(file ? id : -1);
            
            if (file) id++;
        }

        int i = 0;
        while (disc.get(i) != -1) i++;
        int j = disc.size() - 1;
        while (disc.get(j) == -1) j--;

        while (i < j) {
            if (disc.get(i) == -1 && disc.get(j) != -1) {
                disc.set(i, disc.get(j));
                disc.set(j, -1);
                i++;
                j--;
            } else if (disc.get(i) != -1) i++;
            else if (disc.get(j) == -1) j--;
        }
        
        long res = 0;
        int k = 0;
        while (disc.get(k) != -1) {
            res += k * disc.get(k);
            k++;
        }
        return res;
    }

    protected static class Space {
        public int id;
        public int length;
        public Space(int id, int length) {
            this.id = id;
            this.length = length;
        }
    }

    public static long part2(String line) {
        List<Space> disc = new ArrayList<>();
        int id = 0;
        for (int i = 0; i < line.length(); i++) {
            boolean file = i % 2 == 0;
            int length = Integer.parseInt(line.substring(i, i + 1));

            if (length != 0) disc.add(new Space((file ? id : -1), length));
            
            if (file) id++;
        }
        id--;

        while (id > -1) {
            int i = disc.size() - 1;
            while (disc.get(i).id != id) i--;

            int j = 0;
            while (true) {
                if (disc.get(j).id == -1 && disc.get(j).length >= disc.get(i).length) {
                    int diff = disc.get(j).length - disc.get(i).length;
                    disc.get(j).length = diff;
                    Space space = disc.remove(i);
                    disc.add(j, space);
                    disc.add(i + 1, new Space(-1, space.length));
                    break;
                } else if (j >= i) {
                    break;
                }
                j++;
            }
            id--;
        }
        long res = 0;
        int index = 0;
        for (Space space : disc) {
            for (int i = 0; i < space.length; i++) {
                if (space.id != -1) {
                    res += space.id * index;
                }
                index++;
            }
        }
        return res;
    }

    
}
