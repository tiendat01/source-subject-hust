# class MyClass:
#     def __init__(self, a) -> None:
#         pass
#     """A simple example class"""
#     i = 12345
#     def f(self):
#         return 'hello world'

# # print(MyClass.f(MyClass))

# obj = MyClass(3)
# print(obj.f())

# print(f'{"chuỗi khác"}')

# import pprint as pp


# class Request:
#     def send(self):
#         print('Sent', self)

# http_request = Request()
# http_request.send()
# print(type(Request.send) is type(http_request.send))



import pprint


class HtmlDocument:
    version = 5
    extension = 'html'

    def __init__(self, name, contents):
        self.name = name
        self.contents = contents
blank = HtmlDocument('Blank', '')
blank.new_attr = 'Dat'
del blank.name
blank.__dict__.update({'wow': 3})
pprint.pprint(blank.__dict__)
print((blank.wow))

other = HtmlDocument('sdf', 'dsf')
pprint.pprint(other.__dict__)