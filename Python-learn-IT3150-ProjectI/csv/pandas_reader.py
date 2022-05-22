import pandas as pd

# data = pd.read_csv(filepath_or_buffer='https://www.w3schools.com/python/pandas/data.csv.txt')
# print(data)
df = pd.read_csv(filepath_or_buffer='data.csv', index_col=False)
print(list(df.columns.values))
print(df.loc[0:5, 'Duration abc'])
print(df.loc[[0,5],['Duration abc', 'Maxpulse']])