class Employee:
    def __init__(self, name, base_pay, bonus) -> None:
        self.name = name
        self.bonus = bonus
        self.base_pay = base_pay
    def get_pay(self):
        return self.base_pay

class SalesEmployee(Employee):
    def __init__(self, name, base_pay, bonus, sales_incentive):
        super().__init__(name, base_pay, bonus)
        self.sales_incentive = sales_incentive
    def get_pay(self):
        return super().base_pay + self.sales_incentive


john = SalesEmployee('John', 5000,0, 1500)
print(john.get_pay()) # 6500
