salary = int(input("Please enter your salary: "))
if 0 < salary <= 1000:
    salary += salary * .15
    print("Your raised salary is ", salary)
elif 1000 < salary <= 2000:
    salary += salary * .1
    print("Your raised salary is ", salary)
elif 2000 < salary <= 3000:
    salary += salary * .05
    print("Your raised salary is ", salary)
elif 0 < salary <= 1000:
    salary += salary * .025
    print("Your raised salary is ", salary)
