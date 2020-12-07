def multiplyLong():
    val_1 = int(input("Value 1: "))
    val_2 = int(input("Value 2: "))
    result = 0
    for number in range(1, val_2+1):
        result += val_1
    print(result)
    multiplyLong()
try:
    multiplyLong()
except Exception as err:
    print("The following error occurred: " + err)
    multiplyLong()

