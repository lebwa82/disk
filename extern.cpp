#include <iostream>
#include <string> 
#include "header.h"


extern "C"{
    /*
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
    
    int model(Programm**programm_vector)
    {
        model(programm_vector);
    }*/

    int start_programm(int number_of_programms, char**programm_names, 
    int* time_start_programm, int* number_of_reqisters, char*** requester_name,
    int** start_section,int** end_section, int **is_request_on_write, char*** time)
    {
        int i=0, j=0;
        vector <Programm*> programm_vector;
        for(i=0; i<number_of_programms; i++)
        {
            Programm * Programm1 = new Programm(programm_names[i], time_start_programm[i]);
            programm_vector.push_back(Programm1);
            for(j=0; j<number_of_reqisters[i]; j++)
            {
                Request* Request1 = new Request(requester_name[i][j], start_section[i][j], end_section[i][j], is_request_on_write[i][j], time[i][j]);
                Register* Register1 = new Register(Request1);
                Programm1->add_register_to_programm(Register1);
            }
        }
        model(programm_vector);
    }

}