import java.security.*;
import java.util.Scanner;
import java.io.File;
import java.math.BigInteger;

public class Main {
    static Scanner reader;
    public static void main(String[] args) throws Exception {
        System.out.println("2016/05:");
        reader = new Scanner(new File("2016/05/input.txt"));
        System.out.println("part1: " + part1());
        reader.close();
        reader = new Scanner(new File("2016/05/input.txt"));
        System.out.println("part2: " + part2());
        reader.close();
    }

    static String part1() {
        String doorId = reader.nextLine();
        String result = "";
        try {
            int index = 0;
            for (int i = 0; i < 8; i++) {
                String hashtext = "";
                while (!hashtext.startsWith("00000")) {
                    MessageDigest m = MessageDigest.getInstance("MD5");
                    m.reset();
                    m.update((doorId + Integer.toString(index++)).getBytes());
                    byte[] digest = m.digest();
                    BigInteger bigInt = new BigInteger(1, digest);
                    hashtext = bigInt.toString(16);
                    while (hashtext.length() < 32)
                        hashtext = "0" + hashtext;
                }
                result += hashtext.charAt(5);
            }
        } catch (NoSuchAlgorithmException e) {
            e.printStackTrace();
        }
        return result;
    }

    static String part2() {
        String doorId = reader.nextLine();
        StringBuilder result = new StringBuilder("________");
        try {
            int index = 0;
            while (result.toString().contains("_")) {
                String hashtext = "";
                while (!hashtext.startsWith("00000")) {
                    MessageDigest m = MessageDigest.getInstance("MD5");
                    m.reset();
                    m.update((doorId + Integer.toString(index++)).getBytes());
                    byte[] digest = m.digest();
                    BigInteger bigInt = new BigInteger(1, digest);
                    hashtext = bigInt.toString(16);
                    while (hashtext.length() < 32)
                        hashtext = "0" + hashtext;
                }
                int passIndex = (int) (hashtext.charAt(5) - '0');
                if (passIndex >= 0 && passIndex <= 7 && result.charAt(passIndex) == '_')
                    result.setCharAt(passIndex, hashtext.charAt(6));
            }
        } catch (NoSuchAlgorithmException e) {
            e.printStackTrace();
        }
        return result.toString();
    }
}