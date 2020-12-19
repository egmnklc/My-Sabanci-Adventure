inp = input("Please enter movie names and remaining quota: ")
rep = inp.replace(",", ":")
movies = rep.split(":")
sel = input("Please enter the movie you want to watch: ")
if sel in movies:
    ticket = int(input("Please enter the number of tickets you want to buy: "))
    selSeats = 0
    for i in range(len(movies)):
        if movies[i] == sel:
            selSeats += int(movies[i + 1])
    moviesWithGenres = []
    moviesWithGenresOnly = []
    for i in range(len(movies)):
        if movies[movies.index(sel) + 2] == movies[i]:
            moviesWithGenres.append(movies[i - 2])
    for m in moviesWithGenres:
        if m not in moviesWithGenresOnly:
            moviesWithGenresOnly.append(m)
    x = []
    for m in moviesWithGenresOnly:
        tckts = 0
        for i in range(len(movies)):
            if m == movies[i]:
                tckts += int(movies[i + 1])
        x.extend((m, tckts))
    p = []
    if ticket > selSeats and len(x) == 0:
        print("There are not enough seats for", sel, "and any other movie with the genre", movies[movies.index(sel) + 2] + "!")
    elif selSeats >= ticket:
        print("The reservation is done!")
    elif len(x)!= 0:
        for i in range(len(x)):
            if type(x[i]) == int:
                if x[i] >= ticket:
                    p.append(x[i-1])
        p.sort()
        if len(p) != 0:
            print("There are not enough seats for",
                  sel + "! But you can watch one of the following movies from the genre",
                  movies[movies.index(sel) + 2] + ":")
            for d in range(len(p)):
                print("*", p[d])
        elif len(p) == 0:
            print("There are not enough seats for", sel, "and any other movie with the genre",
                  movies[movies.index(sel) + 2] + "!")
elif sel not in movies:
    print("There is no such movie in the theater.")