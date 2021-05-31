import pandas as pd

ss = pd.Series(data=list('xyz'), index=list('abc'), name='name')
print(ss, type(ss))
print(ss.values, type(ss.values))

#pd.DataFrame(
#df = pd.read_csv("../data/house.cs
