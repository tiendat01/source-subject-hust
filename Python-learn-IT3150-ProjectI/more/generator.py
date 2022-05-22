def greeting():
    yield 0
    print('Hi!')
    yield 1
    print('How are you?')
    yield 2
    print('Are you there?')
    yield 3

messenger = greeting()
print(messenger)
result = next(messenger)
print(result)
# print(next(messenger))

