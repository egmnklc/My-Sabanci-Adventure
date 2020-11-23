import re
courses = input("Please enter the courses you have taken previously with letter grades: ")
courses_purified = re.split(r'[;:]\s*', courses)
if courses.count(":") - 1 == courses.count(";"):
    taken_courses = input("Please enter the courses you have taken this semester with letter grades: ")
    taken_courses_purified = re.split(r'[;:]\s*', taken_courses)
    if taken_courses.count(":") - 1 == taken_courses.count(";"):
        selected_course = input("Please enter the course you want to check: ")
        if selected_course in courses_purified:
            selected_course_in_courses_index = courses_purified.index(selected_course)
            if selected_course not in courses_purified and selected_course in taken_courses_purified and taken_courses_purified[taken_courses_purified.index(selected_course) + 1] == "F":
                print(courses_purified[selected_course_in_courses_index + 1], "or S.")
            elif courses_purified[selected_course_in_courses_index + 1].upper() == "F":
                if selected_course not in taken_courses_purified:
                    print("Letter grade will be switched to U")
                elif selected_course in taken_courses_purified:
                    selected_course_in_taken_courses_index = taken_courses_purified.index(selected_course)
                    if courses_purified[selected_course_in_courses_index + 1].upper() == "F":
                        print("Your grade for", selected_course, "is", taken_courses_purified[taken_courses_purified.index(selected_course) + 1].upper()+"." )
                    elif taken_courses_purified[selected_course_in_taken_courses_index + 1].upper() == "F":
                        print("Your grade for", selected_course, "is", taken_courses_purified[taken_courses_purified.index(selected_course) + 1].upper()+"." )
                    else:
                        print("Invalid input")
                else:
                    print("Invalid input")
            elif selected_course in taken_courses_purified and taken_courses_purified[taken_courses_purified.index(selected_course) + 1].upper() == "F" and courses_purified[selected_course_in_courses_index + 1].upper() == "U":
                print("Your grade for", selected_course, "is U.")
            elif selected_course in taken_courses_purified and taken_courses_purified[taken_courses_purified.index(selected_course) + 1].upper() == "F":
                print("Your grade for",selected_course,"is",taken_courses_purified[taken_courses_purified.index(selected_course) + 1] + ".")
            elif selected_course in taken_courses_purified and selected_course in courses_purified and taken_courses_purified[taken_courses_purified.index(selected_course) + 1].upper() != "F":
                print("You can choose between S and", taken_courses_purified[taken_courses_purified.index(selected_course) + 1].upper(), "for", selected_course + "." )
            else:
                print("Invalid input")
        elif selected_course not in courses_purified and selected_course in taken_courses_purified and taken_courses_purified[taken_courses_purified.index(selected_course) + 1].upper() == "F":
            print("Your grade for", selected_course, "is U.")
        elif selected_course not in courses_purified and selected_course not in taken_courses_purified:
            print("You didn't take", selected_course, "this semester.")
        else:
            print("Invalid input")
    else:
        print("Invalid input")
else:
    print("Invalid input")
