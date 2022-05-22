# #include <stdio.h>
# int main()
# {
# int i;
# for (i = 1; i <= 10; i++)
# {
# if (i == 5) continue;
# printf(“%5d”, i);
# if (i == 7) break;
# }
# return 0;
# }

def main():
    for i in range(1, 11):
        if i == 5: continue
        print(f'{i:5d}', end='')
        if i == 7: break
main()