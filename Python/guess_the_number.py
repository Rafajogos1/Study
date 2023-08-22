import random
import sys

#The following two values can be changed at will
min_range = 1
max_range = 100
if min_range > max_range: #Initial check to make sure the range is set correctly
    print("ERROR: The minimum number is smaller than the maximum number!")
    exit(1)
num = random.randint(min_range, max_range) #Generate a random number between the range
max_guess = int((max_range - min_range) / 10) #Set the max guesses to the difference of the values divided by 10
guess_counter = 0
print(f"I've generated a random number between {min_range} and {max_range}. Try to guess it.")
print(f"You have {max_guess} turns.")
guess = 0
while guess != num and max_guess > 0:
    while True: #Check if the input is a number
        try:
            guess = int(input())
            if min_range <= guess <= max_range: #Check if the number is within the set limits
                break
            else:
                print("Please input a number between 1 and 100.")
        except ValueError: #Catch the exception of the input not fitting in an int
            print("You didn't input a number.")
    if guess < num:
        print("Too low.")
    if guess > num:
        print("Too high.")
    max_guess -= 1
    guess_counter += 1
    if max_guess > 1: #Tell the players how many turns they have
        print(f"You have {max_guess} turns left.")
    else:
        print(f"You have only 1 turn left.")
if guess == num: #If the player managed to guess the number
    print("Congratulations, you guessed the number!")
    if guess_counter == 1:
        print("You guessed it in only 1 turn. Amazing!")
    else:
        print(f"You guessed it in {guess_counter} turns.")
else: #If the player didn't manage to guess the number
    print(f"You didn't manage to guess the number.")
    print(f"The number was {num}.")