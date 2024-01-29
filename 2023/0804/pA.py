from fractions import Fraction

cal = input()
arr = cal.split()
op = ""
fraca = ""
fracb = ""
if(arr[2] == '+' or arr[2] == '*' or arr[2] == '/'):
    op = arr[2]
    print("A is a Mixed Fraction.")
    tmp = arr[1].split('/')
    a = int(tmp[0])
    b = int(tmp[1])
    t = int(arr[0]) * b + a
    fraca = str(t) + "/" + str(b)
    if(len(arr) - 3 == 2):
        tmp = arr[4].split('/')
        a = int(tmp[0])
        b = int(tmp[1])
        t = int(arr[3]) * b + a
        fracb = str(t) + "/" + str(b)
        print("B is a Mixed Fraction.")
    else:
        tmp = arr[3].split('/')
        a = int(tmp[0])
        b = int(tmp[1])
        if(a > b):
            print("B is a Improper Fraction.")
        else:
            print("B is a Proper Fraction.")
        fracb = arr[3]
    
else:
    op = arr[1]
    tmp = arr[0].split('/')
    a = int(tmp[0])
    b = int(tmp[1])
    if(a > b):
        print("A is a Improper Fraction.")
    else:
        print("A is a Proper Fraction.")
    fraca = arr[0]
    if(len(arr) - 2 == 2):
        tmp = arr[3].split('/')
        a = int(tmp[0])
        b = int(tmp[1])
        t = int(arr[2]) * b + a
        fracb = str(t) + "/" + str(b)
        print("B is a Mixed Fraction.")
    else:
        tmp = arr[2].split('/')
        a = int(tmp[0])
        b = int(tmp[1])
        if(a > b):
            print("B is a Improper Fraction.")
        else:
            print("B is a Proper Fraction.")
        fracb = arr[2]
frac1 = Fraction(fraca)
frac2 = Fraction(fracb)
if(frac1.denominator <= frac1.numerator):
    if(frac1.numerator % frac1.denominator != 0):
        print(f"{frac1.numerator//frac1.denominator} {frac1.numerator%frac1.denominator}/{frac1.denominator}", end = " ")
    else:
        print(f"{frac1.numerator//frac1.denominator}", end = " ")
else:
    print(f"{frac1.numerator}/{frac1.denominator}", end = " ")
print(op, end = " ")
if(frac2.denominator <= frac2.numerator):
    if(frac2.numerator % frac2.denominator != 0):
        print(f"{frac2.numerator//frac2.denominator} {frac2.numerator%frac2.denominator}/{frac2.denominator}")
    else:
        print(f"{frac2.numerator//frac2.denominator}")
else:
    print(f"{frac2.numerator}/{frac2.denominator}")
frac3 = Fraction(fraca)
if(op == '+'):
    frac3 = frac1 + frac2
elif(op == '*'):
    frac3 = frac1 * frac2
elif(op == '/'):
    frac3 = frac1 / frac2
if(frac3.denominator <= frac3.numerator):
    if(frac3.numerator % frac3.denominator != 0):
        print(f"{frac3.numerator//frac3.denominator} {frac3.numerator%frac3.denominator}/{frac3.denominator}")
    else:
        print(f"{frac3.numerator//frac3.denominator}")
else:
    print(f"{frac3.numerator}/{frac3.denominator}")
