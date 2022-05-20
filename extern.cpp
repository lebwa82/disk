#include <iostream>
#include <string> 
//#include "header.h"
#include "wrapper.h"

extern "C"{
    
    Wrapper* create_wrapper()
    {
        return new Wrapper;
    }
    
    Programm* create_programm(char* name, Wrapper *W, int time_start_programm=0)
    {
        Programm * Programm1 = new Programm(name, time_start_programm);
        W->add_programm(Programm1);
        return Programm1;
    }

    const char* get_programm_name(Programm *P)
    {
        return P->get_programm_name().c_str();
    }        

    int add_register_to_programm(Programm* Programm1, char* requester_name, int start_section,
    int end_section, int is_request_on_write, char* time)
    {
        try{
            Request* Request1 = new Request(requester_name, start_section, end_section, is_request_on_write, time);
            Register* Register1 = new Register(Request1);
            Programm1->add_register_to_programm(Register1);
            return 0;
        }
        catch(exception)
        {
            return 1;
        }
        
    }

    void programm_print(Programm *P)
    {
        P->print();
    }
    
    int model_c(Wrapper *W)
    {
        W->print();
        printf("start model_c\n");
        model(W->programm_vector);
        return 0;
    }

    int Wrap_print(Wrapper *W)
    {
        W->print();
        return 0;
    }
   


}