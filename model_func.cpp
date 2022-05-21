#include <iostream>
#include <string> 
#include "header.h"



int model(vector <Programm*> &programm_vector)
{
    printf("start model\n");
    int real_time=0;
    printf("real_time = %d\n", real_time);
    vector <multimap <int, Programm*> > disk_vector(100);
    multimap <Programm*, Programm*> wait_map;
    
    int i=0;

    for(i=0; i<programm_vector.size(); i++)
    {
        printf("for of model\n");
        Programm* current_programm = programm_vector[i];
        Register *current_register=current_programm->head;
        int time_start_programm = current_programm->time_start_programm;
        while(current_register!=NULL)//перебираем запросы
        {
            printf("current_register->print\n");
            current_register->print();
            int is_request_on_write = current_register->data->get_is_request_on_write();
            int time_request = time_start_programm + current_register->data->get_time();//насколько надо упарываться и для каждого поля делать get метод?
            if(time_request == real_time)//если сейчас время выполнить запрос
            {
                    printf("start if\n");
                    disk_request(real_time, !bool(is_request_on_write),
                     current_programm, disk_vector, wait_map, current_register); //она либо запишет, либо добавит записи в wait_map
            }
            printf("after if\n");

            current_register=current_register->next;
        }
        puts("before delete programm");
        delete_programm_if_it_empty(current_programm, disk_vector, programm_vector);
        puts("after delete programm");
        if( is_deadlock(wait_map)  )
        {
            cout << "DEADLOCK" << endl;
            return 1;
        }

    }

    printf("real_time = %d\n", real_time);
    print_disk(disk_vector);

    //real_time++; переход на следующий шаг

return 0;
}