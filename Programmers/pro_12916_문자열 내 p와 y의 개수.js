function solution(s) {
    return s.match(/p/ig).length == s.match(/y/ig).length;
}