def arithmetic_arranger(problems):
	#Splits list into one long string
	result_str = ""
	for numbers in problems:
		result_str = result_str + numbers + " "
		
	#Separates new string into list by spaces
	result_str = result_str.split()
	
	#Converts 1D List into 2 with problems separated into own lists
	arranged_problems = []
	k = 0
	for i in range(int(len(result_str)/3)):
		new_array = []
		for j in range(3):
			new_array.append(result_str[i + j + k])
		arranged_problems.append(new_array)
		k += 2
	
	#Checks for error messages
	if len(arranged_problems) > 5:
		return print("Error: Too many problems.")

	for row in range(len(arranged_problems)):
		for column in range(3):

			if column % 2 == 1:
				if not arranged_problems[row][column] in "+-":
					return print("Error: Operators must be '+' or '-'.")
			if column % 2 == 0: 
				if not(arranged_problems[row][column].isdigit()):
					return print("Error: Numbers must only",
						"contain digits.")
			if column % 2 == 0:
				if len(arranged_problems[row][column]) > 4:
					return print("Error: Numbers cannot be more",
						"than 4 digits.")
			
	return arranged_problems
	
print(arithmetic_arranger(["33 + 6989", "54 - 1", "3 - 4", "1 + 2"]))
