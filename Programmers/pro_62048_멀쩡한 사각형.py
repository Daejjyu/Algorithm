def gcd(w,h):
    while(h):
        r= w%h
        w=h
        h=r
    return w

def solution(w, h):
    whole = w * h;
    broken = w + h - gcd(w, h)
    return whole - broken

# https://programmers.co.kr/questions/11306
# 조동진
# 우선 w와 h가 공약수가 있다면 문제를 공약수를 나눈 w' 와 h'로 축소시킬수있습니다.
# w'와 h'가 서로소라 가정했을때 대각선은 반대쪽 코너에 도달하기전 w'-1 세로선과 h'-1 가로선을 지나고 지날때마다 새로운 정사각형이 추가됩니다. 그래서 첫 정사각형을 포함 1 + (w'-1) + (h'-1) = w' + h' - 1개의 정사각형을 지나게 되므로 공약수를 다시 곱해주면 w + h - gcd(w,h)개의 정사각형을 지나는것을 찾을수있습니다.