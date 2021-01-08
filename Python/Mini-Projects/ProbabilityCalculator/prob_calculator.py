import copy
import random
# Consider using the modules imported above.

class Hat:

	def __init__(self, **kwargs):
	
		self.contents = []
		
		for k, v in kwargs.items():
			for v in range(v):
				self.contents.append(k)
				
	def draw()

def experiment(hat, expected_balls, num_balls_drawn, num_experiments):
