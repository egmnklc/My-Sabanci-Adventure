names = ["Ali", "Veli", "Aylin"]
surnames = ["Arin", "Cirisci", "Candan"]
birth_days = [1, 22, 8]
birth_months = [1, 6, 12]
birth_years = [1984, 1994, 2001]

name = input("Name: ")
if name in names:
    if name == names[0]:
        surname = input("Surname: ")
        if surname == surnames[0]:
            birthday = input("Please enter your birthday (DD/MM/YYYY): ")
            birthday_purified = birthday.split("/")
            if birthday.count("/") == 2:
                if 1 <= int(birthday_purified[0]) <= 9 and birthday_purified[0] == str("0" + str(birth_days[0])):
                    if 1 <= int(birthday_purified[1]) <= 9 and birthday_purified[1] == str("0" + str(birth_months[0])):
                        if int(birthday_purified[2]) == birth_years[0]:
                            print("You're a customer!")
                        else:
                            print("You're not a customer!")
                    elif int(birthday_purified[1]) > 9 and birthday_purified[1] == birth_months[0]:
                        if int(birthday_purified[2]) == birth_years[0]:
                            print("You're a customer!")
                    else:
                        print("You're not a customer!")
                elif int(birthday_purified[0]) > 9 and int(birthday_purified[0]) == birth_days[0]:#day
                    if 1 <= int(birthday_purified[1]) <= 9 and birthday_purified[1] == str("0" + str(birth_months[0])):#month
                        if int(birthday_purified[2]) == birth_years[0]:#year
                            print("You're a customer!")
                        else:
                            print("You're not a customer!")
                    elif int(birthday_purified[1]) > 9 and int(birthday_purified[1]) == birth_months[0]:
                        if int(birthday_purified[2]) == birth_years[0]:#year
                            print("You're a customer!")
                        else:
                            print("You're not a customer!")
                    else:
                        print(str(birthday_purified[1]))
                else:
                    print("You're not a customer!")
            else:
                print("You're not a customer!")
        else:
            print("You're not a customer!")
if name not in names:
    print("You're not a customer!")

