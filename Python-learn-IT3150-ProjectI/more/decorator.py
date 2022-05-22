# def net_price(price, tax):
#     """ calculate the net price from price and tax
#     Arguments:
#         price: the selling price
#         tax: value added tax or sale tax
#     Return
#         the net price
#     """
#     return price * (1 + tax)

# def currency(fn):
#     def wrapper(*args, **kwargs):
#         result = fn(*args, **kwargs)
#         return f'${result}'
#     return wrapper

# net_price = currency(net_price)
# print(net_price(100, 0.05))

def check(func):
    def inside(a, b):
        if b == 0:
            print("Can't deivide by 0")
            return None
        func(a, b)
    return inside

@check
def div(a, b):
    return a/b
# div = check(div)


print(div(10, 0))
