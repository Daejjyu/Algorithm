# 33분 소요
# 윈도우 + 딕셔너리로 풀이
def solution(gems):
    key = {}

    # jem key
    jem_key_num = 0
    for i in gems:
        if (key.get(i) == None):
            key[i] = 0
            jem_key_num += 1

            # two pointer
    lo, hi, jem_cnt = 0, 0, 0
    ans_lo, ans_hi, ans_len = 0, 0, float('inf')
    while (1):
        if (lo < hi and jem_cnt == jem_key_num):
            key[gems[lo]] -= 1
            if (key[gems[lo]] == 0):
                jem_cnt -= 1
            lo += 1
        else:
            if (hi == len(gems)):
                break
            key[gems[hi]] += 1
            if (key[gems[hi]] == 1):
                jem_cnt += 1
            hi += 1
        if (jem_cnt == jem_key_num and hi - lo < ans_len):
            ans_lo = lo
            ans_hi = hi
            ans_len = hi - lo

    answer = [ans_lo + 1, ans_hi]
    return answer