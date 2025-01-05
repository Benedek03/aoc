set positional-arguments
set dotenv-load

default:
  @just --list

run-cpp year day:
  g++ $1/$2/main.cpp -o main && ./main

run-java year day:
  javac $1/$2/Main.java -d . && java Main