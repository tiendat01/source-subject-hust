import csv

with open('student.csv', 'r') as file:
    csv_dict_reader = csv.DictReader(file)
    header = csv_dict_reader.fieldnames
    print(header)
    for line in csv_dict_reader:
        print(line)

with open('student.csv', 'r') as file:
    csv_reader = csv.reader(file)
    header = next(csv_reader)
    print(header)
    for data in csv_reader:
        print(data)
        
my_header = ['MSSV', 'Tên', 'Khoá học', 'Thành phố', 'Buổi']
with open('student.csv', 'r', encoding='utf-8') as file:
    csv_dict_reader = csv.DictReader(file, my_header);
    for line in csv_dict_reader:
        print(f'{line["MSSV"]}', f'{line["Tên"]}')
