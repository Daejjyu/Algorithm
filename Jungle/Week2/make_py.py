# in Excel, CONCATENATE(A1,",")
import os.path
list1 = [1920,
         2805,
         2110,
         2470,
         11053,
         8983,
         2630,
         1629,
         6549,
         10830,
         2261,
         10828,
         10773,
         9012,
         17608,
         2493,
         10000,
         2504,
         2812,
         18258,
         2164,
         11866,
         3190,
         11279,
         1655,
         1715,
         13334, ]

list2 = ['수 찾기',
         '나무 자르기',
         '공유기 설치',
         '두 용액',
         '가장 긴 증가하는 부분 수열',
         '사냥꾼',
         '색종이 만들기',
         '곱셈',
         '히스토그램에서 가장 큰 직사각형',
         '행렬 제곱',
         '가장 가까운 두 점',
         '스택',
         '제로',
         '괄호',
         '막대기',
         '탑',
         '원 영역',
         '괄호의 값',
         '크게 만들기',
         '큐 2',
         '카드2',
         '요세푸스 문제 0',
         '뱀',
         '최대 힙',
         '가운데를 말해요',
         '카드 정렬하기',
         '철로',
         ]

# define_type
ans1 = int(input('만들고 싶은 파일 유형(0 or 1)을 입력하세요 (Python : 0, Cpp : 1) : '))
option = ['py', 'cpp']  # 쓰는 언어 없으면 option에 추가하세여
lang = option[ans1]

# make_file
print('현재 경로: %s' % (os.getcwd()))
ans2 = int(input('만들고 싶은 경로가 맞습니까? (Yes : 0, No : 1) : '))
if(ans2 == 2):
    print('파이썬 코드를 원하는 경로에서 실행시켜 주세요')
else:
    for i in range(len(list1)):
        # file_dir = str(os.getcwd() + "\%s_%s.%s" % (i+1, list1[i], lang))
        # print(file_dir)
        # if(os.path.isfile(file_dir)):  # 이미 파일이 생성되어 있으면
        #     print('"%s_%s.%s" is exist' % (i+1, list1[i], lang))
        # else:
        if(i < 9):
            f = open("%s%s_%s_%s.%s" %
                     (0, i+1, list1[i], list2[i], lang), 'w')  # 파일이 없으면
            f.close()
        else:
            f = open("%s_%s_%s.%s" %
                     (i+1, list1[i], list2[i],  lang), 'w')  # 파일이 없으면
            f.close()
