function apply(left, right){

    for(let prop in right){
        if (!right.hasOwnProperty(prop)) continue

        left[prop] = typeof(right[prop]) === "object" && typeof(left[prop]) === "object"
            ? apply(left[prop], right[prop])
            : right[prop]
    }

    return left
}

let one = {a: {b: {c: {d: 'd1', e: 'e'}}}}
let two = {a: {b: {c: {d: 'd2', f: 'f'}}}}

console.log(apply(one, two))