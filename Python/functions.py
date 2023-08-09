#Adds a and b and returns the result
def add_numbers(a, b):
    result = a + b
    return result

#Subtracts a and b and returns the result
def subtract_numbers(a, b):
    result = a - b
    return result

num1 = 20
num2 = 30
print(f"{num1} + {num2} = {add_numbers(num1, num2)}")
print(f"{num1} - {num2} = {subtract_numbers(num1, num2)}")