number_input = input("Please enter the your numbers: ")
number_sum = 0
split_number_input = number_input.split(",")

for a in range(len(split_number_input)):
    number_sum += (int(split_number_input[a]))
average_number = number_sum/ len(split_number_input)

if average_number >= 5:
    print("The average is", average_number, "and it is greater than or equal to 5")
else:
    print("The average is", average_number, "and it is smaller than 5")