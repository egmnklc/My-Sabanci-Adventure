import random

password_site = input("Type in the site to generate a password: ")
password_site_capitalized = password_site.capitalize()
password_first_two = password_site_capitalized[:2]
password_last_two = password_site_capitalized[-2:]
password_strings_combined = password_last_two + password_first_two
password_site_length = len(password_site)
password_special_characters = ["!","@","#","$","%","^","&","*","("]
password_random_number = random.randint(0, len(password_special_characters) - 1)

if 5 <= len(password_site) <= 9:
    if len(password_site) == 5:
        password_final = password_strings_combined+"five"+password_special_characters[password_random_number]
        print("The generated password is: ", password_final)
    elif len(password_site) == 6:
        password_final = password_strings_combined+"six"+password_special_characters[password_random_number]
        print("The generated password is: ", password_final)
    elif len(password_site) == 7:
        password_final = password_strings_combined+"seven"+password_special_characters[password_random_number]
        print("The generated password is: ", password_final)
    elif len(password_site) == 8:
        password_final = password_strings_combined+"eight"+password_special_characters[password_random_number]
        print("The generated password is: ", password_final)
    elif len(password_site) == 9:
        password_final = password_strings_combined+"nine"+password_special_characters[password_random_number]
        print("The generated password is: ", password_final)
else:
    print("Cannot generatea password")

