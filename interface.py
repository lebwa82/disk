import ctypes
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


lib_disk.create_programm.argtypes = [ctypes.c_char_p, ctypes.c_int]
lib_disk.create_programm.restype = ctypes.c_void_p
P = lib_disk.create_programm(bytes("Programm1", encoding="utf-8"), 0)

lib_disk.get_programm_name.argtypes = [ctypes.c_void_p]
lib_disk.get_programm_name.restype = ctypes.c_char_p
a = lib_disk.get_programm_name(P)
print(a.decode('utf-8'))