# với mutable obj được truyền vào:
# tham chiếu được sao chép và truyền vào hàm:
def func(ls: list):
    ls.append(1) # ls vẫn trỏ tới đối tượng ban đầu
    # ls = [0] # trỏ tới một list khác

ls = [1,2,3]
func(ls)
print(ls)