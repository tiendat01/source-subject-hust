def power(x, n):
    return 1 if n == 0 else power(x, n-1) * x
    
def main():
    x = 2
    n = 3
    print(f'x^n = {power(x, n)}')
    
main()