#include <iostream>
#include <string> 
#include "header.h"


extern "C"{

    Programm *create_programm(char* name, int time_start_programm=0)
    {
        return new Programm(name, time_start_programm);
    }

    int add_register_to_programm(Programm* Programm1, char* requester_name, int start_section,
    int end_section, int is_request_on_write, char* time="0")
    {
        Request* Request1 = new Request(requester_name, start_section, end_section, is_request_on_write, time);
        Register* Register1 = new Register(Request1);
        Programm1->add_register_to_programm(Register1);
    }
    
    int model(Programm***programm_vector)
    {
        model(programm_vector);
    }


}