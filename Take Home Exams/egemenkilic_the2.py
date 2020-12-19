courses = input("Please enter the courses you have taken previously with letter grades: ")
courses_replace = courses.replace(":", ";")
courses_purified = courses_replace.split(";")
if courses.count(";") + 1 == courses.count(":"):
    taken_courses = input("Please enter the courses you have taken this semester with letter grades: ")
    taken_courses_replace = taken_courses.replace(":", ";")
    taken_courses_purified = taken_courses_replace.split(";")
    if taken_courses.count(";") + 1 == taken_courses.count(":"):
        selected_course = input("Please enter the course you want to check: ")
        if selected_course in courses_purified:
            indexof_selectedCourse_in_courses = courses_purified.index(selected_course)
            gradeOf_selectedCourse_in_courses = indexof_selectedCourse_in_courses + 1
            grade_courses = courses_purified[gradeOf_selectedCourse_in_courses].upper()
            if grade_courses == "F":
                if selected_course in taken_courses_purified:
                    indexof_selectedCourse_in_takenCourses = taken_courses_purified.index(selected_course)
                    gradeOf_selectedCourse_in_takenCourses = indexof_selectedCourse_in_takenCourses + 1
                    grade_takenCourses = taken_courses_purified[gradeOf_selectedCourse_in_takenCourses].upper()
                    if grade_takenCourses == "F":
                        print("Your grade for", selected_course, "is F.")
                    elif grade_takenCourses == "U":
                        print("Letter grade will be U.")
                    elif grade_takenCourses != "F":
                        print("Your grade for", selected_course, "is F.")
                    else:
                        print("Invalid input")
                elif selected_course not in taken_courses_purified:
                     print("Your grade for", selected_course, "is U.")
                else:
                    print("Invalid input")
            elif courses_purified[gradeOf_selectedCourse_in_courses].upper() == "U":
                print("Your grade for", selected_course, "is", courses_purified[gradeOf_selectedCourse_in_courses].upper() + ".")
            elif selected_course in courses_purified and selected_course in taken_courses_purified:
                if taken_courses_purified[taken_courses_purified.index(selected_course) + 1].upper() == "F":
                    print("Your grade for", selected_course, "is", taken_courses_purified[taken_courses_purified.index(selected_course) + 1].upper() + ".")
                elif grade_courses != "F" and taken_courses_purified[taken_courses_purified.index(selected_course) + 1].upper() != "F":
                    print("You can choose between S and", taken_courses_purified[taken_courses_purified.index(selected_course) + 1].upper(), "for", selected_course + ".")
                else:
                    print("Invalid input")
            elif selected_course in courses_purified and selected_course not in taken_courses_purified:
                if grade_courses != "F":
                    print("Your grade for", selected_course, "is", grade_courses + ".")
            else:
                print("Invalid input")
        elif selected_course not in taken_courses_purified and selected_course not in courses_purified:
            print("You didn't take", selected_course, "this semester.")
        elif selected_course not in courses_purified and selected_course in taken_courses_purified and taken_courses_purified[taken_courses_purified.index(selected_course) + 1].upper() == "F":
            print("Your grade for", selected_course, "is U.")
        elif selected_course in taken_courses_purified and selected_course not in courses_purified:
            if taken_courses_purified[taken_courses_purified.index(selected_course) + 1].upper() != "F":
                print("Your grade for", selected_course, "is", taken_courses_purified[taken_courses_purified.index(selected_course) + 1].upper() + ".")
        else:
            print("Invalid input")
    else:
        print("Invalid input")
else:
    print("Invalid input")