import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Main {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner scanner = new Scanner(new File("2024/03/input.txt"));
        StringBuilder sb = new StringBuilder();
        while (scanner.hasNextLine()) {
            sb.append(scanner.nextLine());
        }
        scanner.close();

        System.out.println("2024/03:");
        System.out.println("part1: " + part1(sb.toString()));
        System.out.println("part2: " + part2(sb.toString()));
    }

    public static int part1(String input) {
        final Pattern pattern = Pattern.compile("mul\\((\\d{1,3}),(\\d{1,3})\\)");
        final Matcher matcher = pattern.matcher(input);

        int sum = 0;
        while (matcher.find()) {
            sum += Integer.parseInt(matcher.group(1)) * Integer.parseInt(matcher.group(2));
        }
        return sum;
    }

    public static int part2(String input) {
        final Pattern pattern = Pattern.compile("do\\(\\)|don't\\(\\)|mul\\((\\d{1,3}),(\\d{1,3})\\)");
        final Matcher matcher = pattern.matcher(input);

        int sum = 0;
        boolean enabled = true;
        while (matcher.find()) {
            if (matcher.group(0).equals("do()")) {
                enabled = true;
            } else if (matcher.group(0).equals("don't()")) {
                enabled = false;
            } else if (enabled) {
                sum += Integer.parseInt(matcher.group(1)) * Integer.parseInt(matcher.group(2));
            }
        }
        return sum;
    }
}
