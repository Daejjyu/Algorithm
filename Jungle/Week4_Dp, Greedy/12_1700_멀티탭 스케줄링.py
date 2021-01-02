import sys


def solve():
    input = sys.stdin.readline

    N, K = map(int, input().split())
    list1 = list(map(int, input().split()))

    using = [0] * (K + 1)

    use = 0
    ans = 0
    for i in range(K):
        cur = list1[i]
        if (using[cur]):
            continue
        if (use < N):
            use += 1
            using[cur] = 1
            continue
        last, last_idx = 0, -1
        ans += 1
        for k in range(1, K + 1):  # 사용하는 것 중에 앞으로 안나오거나 제일 늦게 나오는 애를 제거
            if (using[k] == 0):  # 사용 중이 아니면
                continue
            out_cnt = 1
            for j in range(i + 1, K):
                out_cnt += 1
                if (k == list1[j]):
                    break
            if (out_cnt > last):
                last, last_idx = out_cnt, k
        using[last_idx], using[cur] = 0, 1

    print(ans)


solve()
