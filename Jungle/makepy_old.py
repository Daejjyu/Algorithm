# in Excel, CONCATENATE(A1,","), CONCATENATE("'",D1,"',")
import os.path

list1 = [2557,
         10869,
         2588,
         9498,
         2753,
         1085,
         2739,
         10950,
         2438,
         10871,
         2562,
         8958,
         4344,
         2577,
         15596,
         11654,
         2675,
         1152,
         2908,
         9249,
         2869,
         1978,
         9020,
         1065,
         2628,
         10872,
         1914,
         9663,
         1074,
         2750,
         2751,
         10989,
         1181,
         2309,
         10819,
         10971,
         2468,

         ]

list2 = ['Hello World',
         '사칙연산',
         '곱셈',
         '시험 성적',
         '윤년',
         '직사각형에서 탈출',
         '구구단',
         'A+B - 3',
         '별 찍기 - 1',
         'X보다 작은 수',
         '최댓값',
         'OX퀴즈',
         '평균은 넘겠지',
         '숫자의 개수',
         '정수 N개의 합',
         '아스키 코드',
         '문자열 반복',
         '단어의 개수',
         '상수',
         '최장 공통 부분 문자열',
         '달팽이는 올라가고 싶다',
         '소수 찾기',
         '골드바흐의 추측',
         '한수',
         '종이자르기',
         '팩토리얼',
         '하노이 탑',
         'N-Queen',
         'Z',
         '수 정렬하기',
         '수 정렬하기 2',
         '수 정렬하기 3',
         '단어 정렬',
         '일곱 난쟁이',
         '차이를 최대로',
         '외판원 순회 2',
         '안전 영역',
         ]

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
