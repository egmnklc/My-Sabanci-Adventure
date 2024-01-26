# TODO: ---In ANY INVALID CASE, Program should display en error message WITHOUT MOVING FURTHER
# Using the given course name and letter grade info:
# TODO: Calculate if the student will be able to choose between S and the letter grade, or grade will be U or F
# Letter Grades: A, A-, B+, B, B-, C+, C, C-, D+, D-, F
# F is the failing grade
# Student can change Satisfactory(s) option
# Students can take a course multiple times
# TODO: Letter grade is "F"
#   If letter grade is F:
#       Course taken before:
#           If Yes:
#               Previous letter grade:
#                   If U:
#                       Letter grade = U
#                   If letter grade == any passing grade:
#                       Letter grade will be F
#                   Elif letter grade == F:
#                       Letter grade will be F
#           Elif No:
#               Letter grade = U
#   If letter grade != F:
#       Letter grade = original letter grade or S
# TODO: THE FORMAT WILL BE:
#      course1:grade1;course2:grade2;....;courseN:GradeN
#       ie: "MATH101:A-;SPS101:B;IF100:B+;HIST191:S"
# TODO: Semicolons(;) are used between course names and grades.
# TODO: The program will detect any other incorrect input.
# TODO: If numberOfColons is = 1 + numberOfSemicolons
#   Display error message and terminate.
# TODO: Letter grades are case-INSENSITIVE!
#   ASSUME THAT USER ALWAYS INPUTS A VALID GRADE
#   ASSUME THAT COURSE NAMES ONLY CONSIST OF CAPITAL LETTERS AND DIGITS
#   !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
#   SAMPLE RUNS MAY NOT CONTAIN SOME CASES
#   !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
# TODO: Check if coursename in currentCourseLIST == True
#   If False: print an appropriate error message and terminate.
#   =====================================================================
# TODO: Outputs
#   If userinput is invalid, display: "Invalid Input"
#   If coursename not in currentCourseLIST, display: "You didn't take coursename for this semester"
# TODO: If the user's grade to be displayed is F or U:
#   F: print("Your grade for coursename is F.") OR
#   U: print("Your grade for coursename is U.")
# TODO: If the user's grade is some note other than F:
#  Output will be:
#   print("You can choose between S and current_grade for coursename.")

coursesWithGradeNames = input("Please enter the courses you have taken with letter grades: ")
if coursesWithGradeNames.count(":") - 1 == coursesWithGradeNames.count(";"):
    takenCoursesWithLetterGrades = input("Please enter the courses you have taken this semester with letter grades: ")
    if takenCoursesWithLetterGrades.count(":") - 1 == takenCoursesWithLetterGrades.count(";"):
        enterCourseToCheck = input("Please enter the course you want to check: ")
        indexOfEnterCourseToCheck = takenCoursesWithLetterGrades.index(enterCourseToCheck)
        indexOfGradeToCheck = takenCoursesWithLetterGrades.index(enterCourseToCheck) + len(enterCourseToCheck) + 1
        if enterCourseToCheck in takenCoursesWithLetterGrades:
            print("Your grade for " + str(enterCourseToCheck), "is", str(takenCoursesWithLetterGrades[indexOfGradeToCheck]).upper() + ".")
        elif enterCourseToCheck in coursesWithGradeNames is False:
            print("You didn't take", enterCourseToCheck, "this semester.")
        if enterCourseToCheck in takenCoursesWithLetterGrades is True and enterCourseToCheck in coursesWithGradeNames is False:
            if takenCoursesWithLetterGrades[indexOfGradeToCheck] != "F":
                print("You can choose between S and ", takenCoursesWithLetterGrades[indexOfGradeToCheck].upper(),"for",enterCourseToCheck)
            elif takenCoursesWithLetterGrades[indexOfGradeToCheck] == "F":
                if enterCourseToCheck in takenCoursesWithLetterGrades is False:
                    print("Your grade for ", enterCourseToCheck, "is U.")
                elif enterCourseToCheck in takenCoursesWithLetterGrades:
                    if coursesWithGradeNames[indexOfGradeToCheck].upper() == "U":
                        print("Your grade for ", enterCourseToCheck, "is U.")
                    elif coursesWithGradeNames[indexOfGradeToCheck].upper() == "F" or coursesWithGradeNames[indexOfGradeToCheck].upper() != "F":
                        print("Your grade for ", enterCourseToCheck, "is F.")
    else:
        print("Invalid input")
else:
    print("Invalid Input")
