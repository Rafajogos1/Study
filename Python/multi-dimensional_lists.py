matrix = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]

for row in matrix: #loop inside the list
    for i in row: #loop inside the current nested list
        print(i)
        if i % 2 == 0: #check if the value is an odd or an even number
            print("even")
        else:
            print("odd")