
class thi_sinh:
    def __init__(self):
        self.SBD = []
        self.ho_va_ten = []
        self.ketqua = self.diem_thi(10,10,10) # inner class/struct
    class diem_thi():
        def __init__(self, dToan, dLy, dHoa):
            self.dToan = dToan
            self.dLy = dLy
            self.dHoa = dHoa
        def display(self):
            print(f'Diem mon Toan: {self.dToan:<5} \
Diem mon Ly: {self.dLy} \
    Diem mon Hoa: {self.dHoa}')
        
def main():
    ts = thi_sinh()
    diem = ts.ketqua
    diem.display()

main()