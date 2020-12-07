def checkIntegerType():
    userInput = int(input("Type in any integer: "))
    if (userInput > 0):
        print(str(userInput) + " is a positive number")
        checkIntegerType()
    elif(userInput < 0):
        print(str(userInput) + " is a negative number")
        checkIntegerType()
    elif (userInput == 0):
        print(str(userInput) + " is equal to 0.")
        checkIntegerType()
    else:
        print("Some error eccored, returning back to program.")
        checkIntegerType()

try:
    checkIntegerType()
except ValueError as error:
    print("An error has occurred: " + error + ". Returning back to program")
    checkIntegerType()
