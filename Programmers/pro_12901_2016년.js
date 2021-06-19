function solution(a, b) {
    const dayArr = ["THU", "FRI", "SAT", "SUN", "MON", "TUE", "WED"]
    const MonthArr = [0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
    let daySum = b
    while (a--) {
        daySum += MonthArr[a]
    }
    return dayArr[daySum % 7];
}