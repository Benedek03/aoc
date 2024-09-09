import { readFileSync } from 'fs';

const part1 = (f) => {
    let ways = [];
    for (let i = 0; i < f[0].length; i++) {
        const time = f[0][i];
        const best_distance = f[1][i];
        let w = 0;
        for (let j = 1; j < time; j++)
            if (j * (time - j) > best_distance) w++;
        ways.push(w)
    }
    let a = 1;
    for (const w of ways) a *= w;
    return a;
}

const part2 = (f) => {
    const time = f[0];
    const best_distance = f[1];
    let w = 0;
    for (let j = 1; j < time; j++)
        if (j * (time - j) > best_distance) w++;
    return w;
}

let file = readFileSync('./inputs/2023/6.txt').toString().slice(0, -1)
    .replace(/\s\s+/g, ' ')
    .split('\n');

console.log(`part1: ${part1(file.map(x => x.split(': ')[1]).map(x => x.split(' ').map(y => parseInt(y))))}`);
console.log(`part2: ${part2(file.map(x => x.split(': ')[1].replace(/\s+/g, '')).map(x => parseInt(x)))}`);