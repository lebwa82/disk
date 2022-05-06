import ctypes
import time
lib_disk = ctypes.CDLL('./libdisk.so')

'''
print("enter the number of programs")
count = int(input())
for i in range(count):
    print(f"enter the {i} programm name")
    number_of_programms = int(input())'''
    
    
strp=["request1_programm1","request2_programm1", "request3_programm1", "request4_programm1", "request5_programm2"]
start=[3,1,5,4,2]
end=[7,8,9,10,11]
write=[0,0,1,0,1]
t=["2","2","2","2","2"]


lib_disk.create_wrapper.restype = ctypes.c_void_p
lib_disk.create_wrapper.argtypes=[]
Wrap=lib_disk.create_wrapper()

lib_disk.create_programm.argtypes = [ctypes.c_char_p, ctypes.c_void_p, ctypes.c_int]
lib_disk.create_programm.restype = ctypes.c_void_p
Programm1 = lib_disk.create_programm(bytes("Programm1", encoding="utf-8"), Wrap, 0)

lib_disk.get_programm_name.argtypes = [ctypes.c_void_p]
lib_disk.get_programm_name.restype = ctypes.c_char_p
a = lib_disk.get_programm_name(Programm1)
#print(a.decode('utf-8'))

lib_disk.add_register_to_programm.argtypes = [ctypes.c_void_p, ctypes.c_char_p, 
ctypes.c_int, ctypes.c_int, ctypes.c_int, ctypes.c_char_p]
lib_disk.add_register_to_programm.restype = ctypes.c_int
lib_disk.add_register_to_programm(Programm1, bytes("request1", encoding="utf-8"), 2, 5, 0, bytes("1", encoding="utf-8"))

lib_disk.programm_print.argtypes = [ctypes.c_void_p]
#lib_disk.programm_print(Programm1)

file = open("data_file.txt", "r")
line = file.readline()#read comment line
number_of_programms = int(file.readline())

for i in range(number_of_programms):
    line = file.readline()#read comment line
    programm_name = file.readline()
    line = file.readline()#read comment line
    time_start_programm = int(file.readline())
    Programm1 = lib_disk.create_programm(bytes(programm_name, encoding="utf-8"), Wrap, time_start_programm)


    line = file.readline()#read comment line
    number_of_requests = int(file.readline())
    line = file.readline()#read comment line
    for j in range(number_of_requests):
        line = file.readline()
        line_list = line.split()
        request_name = line_list[0]
        start_section = int(line_list[1])
        end_section = int(line_list[2])
        is_request_on_write = int(line_list[3])
        reauest_time = line_list[4]
        print(f"test {j}")
        is_error = lib_disk.add_register_to_programm(Programm1, bytes(request_name, encoding="utf-8"), start_section,
        end_section, is_request_on_write , bytes(reauest_time, encoding="utf-8"))
        print(f"test111 {j}")
        if(is_error==0):
            print("OK")
        else: 
            print(f"Error in create {j} of programm {i}")


#lib_disk.programm_print(Programm1)     






















'''
Console enter
print("How many programms do you wanna have?")
number_of_programms = int(input())
for i in range(number_of_programms):
    print(f"entet name of {i+1} programm")
    programm_name = input()
    print("enter time_start_programm")
    time_start_programm = int(input())
    Programm1 = lib_disk.create_programm(bytes(programm_name, encoding="utf-8"), Wrap, time_start_programm)
    print(f"programm {i+1} created\n How many requests will add?")
    number_of_requests = int(input())
    for j in range(number_of_requests):
        print("enxter name of requests {j}")
        request_name = input()
        print("enxter start section")
        start_section = int
        print("enxter end section")
        print("enxter is request on write")
        '''