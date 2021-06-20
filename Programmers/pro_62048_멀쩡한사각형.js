function solution(w, h) {
    let [gcd, b] = w > h ? [w, h] : [h, w]
    for (let r = 0; b > 0; r = parseInt(gcd % b), gcd = b, b = r) { }
    return w * h - gcd * ((w / gcd - 1) + (h / gcd - 1) + 1);
}