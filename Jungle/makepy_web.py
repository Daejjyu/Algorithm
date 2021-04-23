###########################
# Instruction
###########################
# 백준 문제집 URL을 웹스크래핑하여 빈 파일을 만들어 주는 코드
# 1. selenium, bs4 패키지 설치하고
# 2. 크롬 드라이버 설치해야함
#  - <https://sites.google.com/a/chromium.org/chromedriver/downloads>에서 자기 크롬 버전에 맞는 실행파일 다운
#  - 크롬 브라우저에서 [더보기 -> 도움말 -> 크롬 정보] 에서 버전 확인 가능
# 기능: 언어는 옵션으로 추가 가능함, 중복 파일 만드는 것 방지해놨음

print('*' * 50)
print('@ 요구 사항')
print('1. 백준 문제집이 공개되어 있어야 합니다')
print('2. 패키지가 설치되어 있어야 합니다')
print('3. 크롬 드라이버가 설치되어 있어야 합니다')
print('\n - 자세한 것은 코드 참조')
print('*' * 50)
print()

###########################
# Import
###########################
# pip install selenium
# pip install bs4
# pip install lxml
import sys
import os.path
import time
from selenium import webdriver
from bs4 import BeautifulSoup

###########################
# Input
###########################
url = str(input('백준 문제집 URL을 입력하세요: '))
folder_name = str(input('폴더명을 입력해주세요: '))
not_allowed_char = ['\\', '/', ':', '*', '?', '"', '<', '>', '|']
for i in folder_name:
    if i in not_allowed_char:
        print('[alert]: \, /, :, *, ?, ", <, >, | 는 폴더 이름으로 사용될 수 없습니다')
        sys.exit()
path = str(os.getcwd()) + '\\' + folder_name
print('파일이 생성될 경로: %s' % (path))
response2 = str(input('만들고 싶은 경로가 맞습니까? (Yes : 0, No : 1) : '))
if (response2 != '0'):
    print('[alert]: 파이썬 코드를 원하는 경로에서 실행시켜 주세요')
    sys.exit()

###########################
# launch driver and get url
###########################
print('만드는 중..')
# 크롬 드라이버 경로 넣기
driver = webdriver.Chrome(executable_path="D:\\Hyun\\Daejjyu\\Baekjoon\\Jungle\\chromedriver.exe")
driver.maximize_window()
driver.get(url)
time.sleep(3)

#################
# web scrapping
#################
print('..........')
html = driver.page_source
soup = BeautifulSoup(html, features="html.parser")

problem = soup.find("tbody").find_all("tr")

driver.close()

p_num = []
p_name = []

for i in range(len(problem)):
    p_num.append(problem[i].td.text)
    p_name.append(problem[i].a.text)

not_allowed_char = ['\\', '/', ':', '*', '?', '"', '<', '>', '|']
for i in range(len(p_name)):
    for j in not_allowed_char:
        p_name[i] = p_name[i].replace(j, '')

#################
# select language
#################
option = ['py', 'cpp']  # 쓰는 언어 없으면 option에 추가하세여
# ans1 = int(input('언어를 고르시오. (python : 0, c++ : 1) : '))
response1 = 0
lang = option[response1]


#################
# set_directory
#################
def createFolder(path):
    if not os.path.exists(path):
        os.makedirs(path)


createFolder(path)

###########################
# Make File
###########################
print('..........')
for i in range(len(p_num)):
    if (i < 9):
        file_dir = str(path + "\%s%s_%s_%s.%s" %
                       (0, i + 1, p_num[i], p_name[i], lang))
    else:
        file_dir = str(path + "\%s_%s_%s.%s" %
                       (i + 1, p_num[i], p_name[i], lang))
    if (os.path.isfile(file_dir)):  # 이미 파일이 생성되어 있으면
        print('[error] "', file_dir, '" is exist')
    else:
        if (i < 9):
            f = open(path + "\%s%s_%s_%s.%s" %
                     (0, i + 1, p_num[i], p_name[i], lang), 'w')  # 파일이 없으면
            f.write("import sys\ninput = sys.stdin.readline")
            f.close()
        else:
            f = open(path + "\%s_%s_%s.%s" %
                     (i + 1, p_num[i], p_name[i], lang), 'w')  # 파일이 없으면
            f.write("import sys\ninput = sys.stdin.readline")
            f.close()

###########################
# Success
###########################
print('..success!')
