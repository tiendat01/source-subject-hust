from email import header
import pandas as pd

# header = ['Name', 'Score', 'Salary']
# data = [
#     ['Alex', 62, 80],
#     ['Brad', 45, 56],
#     ['Joey', 85, 98]
# ]

header = ['Name', 'Score', 'Salary']
data = [
    {
        'Name': 'Alex',
        'Score': 62,
        'Salary': 80
    },
    {
        'Name': 'Brad',
        'Score': 45,
        'Salary': 56
    },
    {
        'Name': 'Joey',
        'Score': 85,
        'Salary': 98
    }
]
df = pd.DataFrame(data=data, columns=header)

df.to_csv(path_or_buf='salary.csv', sep=';', header=True, index=False)