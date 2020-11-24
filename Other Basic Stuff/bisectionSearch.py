lower_boundary = int(input("Select a lower boundary: "))
upper_boundary = int(input("Select an upper boundary: "))
guess_counter = 0
set_boundary = [lower_boundary,upper_boundary]
epsilon = .1
arithmetic_mean = (lower_boundary + upper_boundary) / 2
test = []


while arithmetic_mean >= epsilon:
    arithmetic_mean = (lower_boundary + upper_boundary) / 2
    ask_if_smaller = input("Is the selected number greater than " + str(arithmetic_mean) + ", y , n or e?")
    if ask_if_smaller == "y":
        lower_boundary = arithmetic_mean
        guess_counter += 1
        test.append(arithmetic_mean)
        if abs(test[-1] - arithmetic_mean) <= epsilon:
            print("Number of guesses = " + str(guess_counter))
    elif ask_if_smaller == "n":
        upper_boundary = arithmetic_mean
        guess_counter += 1
        test.append(arithmetic_mean)
        if abs(test[-1] - arithmetic_mean) <= epsilon:
            print("Number of guesses = " + str(guess_counter))
            print("")
    elif ask_if_smaller == "e":
        print("The number is equal to: " + str(arithmetic_mean))
        print("Number of guesses = " + str(guess_counter))

    else:
        print("Unknown error has occurred, returning to program.")
