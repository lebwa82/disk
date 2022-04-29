#include <iostream>
#include <string> 
#include "header.h"



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