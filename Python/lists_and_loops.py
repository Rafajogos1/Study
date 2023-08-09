number_list = [1, 2, 3, 4, 5]
fruits = ["apple", "banana", "pineapple", "kiwi", "passionfruit"]
mixed = [5, "string", 3.14]

#"for" loops
print("Testing with \"for\" loops")
for num in number_list:
    print(num)
print("")
for fruit in fruits:
    print(fruit)
print("")
for mix in mixed:
    print(mix)
print("")

#"while" loops
print("Testing with \"while\" loops")
i = 0
while i < len(number_list):
    print(number_list[i])
    i += 1
print("")
i = 0
while i < len(fruits):
    print(fruits[i])
    i += 1
print("")
i = 0
while i < len(mixed):
    print(mixed[i])
    i += 1