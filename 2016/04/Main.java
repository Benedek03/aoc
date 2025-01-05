import java.util.Comparator;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
import java.util.stream.Collectors;
import java.io.File;

public class Main {
    static Scanner reader;
    public static void main(String[] args) throws Exception {
        System.out.println("2016/04:");
        reader = new Scanner(new File("2016/04/input.txt"));
        System.out.println("part1: " + part1());
        reader.close();
        reader = new Scanner(new File("2016/04/input.txt"));
        System.out.println("part2: " + part2());
        reader.close();
    }

    static String part1() {
        int sum = 0;
        while (reader.hasNextLine()) {
            String line = reader.nextLine();

            int index = 0;

            Map<Character, Integer> m = new HashMap<Character, Integer>();

            while (!Character.isDigit(line.charAt(index))) {
                Character c = line.charAt(index);
                if (c == '-') {
                    index++;
                    continue;
                }

                if (m.get(c) == null) {
                    m.put(c, 1);
                } else {
                    m.merge(c, 1, Integer::sum);
                }
                index++;
            }
            Object[] list = m.entrySet().stream().sorted(Map.Entry.comparingByKey())
                    .sorted(Map.Entry.comparingByValue(Comparator.reverseOrder())).map(e -> e.getKey())
                    .collect(Collectors.toList()).toArray();
            String validName = "";
            for (int i = 0; i < 5; i++) {
                validName += list[i];
            }

            String str[] = line.substring(index).split("\\[");
            if (str[1].substring(0, 5).equals(validName))
                sum += Integer.parseInt(str[0]);
        }
        return Integer.toString(sum);
    }

    static char shiftletter(int c, int s) {
        c += s % 26;
        if (c < 'a')
            c += 26;
        else if (c > 'z')
            c -= 26;
        return (char) c;
    }

    static String part2() {
        while (reader.hasNextLine()) {
            String line = reader.nextLine();

            int index = 0;

            Map<Character, Integer> m = new HashMap<Character, Integer>();

            while (!Character.isDigit(line.charAt(index))) {
                Character c = line.charAt(index);
                if (c == '-') {
                    index++;
                    continue;
                }

                if (m.get(c) == null) {
                    m.put(c, 1);
                } else {
                    m.merge(c, 1, Integer::sum);
                }
                index++;
            }
            Object[] list = m.entrySet().stream().sorted(Map.Entry.comparingByKey())
                    .sorted(Map.Entry.comparingByValue(Comparator.reverseOrder())).map(e -> e.getKey())
                    .collect(Collectors.toList()).toArray();
            String validName = "";
            for (int i = 0; i < 5; i++) {
                validName += list[i];
            }

            String str[] = line.substring(index).split("\\[");
            if (str[1].substring(0, 5).equals(validName)) {
                String decrypted = "";
                int shift = Integer.parseInt(str[0]);
                for (char c : line.substring(0, index - 1).toCharArray()) {
                    if (c == '-')
                        decrypted += ' ';
                    else
                        decrypted += shiftletter(c, shift);
                }
                if (decrypted.equals("northpole object storage")) {
                    return str[0];
                }
            }
        }
        return "TODO";
    }
}