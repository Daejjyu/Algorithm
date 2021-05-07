#"이 과정은 사실 어떤 자연수 n이 소수임을 판정하기 위해서 |√n|까지만 진행하면 되는데[1] , 수가 수를 나누기 위해서는 그 몫이 항상 필요하며 나누는 수와 몫 중 어느 하나는 반드시 √n 이하이기 때문이다." (Wiki에 있는 설명입니다.)
def isPrime(number):
    
    if number <= 1:
        return False
    else:
        for i in range(2, number // 2 + 1):
            if number % i == 0:
                return False
        return True
    
primeSet = set()
def makeCombinations(str1, str2):
    if str1 != "":
        if isPrime(int(str1)):
            primeSet.add(int(str1))

    for i in range(len(str2)):
        makeCombinations(str1 + str2[i], str2[:i] + str2[i + 1:])

def solution(numbers):
    makeCombinations("", numbers)

    answer = len(primeSet)

    return answer