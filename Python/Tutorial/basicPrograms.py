#Addition Calculator
num1 = input("Enter a number: ")
num2 = input("Enter another number: ")
#Converts user input to an integer or float
result = int(num1) + float(num2)

print(result)
#####################################################################
#Basic Mad Libs
color = input("Enter a color: ")
plural_noun = input("Enter a plural noun: ")
person = input("Enter a person: ")

print("Roses are " + color)
print(plural_noun + " are blue")
print("I love " + person)
#####################################################################
#Lists
friends = ["Kevin", "Karen", "Jim", "Oscar"] #Can store ints in same list
print(friends[0]) #Print first string in list
print(friends[-1]) #index position back of the list is -1
print(friends[1:]) #Prints everything from Karen onwards
print(friends[1:3]) #Prints from index 1 to index 3

friends[1] = "Mike" #Changes index 1 to Mike
print(friends[1])
#####################################################################
#List functions
lucky_numbers = [4, 8, 15, 16, 23, 42]
#friends function from earlier

friends.extend(lucky_numbers) #Appends lucky_numbers list to friends
friends.append("Creed") #Appends a name onto the end of the list
friends.insert(1, "Kelly") #Inserts Kelly at index 1

friends.remove("Jim") #Removes jim from list
friends.pop() #Removes last element from list
friends.clear() #Empties list
#Repopulating list 
friends.append("Kevin")
friends.insert(0, "Jim")
print(friends.index("Kevin")) #Prints index of name if in list
print(friends.count("Jim")) #Prints number of same elements in list

friends.sort() #Sorts list alphabetically
lucky_numbers.sort() #Sorts list

lucky_numbers.reverse() #Reverses order of list

friends2 = friends.copy() #creates a copy of friends list
#####################################################################
#Tuples - Container to store information, is immutable
coordinates = (4, 5) #Tuple is parenthesis
print(coordinates[0]) #Prints index 0

coordinates_list = [(4, 5), (6, 7)] #List with immutable values
#####################################################################
#Functions - def is key word, loc must be indented
def say_hi(name, age): #All code after this line is in function
	print("Hello" + name + ", you are " + str(age))

say_hi("Mike", 35) #funcion call- prints out hello user
say_hi("Steve", 50)
#####################################################################
#Return Statement
def cube(num):
	return num*num*num #Returns cubed value
	
result =	cube(4)
print(cube(3)) #Prints cubed number
print(result)
#####################################################################
#If statements
is_male = False
is_tall = True

if is_male or is_tall: #Excecution of if statement if true
	print("You are a male or tall or both")
else:
	print("You are neither male nor tall")
	
if is_male and is_tall: #Both conditions must be true
	print("You are a tall male")
elif is_male and not(is_tall): #Not negates is_tall
	print("You are a short male")
elif not(is_male) and is_tall: #if is_male is false and is_tall true
	print("You are not a male but are tall")
else:
	print("You are either not male or not tall or both")
#####################################################################
#If statements and comparisons
def max_num(num1, num2, num3):
	if num1 >= num2 and num1 >= num3:
		return num1
	elif num2 >= num1 and num2 >= num3:
		return num2
	else:
		return num3
		
print(max_num(3, 40, 5))
#####################################################################
#Building a better calculator
num1 = float(input("Enter first number: ")) #Auto converts to float
op = input("Enter operator: ")
num2 = float(input("Enter a second number: "))

if op == "+":
	print(num1 + num2)
elif op == "-":
	print(num1 - num2)
elif op == "/":
	print(num1 / num2)
elif op == "*":
	print(num1 * num2)
else:
	print("ERROR: INVALID OPERATOR")
#####################################################################
#Dictionary - Stores info as key value pairs
#Want a program to convert Jan -> January
monthConversions = { #Create inside curly brackets
	"Jan": "January", #Left is key, right is value
	"Feb": "February",
	"Mar": "March",
	"Apr": "April",
	"May": "May",
	"Jun": "June",
	"Jul": "July",
	"Aug": "August",
	"Sep": "September",
	"Oct": "October",
	"Nov": "November",
	"Dec": "December"
}

print(monthConversions["Nov"]) #Prints November
print(monthConversions.get("Dec", "No Key")) #Prints December or def.
#####################################################################
#While loop
i = 1
while i <= 10:
	print(i)
	i = i + 1
	#i += 1 works as well

print("Done with loop")
#####################################################################
#Building a guessing game
secret_word = "giraffe"
guess = ""
guess_count = 0
guess_limit = 3
out_of_guesses = False

while guess != secret_word and not(out_of_guesses):
	if guess_count< guess_limit:
		guess = input("Enter guess: ")
		guess_count += 1
	else:
		out_of_guesses = True

if out_of_guesses:
	print("Out of Guesses, you lose :(")
else:
	print("You win!")
#####################################################################
#For loops 
for letter in "School Academy": #print every letter in school academy
	print(letter)

people = ["Jim", "Karen", "Kevin"]
#Prints each person in array. Can name "person" whatever
for person in people: 
	print(person)
#Prints every number in range of 0 - 10 not including 10
for index in range(10):
	print(index)
#Prints 3 - 9, does not include 10
for index in range(3, 10):
	print(index)
#Prints index 0 to 2
for index in range(len(friends)):
	print(friends[index])

for index in range(5):
	if index == 0:
		print("First iteration")
	else:
		print("Not first")
#####################################################################
#Exponent Function
print(2**3) #2^3 outputs 8

def raise_to_power(base_num, pow_num):
	result = 1
	for index in range(pow_num):
		result = result * base_num
	return result
	
print(raise_to_power(3,2))
#####################################################################
#2D lists and nested arrays
number_grid = [ #4 Rows and 3 columns 
	[1, 2, 3],
	[4, 5, 6],
	[7, 8, 9],
	[0]
]

print(number_grid[0][0]) #Print Row 0 column 0

for row in number_grid: 
	#print(row) #Prints out each row
	for col in row:
		print(col) #Prints out all the columns in each row
#####################################################################
#Build a translator
#Giraffe Language
#Vowles -> g
#dog -> dgg
#cat -> cgt

def translate(phrase): 
	translation = ""
	for letter in phrase: 
		if letter.lower() in "aeiou": #Checks to see if letter in aeiou
			if letter.isupper():
				translation = translation + "G"
			else:
				translation = translation + "g"
		else:
			translation = translation + letter
	return translation
	
print(translate(input("Enter a phrase: ")))
#####################################################################
#Comments - Triple quotation mark for multiple lines
'''
Will not be read
'''
#####################################################################

#Try Except - Handle errors when occur -- try except block
try:
	value = 10 / 0
	number = int(input("Enter a number: "))
	print(number)
except ZeroDivisionError as err: #best practice use specific errors
	print(err)
except ValueError:
	print("Invalid input")
#####################################################################
#Reading Files
#Can take multiple paths to file
#Second parameter is mode of viewing file
#r is for reading the file no change
#W is for writing to the file
#a is for appending to the file, add now info
#r+ can both read and write to file
employee_file = open("employees.txt", "r") 

print(employee_file.readable()) #Returns t or f if readable
print(employee_file.read()) #Reads info from file

#Would need to reset cursor to avoid next errors
print(employee_file.readline()) #Reads oneline
print(employee_file.readlines()) #Puts lines read in lists
print(employee_file.readline()[1]) #Prints out index 1 line

for employee in employee_file.readlines():
	print(employee)
	
employee_file.close() #Closes file
#####################################################################
#Writing to files
#if w is used then entire file is overwritten
append_file = open("employees.txt", "a")

append_file.write("Toby - HR\n")

append_file.close()

#writing to file
write_file = open("employees1.txt", "w")

write_file.write("Kelly - Customer Service\n")

write_file.close()
#####################################################################
#Modules and Pip - Some modules are built in
#	Other modules are external and need to be installed
#		steps to install:
#			1. pip used as a package manager (must install pip)
#			2. Follow guidelines on install
#Hypothetical secondary file "useful_tools.py
import useful_tools #import python file

print(useful_tools.rool_dice(10))
#List of python modules search (Official Docs) -- can be imported 
