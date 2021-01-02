def add_time(start, duration, day):

	#Separate the hours from others in start
	start_hours = start.split(":")
	#Separate the minutes from others in start
	start_minutes = start_hours[1].split(" ")[0]
	#Make hours the only thing available
	start_hours = start_hours[0]
	
	duration_hours = duration.split(":")[0]
	duration_minutes = duration.split(":")[1]
	
	start_minutes = int(start_minutes) + int(duration_minutes)
	start_hours = int(start_hours) + int(duration_hours)
	
	
	'''
	if minutes[1] == "AM"
		day_half = 0
	else: 
		day_half = 1
	'''
	
	new_time = 0

	return new_time
