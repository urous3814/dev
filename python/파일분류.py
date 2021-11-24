import os
# import glob
# import shutil

dir = input("파일을 분류할 경로를 입력하세요: ")        #경로 지정
print("경로: ", dir,'\n')

print("분류기준 선택")                          #분류기준 선택
print("a. 특정 문자의 파일 분류")
print("b. 파일의 확장자 기준 파일 분류",'\n')
a = input("분류 기준을 선택하세요: ")
print(a)
if(a == "a"):
    print("분류 시작")
    file_list = os.listdir(dir)
    text = input("분류의 기준이 될 문자 입력: ")        #분류 문자 입력

    try:
        os.makedirs(dir + "\\" + text)      #파일 만들기
    except:
        pass

    for i in range(len(file_list)):         #분류
        if(file_list[i].find(text) >= 0):
            print("분류")
            os.rename(dir + "\\" + file_list[i], dir+"\\"+text+"\\"+file_list[i])
elif(a == "b"):
    ext = list()
    print("분류 시작")
    file_list = os.listdir(dir)
    print(file_list)
    for i in range(len(file_list)):         #확장자 찾기
        if(file_list[i].find('.') <= 0):
            continue
        tmp_list = file_list[i].split('.')   
        ext.append(tmp_list[-1])

    tmp_ext = set(ext)                      #중복 제거
    ext = list(tmp_ext)
    print(ext)

    for i in range(len(ext)):     
        try:
            os.makedirs(dir + "\\" + ext[i])      #파일 만들기
        except:
            pass
        for j in range(len(file_list)):     #분류
            if(file_list[j].find(ext[i]) >= 0):
                os.rename(dir + "\\" + file_list[j], dir+"\\"+ext[i]+"\\"+file_list[j])
print("분류 끝")
