import json
 
data = (1,2,3,4)
data_json = [1,2,3,4]
print(json.dumps(data))
print(json.dumps(data_json))

a = json.dumps(data)
b = json.dumps(data_json)
print(json.loads(a))
print(json.loads(b))
