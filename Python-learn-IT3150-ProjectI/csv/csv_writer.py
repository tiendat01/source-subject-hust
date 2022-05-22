import csv

# header = ['name', 'area', 'id', 'country_code']
# data = [
#     ['Afghanistan', 652090, 'AF', 'AFG'],
#     ['Algeria', 2381741, 'DZ', 'DZA'],
#     ['Ameriacan Samoa', 199, 'AS', 'ASM'],
#     ['Andora', 468, 'AD', 'AND'],
#     ['Angola', 1246700, 'AO', 'AGO']
# ]
# with open('countries.csv', 'w', encoding='utf-8', newline='') as file:
#     csv_writer = csv.writer(file)
#     csv_writer.writerow(header)
#     csv_writer.writerow(data[0])
#     csv_writer.writerows(data[1:])

fieldnames = ['name', 'area', 'id', 'country_code']
# dict có key tương ứng với fieldnames
list_dict = [
    {
        'name': 'Albania',
        'area': 28748,
        'id': 'AL',
        'country_code': 'ALB'
    },
    {
        'name': 'Algeria',
        'area': 2381741,
        'id': 'DZ',
        'country_code': 'DZA' 
    },
    {
        'name': 'American Samoa',
        'area': 199,
        'id': 'AS',
        'country_code': 'ASM'
    }
]

with open('countries.csv', 'w', encoding='utf-8', newline='') as file:
    csv_writer_dict = csv.DictWriter(file, fieldnames=fieldnames)
    csv_writer_dict.writeheader()
    csv_writer_dict.writerows(list_dict)