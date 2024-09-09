set positional-arguments
set dotenv-load
set shell := ["bash", "-uc"]

default:
  @just --list

input year day:
  curl -s --cookie session=$SESSION https://adventofcode.com/$1/day/$2/input > inputs/$1/$2.txt

input-all:
  for i in {2019..2023}; do \
    for j in {1..25}; do \
      just input $i $j; \
    done \
  done

run-cpp year day: 
  g++ -Wall -Werror ./$1/day$2.cpp -lcrypto -o a.out && ./a.out

run-mjs year day:
  node ./$1/day$2.mjs