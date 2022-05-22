# 5. Mở một tệp văn bản, đếm xem trong văn bản đó có bao
# nhiêu kí tự, bao nhiêu từ, bao nhiêu câu

import os
path = os.path.abspath(__file__)
curdir = os.path.dirname(path)

def main():
    with open(curdir+'\\text.txt', 'r') as f:
        content = f.read()
        words = content.split()
        lines = content.split('\n')
        count_char = 0
        for word in words:
            count_char += len(word)
        print(f'Co {count_char} ky tu bo qua khoang trang')
        print(f'Co {len(words)} tu')
        print(f'Co {len(lines)} dong')
main()