user_input = input("Please input something: ") #Ask for user input and store it in "user_input"
print("You wrote:", user_input)
print("Please enter a number:", end= " ")
while True:
    try: #Attempt to save the input as an input
        num_input = int(input())
        break
    except ValueError: #Catch a "ValueError" exception if the value cannot be assigned as an int
        print("Invalid input. Please enter a number:", end= " ")
print("You entered the number:", num_input)
if num_input % 2 == 0: #Check if the rest of the division is 0 to check if the number is even or odd
    print("It is an even number.")
else:
    print("It is an odd number.")