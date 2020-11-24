import math
def calculateAreaOfCylinder():
    radius = int(input("Radius of cylinder: "))
    height = int(input("Height of cylinder: "))
    paralellogramArea = math.pi * (radius ** 2) * height
    print(paralellogramArea)
calculateAreaOfCylinder()

