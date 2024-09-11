package common;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public abstract class puzzle {
    private String fileName;

    protected puzzle(String fn) {
        this.fileName = fn;
    }

    protected Scanner getScanner() {
        try {
            return new Scanner(new File(fileName));
        } catch (FileNotFoundException e) {
            System.err.println("Couldn't open file.");
            e.printStackTrace();
            return null;
        }
    }

    protected abstract String part1();

    protected abstract String part2();

    protected void solve() {
        System.out.println("==========");
        System.out.println("part1: " + part1());
        System.out.println("part2: " + part2());
    }
}
