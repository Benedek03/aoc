import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class day07 {
    static class File {
        public String name;
        public int size;

        public File(String name, int size) {
            this.name = name;
            this.size = size;
        }
    }

    static class Directory {
        public String name;
        public int size;
        public Directory parent;
        public List<Directory> subDirectories = new ArrayList<Directory>();
        public List<File> files = new ArrayList<File>();

        public Directory(String name, Directory parent) {
            this.name = name;
            this.parent = parent;
            this.size = 0;
        }

        public Directory(String name) {
            this.name = name;
            this.parent = this;
            this.size = 0;
        }

        public void addSubDirectory(Directory directory) {
            this.subDirectories.add(directory);
        }

        public void addFile(File file) {
            this.files.add(file);
            this.addSize(file.size);
        }

        private void addSize(int size) {
            this.size += size;
            if (this.parent != this)
                this.parent.addSize(size);
        }
    }

    // private static void print(Directory dir, int d) {
    // for (int i = 0; i < d; i++)
    // System.out.println(" ");
    // System.out.println("- DIR " + dir.size + " " + dir.name);
    // for (var item : dir.files) {
    // for (int i = 0; i < d + 1; i++)
    // System.out.println(" ");
    // System.out.println("- FILE " + item.size + " " + item.name);
    // }
    // for (var item : dir.subDirectories) {
    // print(item, d + 1);
    // }
    // }

    static void getDirSizes(Directory dir, List<Integer> dirSizes) {
        dirSizes.add(dir.size);
        for (Directory item : dir.subDirectories) {
            getDirSizes(item, dirSizes);
        }
    }

    public static void main(String[] args) {
        Directory root = new Directory("/");
        Directory currentDirectory = root;

        try {
            java.io.File myObj = new java.io.File("./inputs/2022/7.txt");
            Scanner myReader = new Scanner(myObj);

            String[] line = myReader.nextLine().split("\\s+");
            while (myReader.hasNextLine()) {
                if (line[0].equals("$")) {
                    if (line[1].equals("cd")) {
                        if (line[2].equals("/"))
                            currentDirectory = root;
                        else if (line[2].equals(".."))
                            currentDirectory = currentDirectory.parent;
                        else {
                            for (var i : currentDirectory.subDirectories) {
                                if (i.name.equals(line[2])) {
                                    currentDirectory = i;
                                    break;
                                }
                            }
                        }
                        line = myReader.nextLine().split("\\s+");
                    } else if (line[1].equals("ls")) {
                        line = myReader.nextLine().split("\\s+");
                        while (!line[0].equals("$")) {
                            if (line[0].equals("dir"))
                                currentDirectory.addSubDirectory(new Directory(line[1], currentDirectory));
                            else
                                currentDirectory.addFile(new File(line[1], Integer.parseInt(line[0])));
                            if (!myReader.hasNextLine())
                                break;
                            line = myReader.nextLine().split("\\s+");
                        }
                    }
                }
            }

            List<Integer> dirSizes = new ArrayList<Integer>();
            getDirSizes(root, dirSizes);

            // print(root, 0);
            int sum = 0;
            for (var i : dirSizes)
                if (i <= 100000)
                    sum += i;
            System.out.println("part1: " + sum);

            int minSize = Integer.MAX_VALUE;
            for (var i : dirSizes)
                if (i >= (30000000 - (70000000 - root.size)) && minSize > i)
                    minSize = i;

            System.out.println("part 2: " + minSize);
            myReader.close();
        } catch (FileNotFoundException e) {
            System.out.println("Couldn't read the file.");
            e.printStackTrace();
        }
    }
}
