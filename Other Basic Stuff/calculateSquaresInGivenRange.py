import math

def calculateSquaresInGivenRange():
    givenList = int(input("Type in a positive integer: "))
    n = givenList
    calculation = ((n * (n+1) / 2) ** 2) - (n * ((2*n)+1) * (n+1) / 6)
    print(calculation)
calculateSquaresInGivenRange()