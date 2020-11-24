def abundantNumberCalculator():
    number = int(input("Type in a positive integer: "))
    b = number
    myList = []
    numbersCanDivide = [1]
    numbersCannotDivide = []
    a = -1
    for i in range(1, number):
        number -= 1
        myList.append(number)
        a += 1
        if(len(myList) > 1):
            if(b % myList[a-1]  == 0):
                numbersCanDivide.append(myList[a-1])
            elif(b % myList[a-1] != 0):
                numbersCannotDivide.append(myList[a-1])
    print("Proper dividors of " + str(b) + " are: " + str(numbersCanDivide))
    print("Improper dividors of " + str(b) + " are: " + str(numbersCannotDivide))
    sumValue = 1
    for i in range(1, len(numbersCanDivide)):
        sumValue += numbersCanDivide[i]
    if (sumValue > b):
        print(str(b) + "is an abundant value.")
    elif (sumValue < b):
        print(str(b) + "is not an abundant value.")

try:
    abundantNumberCalculator()
except Exception as err:
    print("Following error has occurred: " + err)
