#This way works best when the files are needed for a short amount of time
with open("Test Files/test_read.txt", "r") as file1, open("Test Files/test_write.txt", "w") as file2, open("Test Files/test_append.txt", "a") as file3:
    print(file1.read())
    file2.write("Sreo")
    file3.write("\nSreo")