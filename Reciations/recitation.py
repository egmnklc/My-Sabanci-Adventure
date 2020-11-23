myList = [16, 1, 10, 31, 15, 11, 47, 23, 47, 3, 29, 23, 44, 27, 10, 14, 17, 15, 1, 38, 7, 7, 25, 1, 8, 15, 16, 20, 12,
          14, 6, 10, 39, 42, 33, 26, 30, 27, 25, 13, 11, 26, 39, 19, 15, 21, 22]
starting_index = int(input("Please enter the starting index: "))
if 0 <= starting_index <= len(myList):
    stopping_index = int(input("Please enter the stopping index: "))
    if 0 <= stopping_index <= len(myList):
        step_size = int(input("Please enter the step size: "))
        if 0 < step_size:
            sub_list = myList[starting_index:stopping_index:step_size]
            print("The summation of the elements of ", myList[starting_index:stopping_index:step_size], "is", sum(myList[starting_index:stopping_index:step_size]) + ".")
    else:
        print("Invalid stopping value!")
else:
    print("Invalid starting value!")
