# 3. Viết chương trình sao chép nội dung tệp mã nguồn
# chương trình C có tên là file_1.c sang tệp có tên là file_2.c

import os
path = os.path.abspath(__file__)
curdir = os.path.dirname(path)

def main():
    f1 = open(curdir+'\\file1.c', 'r')
    f2 = open(curdir+'\\file2.c', 'w')
    bigstr = f1.read()
    f2.write(bigstr)
    f1.close()
    f2.close()

main()