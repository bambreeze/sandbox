import json
 
data = {
    'nanbei':'haha',
    'a':[1,2,3,4],
    'b':(1,2,3)
}
with open('json_test.txt','w+') as f:
    json.dump(data,f)
 
with open('json_test.txt','r+') as f:
    print(json.load(f))
