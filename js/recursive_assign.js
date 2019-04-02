function isObject (value) {
    return value && typeof value === 'object' && value.constructor === Object;
}

function assign(left, right){

    for(let prop in right){
        if (!right.hasOwnProperty(prop)) continue

        left[prop] = isObject(right[prop]) && isObject(left[prop])
            ? assign(left[prop], right[prop])
            : right[prop]
    }

    return left
}

let one = {a: {b: {c: {d: 'd1', e: 'e'}}}}
let two = {a: {b: {c: {d: 'd2', f: 'f'}}}}

console.log(assign(one, two))
