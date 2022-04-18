#include <iostream>
#include <string> 
#include "header.h"

int model()
{
int real_time=0;//метод программы - дай мне ближайший запрос как идея
int i;

map <char, Programm*> mp1;
vector <map <char, Programm*> > dick_vectorl;
//vector <Programm*> vector_programm;
string strp[]={"request1_programm1","request2_programm1", "request3_programm1", "request4_programm1", "request5_programm2"};
int start[]={3,1,5,4,2};
int end[]={7,8,9,10,11};
bool write[]={0,0,1,0,1};
int t[]={2,2,2,2,2}; 


Programm *Programm1 = new Programm("programm1");
//Programm1->print();
for(i=0; i<5; i++)
{
    Request *Request1= new Request(strp[i], start[i], end[i], write[i], t[i]);
    //Request1->print();
    Register *Register1= new Register(Request1);
    //Register1->print();
    
    Programm1->add_register_to_programm(Register1);
}

Programm1->print();


return 0;
}
