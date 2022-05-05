#include <iostream>
#include <string> 
#include "header.h"



class Wrapper{
public:
    vector <multimap <int, Programm*> > disk_vector;
    vector <Programm*> programm_vector;
    
    Wrapper() {}
    
    int add_programm(Programm* P)
    {
        programm_vector.push_back(P);
        return 0;
    }

    

};