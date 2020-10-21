#If want to inherit functions from another class:
#from fileName import className
#class Student(className):
##Override certain functions can be done:
#def function_name(self)
#	print("Function overwritten)
class Student:
	
	def __init__(self, name, major, gpa, is_on_probation):
		self.name = name
		self.major = major
		self.gpa = gpa
		self.is_on_probation = is_on_probation
		
	def on_honor_roll(self):
		if self.gpa >= 3.5:
			return True
		else:
			return False
