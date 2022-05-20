#include <iostream>
#include <string> 
#include "header.h"



class Wrapper{
public:
    //vector <multimap <int, Programm*> > disk_vector;
    vector <Programm*> programm_vector;
    
    Wrapper() {}
    
    int add_programm(Programm* P)
    {
        programm_vector.push_back(P);
        return 0;
    }

    void print()
    {
        int i;
        for(i=0; i<programm_vector.size(); i++)
        {
            programm_vector[i]->print();
        }

    }
    

};