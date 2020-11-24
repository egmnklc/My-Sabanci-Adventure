import math
def lengthOfArcLength():
    degree = int(input("Degree: "))
    diameter = int(input("Diameter: "))
    lengthOfArcLength = 2 * math.pi * degree * diameter / 720
    print(lengthOfArcLength)
lengthOfArcLength()