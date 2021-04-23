num = int(input())

# ans = 1

# for i in range(1, num+1):
#     ans *= i

# print(ans)


def factorial(n):
    if(n == 0):
        return 1
    return n*factorial(n-1)


print(factorial(num))
