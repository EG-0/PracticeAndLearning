class Category:

	def __init__(self, name):
		self.ledger = []
		self.name = name
		self.total = 0
	
	def deposit(self, amount, description = None):
		self.total = self.total + amount
		
		if description == None:
			self.description = ""
		else:
			self.description = description
			
		self.ledger.append(
			{"amount": amount, "description": description}
		)
		
	def withdraw(self, amount, description = None):
		
		#Checking to ensure enough funds are available
		if (check_funds(self, amount) == False):
			return False
		else:
		
			self.total = self.total - amount
		
			if description == None:
				self.description = ""
			else:
				self.description = description
			
			self.ledger.append(
					{"amount": -amount, "description": description}
				)
		
			return True
		
	def get_balance(self):
	
		return self.total
		
	def transfer(self, amount, budget_cat):
		
		if (check_funds(self, amount) == False):
			return False
		else:
			
			self.total = self.total - amount
			budget_cat.total = budget_cat.total + amount
			
			self.ledger.append(
				{
					"amount": -amount, 
					"description": "Transfer to {budget_cat.name}"
				}
			)
			
			budget_cat.ledger.append(
				{
					"amount": amount,
					"description": "Transfer from {self.name}"
				}
			)
			
			return True
		
	def check_funds(self, amount):
		
		if amount > self.total:
			return False
		else: 
			return True
