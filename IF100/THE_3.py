# TODO, 3 inputs to get from user:
#   1. Movie names
#   2. Movies' genres
#   3. Remaining seats
#   The movie could occur multiple times in  this input
#       The program should calculate all seats for multiple names
#       Information of movies will be seperated with commas
inp = input("Please enter movie names and remaining quota: ")
rep = inp.replace(",",":")
movies = rep.split(":")
sel = input("Please enter the movie you want to watch: ")
if sel in movies:
    ticket = int(input("Please enter the number of tickets you want to buy: "))
    if movies.count(sel) > 1:
        selIndexes = []
        selTotalQuota = 0
        for selDuplicate in range(len(movies)):
            if movies[selDuplicate] == sel:
                selIndexes.append(selDuplicate)
                selTotalQuota += int(movies[selDuplicate+1])
        if selTotalQuota >= ticket:
            print("The reservation is done!")
        elif selTotalQuota < ticket:
            print(24,24,24)
    if movies.count(sel) == 1:
        selIndex = movies.index(sel)
        seatNumber = int(movies[selIndex+1])
        genre = movies[selIndex+2]
        if seatNumber >= ticket:
            print("The reservation is done!")
        elif seatNumber < ticket:
            duplicateMovies = []
            for a in range(len(movies)):
                if movies[a] == genre and movies[a-2] != sel:
                    duplicateMovies.append(movies[a-2])
                    duplicateMovies = list(dict.fromkeys(duplicateMovies))
            for m in range(len(duplicateMovies)):
                print("38 *"+ duplicateMovies[m])
            if len(duplicateMovies) == 0:
                print("There are not enough seats for", sel, "and any other movie with the genre action!")
            elif len(duplicateMovies) > 0:
                testMovies = []
                if len(movies) % 2 == 1:
                    for k in range(len(movies) + 1):
                        for l in duplicateMovies:
                            if movies[k-1] == l:
                                testMovies.extend((l, movies[k]))
                    final = []
                    for m in duplicateMovies:
                        ticket = 0
                        for i in range(len(movies)):
                            if m == movies[i]:
                                ticket += int(movies[i + 1])
                        final.extend((m, ticket))
                    print(final,54)

                elif len(movies) % 2 == 0:
                    for k in range(len(movies)):
                        for l in duplicateMovies:
                            if movies[k-1] == l:
                                testMovies.extend((l, movies[k]))
                    final = []
                    for m in duplicateMovies:
                        ticket = 0
                        for i in range(len(movies)):
                            if m == movies[i]:
                                ticket += int(movies[i + 1])
                        final.extend((m, ticket))
                    print(final,67)
if sel not in movies:
    print("There is no such movie in the theater.")