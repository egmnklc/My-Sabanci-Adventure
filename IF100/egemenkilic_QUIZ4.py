numbers = input("Give me a list of numbers: ")
splittedNumbers = numbers.split(",")
sum = 0

for i in range(len(splittedNumbers)):
    sum += int(splittedNumbers[i])
average = sum / len(splittedNumbers)

if average >= 5:
    print("The average is", average, "and it is greater than or equal to 5")
elif average < 5:
    print("The average is", average, "and it is smaller than 5")
