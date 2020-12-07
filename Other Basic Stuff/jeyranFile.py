words_splitted = input("Give me some words: ")
words = words_splitted.split(",")
counter = 0
for i in range(len(words)):
    if words[i-1].isalpha() == True:
        counter += 1
print(counter)