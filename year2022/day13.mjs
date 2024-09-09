import { readFileSync } from 'fs';

const compare = (left, right) => {
    if (typeof left === 'number' && typeof right === 'number')
        return (left == right) ? 0 : left > right ? 1 : -1;
    else if (typeof left !== 'number' && typeof right !== 'number')
        for (let i = 0; i < right.length + 1; i++) {
            if (typeof left[i] === 'undefined' && typeof right[i] === 'undefined') return 0;
            if (typeof left[i] === 'undefined') return -1;
            if (typeof right[i] === 'undefined') return 1;
            let s = compare(left[i], right[i]);
            if (s == 0) continue;
            return s;
        }
    else if (typeof left === 'number' && typeof right !== 'number') return compare([left], right);
    else if (typeof left !== 'number' && typeof right === 'number') return compare(left, [right]);
}

const part1 = (f) => {
    let result = 0;
    for (let i = 0; i < f.length - 1; i += 2)
        if (compare(JSON.parse(f[i]), JSON.parse(f[i + 1])) == -1) result += i / 2 + 1;
    return result;
}

const part2 = (f) => {
    f.push('[[2]]');
    f.push('[[6]]');
    f.sort((a, b) => compare(JSON.parse(a), JSON.parse(b)));

    let result = 1;
    for (let i = 0; i < f.length; i++)
        if (f[i] == '[[2]]' || f[i] == '[[6]]') result *= (i + 1);
    return result;
}

let file = readFileSync('./inputs/2022/13.txt').toString()
    .slice(0, -1)
    .replace(/\n\n/g, '\n')
    .split('\n')
    .map(x => x.replace(/\n/g, '\n'));

console.log(`part1: ${part1(file)}`);
console.log(`part2: ${part2(file)}`);