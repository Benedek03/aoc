import { readFileSync } from 'fs';

const part1 = (ids, maps) => {
    let new_ids = ids.map(x => x);
    for (const map of maps) {
        for (let i = 0; i < map.length; i++) {
            const modifier = map[i];
            for (let j = 0; j < ids.length; j++) {
                if (ids[j] >= modifier[1] && ids[j] < modifier[1] + modifier[2])
                    new_ids[j] += modifier[0] - modifier[1];
            }
        }
        ids = new_ids.map(x => x);
    }

    return Math.min.apply(Math, ids);
}

const part2 = (ids, maps) => {
    return 'TODO';
}

let file = readFileSync('./inputs/2023/5.txt').toString().slice(0, -1)
    .replace(/\n\n+/g, '\n')
    .replace(/\s\s+/g, ' ')
    .split('\n');

let ids = file[0].split(': ')[1].split(' ').map(x => parseInt(x));
file.shift();
let maps = []
let i = -1;
for (let j = 0; j < file.length; j++) {
    if (file[j].endsWith('map:')) {
        i++;
        maps.push([]);
    } else {
        maps[i].push(file[j].split(' ').map(x => parseInt(x)));
    }
    
}

// console.log(ids, maps);
console.log(`part1: ${part1(ids, maps)}`);
console.log(`part2: ${part2(ids, maps)}`);