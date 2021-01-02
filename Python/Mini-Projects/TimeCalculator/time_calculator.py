def add_time(start, duration, day):

	#Separate the hours from others in start
	start_hours = start.split(":")
	#Separate the minutes from others in start
	start_minutes = start_hours[1].split(" ")[0]
	#Separate AM/PM from others in start
	day_half = start_hours[1].split(" ")[1]
	#Make hours the only thing available
	start_hours = start_hours[0]
	
	#Split duration parameter into hours and minutes
	duration_hours = duration.split(":")[0]
	duration_minutes = duration.split(":")[1]
	
	#Add minutes and hours together
	start_minutes = int(start_minutes) + int(duration_minutes)
	start_hours = int(start_hours) + int(duration_hours)
	
	#Calculate minutes
	duration_minutes = int(start_minutes) / int(60)
	remainder_minutes = start_minutes % 60

	#Format minutes properly if less then 10
	if int(remainder_minutes) < 10:
		remainder_minutes = "0" + str(remainder_minutes)

	#Calculate hours
	start_hours = start_hours + int(duration_minutes)
	remainder_hours = start_hours % 12
	
	#Format AM/PM properly
	if (int(start_hours) / 12) > 0:
		#Need number of half days added
		temp_time_track = int((start_hours) / 12) % 2
		
		#Add corresponding number representing which half of the day
		#	it is
		if day_half == "AM":
			temp_time_track = temp_time_track + 0
		else: 
			temp_time_track = temp_time_track + 1
		
		#Determine whether temp_time_track is even or odd
		# Even means first half of day, odd means second
		if temp_time_track % 2 == 0:
			day_half = " AM"
		else:
			day_half = " PM"

	#Format output
	new_time = str(remainder_hours) + ":" + str(remainder_minutes) + day_half
	
	return new_time
