#include <iostream>
#include <string> 
#include "header.h"

int model()
{
//int real_time=0;//метод программы - дай мне ближайший запрос как идея
int i;

map <char, Programm*> mp1;
vector <map <char, Programm*> > dick_vectorl;
//vector <Programm*> vector_programm;
string strp[]={"request1_programm1","request2_programm1", "request3_programm1", "request4_programm1", "request5_programm2"};
int start[]={3,1,5,4,2};
int end[]={7,8,9,10,11};
bool write[]={0,0,1,0,1};
string t[]={"2","2","2","2","2"}; 


Programm *Programm1 = new Programm("programm1");
//Programm1->print();
for(i=0; i<5; i++)
{
    Request *Request1= new Request(strp[i], start[i], end[i], write[i], t[i]);
    Register *Register1= new Register(Request1);
    Programm1->add_register_to_programm(Register1);
}

Programm1->print();


return 0;
}


int model1()
{
    int real_time=0;
    vector <Programm*> programm_vector;
    vector <multimap <int, Programm*> > disk_vector;
    multimap <Programm*, Programm*> wait_map;
    
    int i=0;

    for(i=0; i<programm_vector.size(); i++)
    {
        Programm* current_programm = programm_vector[i];
        Register *current_register=current_programm->head;
        int time_start_programm = current_programm->time_start_programm;
        while(current_register!=NULL)//перебираем запросы
        {
            int is_request_on_write = current_register->data->get_is_request_on_write();
            int time_request = time_start_programm + current_register->data->get_time();//насколько надо упарываться и для каждого поля делать get метод?
            if(time_request == real_time)//если сейчас время выполнить запрос
            { 
                    disk_request(real_time, !bool(is_request_on_write),
                     current_programm, disk_vector, wait_map, current_register); //она либо запишет, либо добавит записи в wait_map
            }

            current_register=current_register->next;
        }

        delete_programm_if_it_empty(current_programm, disk_vector, programm_vector);
        if( is_deadlock(wait_map)  )
        {
            cout << "DEADLOCK" << endl;
            return 1;
        }
    }



    //real_time++; переход на следующий шаг

return 0;
}