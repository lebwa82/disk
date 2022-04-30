import ctypes
lib_programm = ctypes.CDLL('./libdisk.so')


print("enter the number of programs")
count = int(input())
for i in range(count):
    print(f"enter the {i} programm name")
    number_of_programms = int(input())
    
    
