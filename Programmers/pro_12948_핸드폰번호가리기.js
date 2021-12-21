function solution(phone_number) {
    return phone_number.slice(-4).padStart(phone_number.length, '*');
}