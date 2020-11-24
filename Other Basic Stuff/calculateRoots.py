import math
def calculateRoots():
    print("Write in the format of ax^2+bx+c")
    d = 2
    a = int(input("Value of a: "))
    b = int(input("Value of b: "))
    c = int(input("Value of c: "))
    delta = (b ** 2) - (4 * a * c)
    firstRoot = firstRoot = (-b + math.sqrt(delta)) / (2 * a)
    secondRoot = (-b - math.sqrt(delta)) / (2 * a)
    print(delta)
    if (d == 2 & delta > 0):
        print("First root is: " + str(firstRoot))
        print("Second root is: " + str(secondRoot))
    elif (d == 2 & delta == 0 and firstRoot == secondRoot):
        print("It has 2 roots, equal in value of: " + str(firstRoot))
        calculateRoots()
    elif (d == 2 and delta < 0):
        print("No real roots were found.")
        calculateRoots()
    else:
        print("Error occurred")
        calculateRoots()
try:
    calculateRoots()
except ValueError as valueError:
    print("A value error was ocurred: ", valueError, ". Returning back to program.")
    calculateRoots()
