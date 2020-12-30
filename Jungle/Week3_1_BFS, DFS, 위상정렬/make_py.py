# in Excel, CONCATENATE(A1,","), CONCATENATE("'",D1,"',")
import os.path

list1 = [1260,
         2606,
         2178,
         7569,
         3055,
         2294,
         1987,
         11725,
         2573,
         2617,
         2252,
         2637,
         ]

list2 = ['DFS와 BFS'
    , '바이러스'
    , '미로 탐색'
    , '토마토'
    , '탈출'
    , '동전 2'
    , '알파벳'
    , '트리의 부모 찾기'
    , '빙산'
    , '구슬 찾기'
    , '줄 세우기'
    , '장난감조립']

# define_type
ans1 = 0
option = ['py']  # 쓰는 언어 없으면 option에 추가하세여
lang = option[ans1]

# make_file
print('현재 경로: %s' % (os.getcwd()))
ans2 = int(input('만들고 싶은 경로가 맞습니까? (Yes : 0, No : 1) : '))
if (ans2 == 2):
    print('파이썬 코드를 원하는 경로에서 실행시켜 주세요')
else:
    for i in range(len(list1)):
        if (i < 9):
            file_dir = str(os.getcwd() + "\%s%s_%s_%s.%s" %
                           (0, i + 1, list1[i], list2[i], lang))
        else:
            file_dir = str(os.getcwd() + "\%s_%s_%s.%s" %
                           (i + 1, list1[i], list2[i], lang))
        if (os.path.isfile(file_dir)):  # 이미 파일이 생성되어 있으면
            print('[error] "', file_dir, '" is exist')
        else:
            if (i < 9):
                f = open("%s%s_%s_%s.%s" %
                         (0, i + 1, list1[i], list2[i], lang), 'w')  # 파일이 없으면
                f.close()
            else:
                f = open("%s_%s_%s.%s" %
                         (i + 1, list1[i], list2[i], lang), 'w')  # 파일이 없으면
                f.close()
