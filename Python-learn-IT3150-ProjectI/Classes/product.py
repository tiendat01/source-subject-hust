class Product:
    default_discount = 0

    def __init__(self, price):
        self.price = price
        self.discount = Product.default_discount

    def set_discount(self, discount):
        self.discount = discount

    def net_price(self):
        return self.price * (1 - self.discount)

class Test:
    x = 10
    def __init__(self):
        self.x = 20
test = Test()
print(test.x)  # 20
print(Test.x)  # 10

