# in Excel, CONCATENATE(A1,","), CONCATENATE("'",D1,"',")
import os.path

list1 = [1753,
         1916,
         1504,
         4485,
         1238,
         1261,
         10473,
         2211,
         16681,
         5719,
         1162,
         10217]

list2 = ['최단경로',
         '최소비용 구하기',
         '특정한 최단 경로',
         '녹색 옷 입은 애가 젤다지',
         '파티',
         '알고스팟',
         '인간 대포',
         '네트워크 복구',
         '등산',
         '거의 최단 경로',
         '도로포장',
         'KCM Travel',
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
