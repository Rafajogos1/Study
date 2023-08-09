user_input = input("Please input something: ")
print("You wrote:", user_input)
print("Please enter a number:", end= " ")
while True:
    try:
        num_input = int(input())
        break
    except ValueError:
        print("Invalid input. Please enter a number:", end= " ")
print("You entered the number:", num_input)
if num_input % 2 == 0:
    print("It is an even number.")
else:
    print("It is an odd number.")