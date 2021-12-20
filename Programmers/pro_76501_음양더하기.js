function solution(absolutes, signs) {
    return signs.reduce((a, v, i) => v ? a += absolutes[i] : a -= absolutes[i], 0);
}