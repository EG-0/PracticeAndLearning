class Rectangle:
	
	def __init__(self, width, height):
		self.width = width
		self.height = height

	def set_width(self, width):
		self.width = width
		
	def set_height(self, height):
		self.height = height
		
	def get_area(self):
		return self.width * self.height
		
	def get_perimeter(self):
		return self.width * 2 + self.height * 2
		
	def get_diagonal(self):
		return (self.width ** 2 + self.height ** 2) ** .5
		
	def get_picture(self):
		#Check preconditions for printing picture
		if self.height > 50 or self.width > 50:
			return "Too big for picture"
		
		return_string = ""
		#Set string equal to height and width of paramteters
		for i in range(self.width):
			return_string = return_string + "*"
		
		return_string += "\n"
		return_string = return_string * self.height
		
		return return_string
		
	def get_amount_inside(self, shape):	
		return int(self.get_area() / shape.get_area())
			
	def __str__(self):
		return f"Rectangle(width ={self.width}, height ={self.height})"

class Square(Rectangle):

	def __init__(self, side):
		self.width = side
		self.height = side
		self.side = side
		
	def set_side(self, side):
		self.width = side
		self.height = side
		self.side = side
	
	def set_width(self, side):
		self.width = side
		
	def set_height(self, side):
		self.height = side
		
	def __str__(self):
		return f"Square(side={self.side})"
