#Hello World
print("Hello World")
#Draw a shape
print("   /|")
print("  / |")
print(" /  |")
print("/___|")
#Using variables - covers all types, words separated by 
#	underscore
character_name = "John" #String being stored
character_age = "50" 
change_age = 5 #integer variable
is_male = True #boolean variable (capital T or F)

print("There once was a man named " + character_name + ", ")
print("he was " + character_age + " years old.")

character_name = "Mike"
character_age = "50"
print("He really liked the name " + character_name + ", " )
print("but didn't like being " + character_age + ".")
#Working with strings
print("Giraffe \nAcademy") #New line
print("Giraffe\"Academy") #Print out quotation literally

phrase = "Giraffe Academy"
print(phrase + " is an academy") #concatenate string

print(phrase.lower()) #print in lower case
print(phrase.upper()) #print in upper case

print(phrase.isupper()) #checks for upper case returns t or f
print(phrase.upper().isupper()) #can be used in conjunction

print(len(phrase)) #determine length of string

print(phrase[0]) #Prints the first character in a string
print(phrase[2]) #Prints the third character in string

print(phrase.index("G")) #Returns the index of the parameter
print(phrase.index("Acad"))

print(phrase.replace("Giraffe", "Elephant")) #Replaces 1st with 2nd

#Working with numbers
print(-2.0987) #Prints number
print(3 + 4.5) #Prints 7.5, no trunacation
print(10 % 3) #Prints remainder of 10/3

my_num = -5
print(my_num)
print(str(my_num) + " is my number") #converts number to string

print(abs(my_num)) #absolute value of number
print(pow(3, 2)) #3 raised to the power of 2 -- power function

print(max(4, 6)) #Prints out the bigger number
print(min(4, 6)) #Prints out the smaller number

print(round(3.2)) #rounds number

from math import * #Imports a math library/module

print(floor(3.7)) #Grabs lowest number i.e. chops off decimal
print(ceil(3.7)) #Rounds number no matter what

print(sqrt(36)) #finds sqrt of function = 6.0

#Getting input from users
name = input("Enter your name: ") #Allows user to input, prompt inside
age = input("Enter your age: ")
print("Hello " + name + "! You are " + age) 