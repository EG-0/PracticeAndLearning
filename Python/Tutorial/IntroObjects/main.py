from Student import Student

#Object is instance of class
#student1 is creating an object
student1 = Student("Jim", "Business", 3.6, False)
student2 = Student("Pam", "Art", 2.5, True)

print(student1.name)
print(student2.gpa)

print(student1.on_honor_roll())
