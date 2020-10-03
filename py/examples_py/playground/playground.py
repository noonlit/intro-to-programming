# recursive sum
def sum(list): 
	if list == []: return 0 
	
	return list[0] + sum(list[1:])

#print(sum([1, 2, 3]))

# recursive elements count
def count(list): 
	if list == []: return 0
	
	return 1 + count(list[1:])

#print(count([1, 2, 3]))

# dictionaries
dictionary = dict()
dictionary1 = {}

dictionary1["testIndex"] = "testValue"
print(dictionary1.get("testIndex", None));
