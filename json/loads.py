import json
 
data = {'name':'nanbei', 'age':18}
print(json.dumps(data))
a = json.dumps(data)
print(json.loads(a))
