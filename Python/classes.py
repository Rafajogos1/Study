class Person: #Define a class named "Person" with three values and a method that uses said values
    def __init__(self, name, age, gender):
        self.name = name
        self.age = age
        self.gender = gender
    def introduce(self):
        print(f"My name is {self.name} I'm {self.age}, years old and I'm a {self.gender}.")
    def receive_arg(self, arg):
        print(f"I received a {arg}.")

class Worker(Person):
    def profession(self):
        print("I'm a worker")

class Birth(Person): #I only noticed how redundant this is afterwards, but I used it to learn how to work with inheritance.
    def __init__(self, name, age, gender, age_of_birth):
        super().__init__(name, age, gender)
        self.age_of_birth = age_of_birth
    def when_born(self):
        print(f"I was born {self.age_of_birth} years ago.")

Angela = Person("Angela", 25, "female") #Create a new "Person", name it "Angela" and attribute values to it
Michael = Person("Michael", 32, "male") #Create a new "Person", name it "MIchael" and attribute values to it
Angela.introduce() #Call the method "introduce" of Angela
Angela.receive_arg("spoon") #Call the method "receive_arg" of Angela and pass "spoon" to it
Michael.introduce() #Call the method "introduce" of Michael
Michael.receive_arg("fork") #Call the method "receive_arg" of Michael and pass "fork" to it

#Inheritance
print("")
Timmy = Worker("Timmy", 19, "male")
Timmy.introduce()
Timmy.receive_arg("knife")
Timmy.profession()

print("")
Caroline = Birth("Caroline", 20, "female", 20)
Caroline.introduce()
Caroline.receive_arg("suitcase")
Caroline.when_born()
