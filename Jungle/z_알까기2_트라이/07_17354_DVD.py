# input 부터 받고 생각. 딕셔너리에 리스트 넣는 것이 생각처럼 잘 안되서 50분 걸렸다
import sys

input = sys.stdin.readline

w,h,W,H = map(int,input().split())
dvd_x,dvd_y = map(int,input().split())
dvd_dx , dvd_dy = map(int,input().split())

# 왼쪽 위 x==0, y==0
# 오른쪽 위 x+w==W,y==0
# 왼쪽 밑 x==0 y+h == H
# 오른쪽 밑 x+w==W,y+h ==H

# dictionary로 같은 위치에서 같은 속도 방향이라면 중단.
# 계속 loop돌기
dict = {}
time = 0

def cmp(x,y):
    global dvd_dx
    global dvd_dy
    global dvd_x
    global dvd_y
    cur_time = 0
    if(x>y):# go to Y
        cur_time = y
        dvd_x += cur_time * dvd_dx
        dvd_y += cur_time * dvd_dy
        dvd_dy *= -1
    else:
        cur_time =x
        dvd_x += cur_time*dvd_dx
        dvd_y += cur_time*dvd_dy
        dvd_dx *= -1

    return cur_time

def check():
    global time
    global dict

    if(dict.get((dvd_x, dvd_y))!=None):
        #딕셔너리를 잘 못써서 같은 위치에서 다른 속도상황을 처리 못했는데 정답 받았다. 그런 경우가 없는 것일까?
        print(-1)
        quit()
    dict[(dvd_x, dvd_y)] = (dvd_dx,dvd_dy)
    if(( dvd_x == 0 and dvd_y ==0)or(dvd_x+w ==W and dvd_y==0)or (dvd_x==0 and dvd_y+h==H)or (dvd_x+w==W and dvd_y+h==H)):
        print(time)
        quit()

# 왼쪽 위 x==0, y==0
# 오른쪽 위 x+w==W,y==0
# 왼쪽 밑 x==0 y+h == H
# 오른쪽 밑 x+w==W,y+h ==H

while(1):
    if(dvd_dx >0 and dvd_dy >0):
        time += cmp(W - (dvd_x+w), H - (dvd_y+h))
    elif(dvd_dx >0 and dvd_dy <0):
        time += cmp(W-(dvd_x+w),dvd_y-0)
    elif(dvd_dx <0 and dvd_dy >0):
        time += cmp(dvd_x-0,H - (dvd_y+h))
    elif(dvd_dx <0 and dvd_dy <0):
        time += cmp(dvd_x-0,dvd_y-0)
    check()
