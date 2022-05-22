class Person:
    def __init__(self, first_name, last_name, age) -> None:
        self.first_name = first_name
        self.last_name = last_name
        self.age = age

    def __del__(self):
        print('__del__ method được gọi!')

    def __str__(self) -> str:
        return '__str__ được gọi: ' f'Person({self.first_name},{self.last_name},{self.age})'
    def __repr__(self) -> str:
        return '__repr__ được gọi: ' f'Person({self.first_name},{self.last_name},{self.age}'
    def __eq__(self, __o: object) -> bool:
        return isinstance(__o, Person) and self.age == __o.age
    # hash() phụ thuộc vào __eq__()
    def __hash__(self) -> int:
        return hash(self.age)
    def __bool__(self):
        if self.age < 18 or self.age > 65: return False
        return True

person = Person('John', 'Doe', 23)
print(person)
print(repr(person))
print(len(person))
print(person.__next__())
person = None # GC làm việc
del person # hoặc tự gọi