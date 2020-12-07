numbers = input("Please enter a number list: ")
numbers_split = numbers.split(",")
swapped = True
while swapped:
    swapped = False
    for i in range(len(numbers_split)-1):
        if int(numbers_split[i]) > int(numbers_split[i+1]):
            numbers_split[i], numbers_split[i+1] = numbers_split[i+1], numbers_split[i]
            swapped = True

if int(numbers_split[0]) % 5 == 0:
    print(numbers_split[0], "is divisible by 5.")
else:
    print(numbers_split[0], "is not divisible by 5.")