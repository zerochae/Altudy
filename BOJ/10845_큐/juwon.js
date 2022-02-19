const fs = require('fs');

const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

const input = fs.readFileSync('/dev/stdin').toString().split('\n');

// const fs = require("fs");

// const input = fs.readFileSync("/dev/stdin").toString().split("\n");

class Queue{
    constructor(){
        this._arr = [];
    }
    push(p){
        this._arr.push(p)
    }
    pop(){
        return this._arr.length === 0 ? -1 : this._arr.shift()
    }
    size(){
        return this._arr.length
    }
    empty(){
        return this._arr.length === 0 ? 1 : 0
    }
    front(){
        return this._arr.length === 0 ? -1 : this._arr[0]
    }
    back(){
        return this._arr.length === 0 ? -1 : this._arr[this._arr.length-1]
    }
}

const queue = new Queue()

let cmd = []

let result = []

let temp = ''

for(let i = 1; i < input.length; i++){
    cmd = input[i].split(' ')
    if( cmd[0] === 'push' ){
        // temp = parseInt(cmd[1])
        // temp = +cmd[1]
        temp = Number(cmd[1])
    }
    
    switch (cmd[0]) {
        case 'push':
            queue.push(temp)
            break
        case 'pop':
            result.push(queue.pop())
            break
        case 'size':
            result.push(queue.size())
            break
        case 'empty':
            result.push(queue.empty())
            break
        case 'front':
            result.push(queue.front())
            break
        case 'back':
            result.push(queue.back())
            break
    }
}

console.log(result.join('\n'))