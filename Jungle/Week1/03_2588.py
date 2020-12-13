a = int(input())
b = int(input())

print(a*(b % 10), a*(int(b % 100 / 10)), a*(int(b/100)), a*b, sep='\n')
