package year2016;

import java.security.*;
import java.util.Scanner;
import java.math.BigInteger;

import common.puzzle;

public class day05 extends puzzle {
    public day05() {
        super("./inputs/2016/5.txt");
    }

    public static void main(String[] args) {
        new day05().solve();
    }

    protected String part1() {
        Scanner reader = getScanner();
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

    protected String part2() {
        Scanner reader = getScanner();
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