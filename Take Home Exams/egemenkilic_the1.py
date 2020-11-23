# To begin with, I've decided to work with common units. I've chosen KB and seconds to work with.
# I generally write my codes in CamelCase, I wanted to give a try to write using _ this time.
# Watching a minute of 480p video costs 7.7 MB to user, it was a given data.
# So I converted the cost of video to KB at first.
# Then, I divided the result by 60 to calculate what is the cost of watching a second of 480p video.
cost_of_watching_one_sec_video = 7.7 * 1024 / 60
# I've declared the cost of sending a message on WhatsApp in KB.
cost_of_sending_one_message = 1.7
# I've got the quota of user in GB.
quota = float(input("Please enter your internet quota (GB): "))
# Quota is converted to KB.
quota_in_KB = quota * 1024 ** 2
# Asked user to enter the value of watched minutes.
viewing_time_of_user = float(input("Please enter your total video viewing time in minutes: "))
# I have calculated the cost of viewing time in KB.
# Multiplying viewing time with 60 converts the watched minutes to seconds.
# Multiplying the result with oneSecVideo allows me to calculate the cost of watching x seconds.
viewing_time_in_Kb = viewing_time_of_user * 60 * cost_of_watching_one_sec_video
# Asked user to enter the number of messages sent.
messages_sent = int(input("Please enter the number of messages you send: "))
# By multiplying the value of messages by oneMessage, the cost of sending y messages was calculated in KB.
messages_in_Kb = messages_sent * cost_of_sending_one_message
# remainingQuota was calculated by subtracting the sum of viewingTimeInKb and messagesInKb from quotaInKb
remaining_Quota_in_Gb = (quota_in_KB - viewing_time_in_Kb - messages_in_Kb) / 1024 ** 2
# Printed the reuslt of remainingQuota, rounded it to 2 significant figures.
print("Your remaining internet quota is", round(remaining_Quota_in_Gb, 2), "GB(s).")
# Converted the remainingQuota to KB.
remaining_quota_in_Kb = remaining_Quota_in_Gb * 1024 ** 2
# Calculated the value of watchableHours. To do so, I've divided the remainingQuotaInKb by oneSecVideo * 3600
# The reason why I multiplied the value with 3600 is to convert seconds to hours.
watchableHours = remaining_quota_in_Kb / (cost_of_watching_one_sec_video * 3600)
# Calculated watchableMinutes as an integer value.
watchableMinutes = int(remaining_quota_in_Kb / (cost_of_watching_one_sec_video * 60))
# watchableHours had a float and I needed the decimal part, so I've subtracted the int value of the original value.
a = watchableHours - int(watchableHours)
# By multiplying the value with 60, I've converted hours to minutes.
b = int(a * 60)
# To calculate the watchableSeconds, I've did the same maths on line 34 with a little parts.
watchableSeconds = watchableHours * 3600 - int(watchableHours) * 3600 - b * 60
# Finally, printed out the result.
print("You can watch video for", int(watchableHours), "hour(s),", b, "minute(s) and", round(watchableSeconds, 2), "second(s).")
# Thanks for the pleasurable assignment!
# Regards, Egemen Kilic.
