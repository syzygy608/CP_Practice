s = input()

if len(s) < 1 or len(s) > 10000:
	print("北七")

for el in s:
	if (el < 'a' or el > 'z') and (el < '0' or el > '9'):
		print("北八")