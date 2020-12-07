def calculateArmstrongNumber():
    question = input("Type in a number: ")
    a = int(question[0])
    b = int(question[1])
    c = int(question[2])
    d = int(question[3])
    number = a*1000+b*100+c*10+d
    armstrongNumber = a ** 4 + b ** 4 + c ** 4 + d ** 4
    print(armstrongNumber)
calculateArmstrongNumber()
