def bisection(user_list, target):
    user_list.sort()
    sum = 0
    for i in range(len(user_list)):
        sum += user_list[i]
    mean = int(sum / len(user_list))
    while target != mean:
        if len(user_list) % 2 == 0:
            first_half = user_list[0:int(len(user_list) / 2)]
            second_half = user_list[int(len(user_list) / 2):len(user_list)]
            sum_first_half = 0
            sum_second_half = 0
            for i in range(len(first_half)):
                sum_first_half += first_half[i]
            for i in range(len(second_half)):
                sum_second_half += second_half[i]
            mean_secondHalf
        elif len(user_list) % 2 == 1:
            print(None)



bisection([1,2,3,4,5,6,7,8], 8)