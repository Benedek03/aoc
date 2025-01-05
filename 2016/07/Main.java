import java.util.List;
import java.io.File;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    static Scanner reader;
    public static void main(String[] args) throws Exception {
        System.out.println("2016/07:");
        reader = new Scanner(new File("2016/07/input.txt"));
        System.out.println("part1: " + part1());
        reader.close();
        reader = new Scanner(new File("2016/07/input.txt"));
        System.out.println("part2: " + part2());
        reader.close();
    }

    static String part1() {
        int counter = 0;
        while (reader.hasNextLine()) {
            char[] line = reader.nextLine().toCharArray();
            boolean inBrackets = false;
            boolean supportsTLS = false;
            for (int i = 0; i < line.length - 3; i++) {
                if (line[i] == '[')
                    inBrackets = true;
                else if (line[i] == ']')
                    inBrackets = false;
                else if (line[i] != line[i + 1] && line[i + 1] == line[i + 2] && line[i] == line[i + 3]) {
                    if (inBrackets) {
                        supportsTLS = false;
                        break;
                    } else
                        supportsTLS = true;
                }
            }
            if (supportsTLS)
                counter++;
        }
        return Integer.toString(counter);
    }

    static String part2() {
        int counter = 0;
        while (reader.hasNextLine()) {
            char[] line = reader.nextLine().toCharArray();
            boolean supportsSSL = false;
            List<char[]> abas = new ArrayList<char[]>();
            List<char[]> babs = new ArrayList<char[]>();
            boolean inBrackets = false;
            for (int i = 0; i < line.length - 2; i++) {
                if (line[i] == '[')
                    inBrackets = true;
                else if (line[i] == ']')
                    inBrackets = false;
                else if (line[i] != line[i + 1] && line[i] == line[i + 2]) {
                    char[] cc = { line[i], line[i + 1] };
                    if (!inBrackets)
                        abas.add(cc);
                    else
                        babs.add(cc);
                }
            }
            for (int i = 0; i < abas.size(); i++)
                for (int j = 0; j < babs.size(); j++)
                    if (abas.get(i)[0] == babs.get(j)[1] && abas.get(i)[1] == babs.get(j)[0])
                        supportsSSL = true;
            if (supportsSSL)
                counter++;
        }
        return Integer.toString(counter);
    }
}
