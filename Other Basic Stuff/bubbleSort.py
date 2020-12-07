numbers = input("Please enter a number list: ")
numbers_split = numbers.split(",")
swapped = True
while swapped:
    swapped = False
    for i in range(len(numbers_split)-1):
        if int(numbers_split[i]) > int(numbers_split[i+1]):
            numbers_split[i], numbers_split[i+1] = numbers_split[i+1], numbers_split[i]
            swapped = True

diff = int(numbers_split[0]) - int(numbers_split[-1])

if diff % 2 == 0:
    print("The difference is an even value")
else:
    print("The difference is an odd value")