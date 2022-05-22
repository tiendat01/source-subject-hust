# Bài 5.5 Viết chương trình đọc hai chuỗi S và T. Đếm số lần mỗi ký tự xuất hiện
# trong cả hai chuỗi.
# Chú ý: Đầu tiên xuất một chuỗi các ký tự riêng biệt trong cả hai chuỗi. Sau đó, đối
# với mỗi ký tự đó hiển thị ra số lần xuất hiện trong cả hai chuỗi.

def countc(str, c):
    count = 0
    for cs in str:
        if (cs == c): count += 1
    return count

def myFunction(c):
    return ord(c)
def main():
    s = input('Nhap chuoi s: ')
    t = input('Nhap chuoi t: ')
    setc = set() # set, items is distinct
    ls = [] # list of distinct characters
    dict = {} # dictionary
    for i in range(0, len(s)):
        setc.add(s[i])

    for c in setc:
        count_si = 0
        for j in range(0, len(t)):
            if (c == t[j]):
                count_si += 1
        if count_si > 0:
            ls.append(c)
            dict.update({c:count_si})

    ls.sort(key=myFunction)
    print(ls)
    for c in ls:
        dict[c] += countc(s, c)
    for c in ls:
        print(f'{dict[c]} ', end='')
main()        