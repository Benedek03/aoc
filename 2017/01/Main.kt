import java.io.File

fun main() {
    val input = File("./2017/01/input.txt").readText()
        .toCharArray()
        .filter { it.isDigit() }
        .map { it.digitToInt() }

    println("2017/02:")

    var sum = 0;
    input.forEachIndexed { i, c -> if (c == input[(i + 1) % input.size]) sum += c }
    println("part1: $sum")

    sum = 0
    input.forEachIndexed { i, c -> if (c == input[(i + input.size / 2) % input.size]) sum += c }
    println("part2: $sum")
}