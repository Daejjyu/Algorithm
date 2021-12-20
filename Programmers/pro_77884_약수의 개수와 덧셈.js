function solution(left, right) {
    return Array(right - left + 1)
        .fill(0)
        .reduce((acc, _, i) =>
            parseInt(Math.sqrt(left + i)) === Math.sqrt(left + i) ?
                acc -= left + i : acc += left + i, 0
        );
}