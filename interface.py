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
lib_disk.programm_print(Programm1)
