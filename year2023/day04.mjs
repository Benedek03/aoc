import { readFileSync } from 'fs';

const part1 = (f) => {
    let sum = 0;
    for (let i = 0; i < f.length; i++) {
        const element = f[i];
        let p = 0;
        for (let j = 0; j < element[1][0].length; j++) {
            const e = element[1][0][j];
            if(element[1][1].includes(e)) p += 1;
        }
        if (p > 0) sum += Math.pow(2, p - 1);
    }
    return sum;
}

const part2 = (f) => {
    let matching = []
    for (let i = 0; i < f.length; i++) {
        const element = f[i];
        let p = 0;
        for (let j = 0; j < element[1][0].length; j++) {
            const e = element[1][0][j];
            if(element[1][1].includes(e)) p += 1;
        }
        matching.push(p);
    }
    let instances = [];
    for (let i = 0; i < matching.length; i++) {
        instances.push(1);
    }
    let sum = 0;
    for (let i = 0; i < instances.length; i++) {
        for (let j = 0; j < matching[i]; j++) {
            instances[i + 1 + j] += instances[i];
        }
        sum += instances[i];
    }
    return sum;
}

let file = readFileSync('./inputs/2023/4.txt').toString().slice(0, -1).replace(/\s\s+/g, ' ').split('\n')
    .map(x => x.replace('Card ', ''))
    .map(x => x.split(': '));

for (let i = 0; i < file.length; i++) {
    const element = file[i];
    element[1] = element[1].split(' | ');
    element[1][0] = element[1][0].split(' ').map(x => parseInt(x));
    element[1][1] = element[1][1].split(' ').map(x => parseInt(x));
}

console.log(`part1: ${part1(file)}`);
console.log(`part2: ${part2(file)}`);