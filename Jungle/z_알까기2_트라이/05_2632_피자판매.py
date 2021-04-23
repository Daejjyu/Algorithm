# 투포인터인줄 알고 출제했으나... 그리디하게 담고 이분탐색하는 문제였다.
# 50분 소요

import sys
import bisect

def solve():
    input = sys.stdin.readline

    P = int(input())
    M,N = map(int,input().split())
    pizza_A = [int(input()) for _ in range(M)]
    pizza_B = [int(input()) for _ in range(N)]

    def make_pizza(pizza, size):
        make = [0]  # 한 피자에서만 판매할 수 있기에
        make.append(sum(pizza))  # 가장 큰 값은 전체를 파는 경우 하나
        for i in range(size):
            j = i
            sum1 = 0
            while (sum1 <= P):
                j = (j + 1) % size
                sum1 += pizza[j]
                if (sum1 > P or j == i):
                    break
                make.append(sum1)
        make.sort()
        return make

    sum_A = make_pizza(pizza_A,M)
    sum_B = make_pizza(pizza_B,N)

    ans = 0
    for i in range(len(sum_B)):
        ans += bisect.bisect_right(sum_A,P-sum_B[i],0)-bisect.bisect_left(sum_A,P-sum_B[i],0)

    print(ans)
solve()