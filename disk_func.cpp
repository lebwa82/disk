#include <iostream>
#include <string> 
#include "header.h"


int disk_request(int real_time, int is_on_read, Programm* current_programm, 
                vector <multimap <int, Programm*> > &disk_vector, 
                multimap <Programm*, Programm*> &wait_map, Register *current_register)
{//вернет список программ которые надо подождать
    int flag=0;//есть ли невозможные для записи клетки
    multimap <int, Programm*> blocked_cell; 
    printf("disk_request1\n");
    for(int disk_i=current_register->data->get_start_section(); 
    disk_i<current_register->data->get_end_section(); disk_i++)//идем по области диска
    {
        printf("disk_request2\n");
        if(disk_vector[disk_i].count(1)+disk_vector[disk_i].count(is_on_read)>0)//если не пустой
        {//если хочу читать - то не должно быть запросов на запись. А если хочу писать - то никаких
            flag=1;//так это попытка записи, то если кто-то еще смотрит
            //хотя бы одну клетку - то мы вылетаем
            blocked_cell = disk_vector[disk_i];
            break;//по идее я могу вылететь:
            //типа я подожду завершения этой программы и потом пройду дальше
            //я в любом случае найду deadblock - только позже
        }
    }
    printf("disk_request3\n");

    if(flag==1)//если какой-то блок недоступен
    {
        printf("flag=1\n");
        multimap <int, Programm*> :: iterator it;
        it = blocked_cell.begin();
        for(;it!=blocked_cell.end( );it++)
        {//составляем список ожидания для каждой программы
            wait_map.insert(make_pair(current_programm, it->second));
            
            Register * p = current_programm->head;
            while(p!= NULL)
            {
                if(p->data->get_time() == real_time)
                {
                    current_register->data->increase_time_by_1();
//отложим программу на 1, чтобы в следующий раз еще раз проверить возможность действия
                }
                p=p->next;
            }
        }  
    }

    else//то есть запись возможна
    {   printf("else flag=0\n");
        for(int disk_i=current_register->data->get_start_section(); 
        disk_i<current_register->data->get_end_section(); disk_i++)
        {//Пишем данные
            disk_vector[disk_i].insert(make_pair(1, current_programm));
        }
        puts("after else for");
        current_programm->delete_reqister_from_programm(current_register);
        puts("after else for2");
    }
    return 0;

}




int is_deadlock(multimap <Programm*, Programm*> wait_map)
{
    multimap <Programm*, Programm*> :: iterator one = wait_map.begin();
    multimap <Programm*, Programm*> :: iterator two;
    for(;one!=wait_map.end( );one++)
    {
        for(two = one;two!=wait_map.end( );two++)
        {
            if(one->first == two->second && one->second == two->first)
            {
                return 1;//все плохо - дедблок есть
            }
        }
    }
    return 0;//все хорошо
}




int delete_programm_if_it_empty(Programm* current_programm, vector <multimap <int, Programm*> > &disk_vector, vector <Programm*> &programm_vector)
{
    if(current_programm->head!= NULL)
    {
        return 1;//если в программе еще есть запросы - ее удалять не надо
    }
    multimap <int, Programm*> mp;
    multimap <int, Programm*> :: iterator it;
    int disk_i=0;
    for(disk_i=0; disk_i<disk_vector.size(); disk_i++)
    {
        mp = disk_vector[disk_i];
        for(;it!=mp.end( );it++)
        {
            if(it->second == current_programm)
            {
                mp.erase(it);//Нужно ли сделать it--?
            }
        }
        vector <Programm*> :: iterator v;
        for(v = programm_vector.begin(); v!=programm_vector.end(); v++)
        {
            if(*v==current_programm)
            {
                programm_vector.erase(v);
            }
        }
        
    }
    return 0;



}


void print_disk(vector <multimap <int, Programm*> > &disk_vector)
{
    multimap <int, Programm*> mp;
    multimap <int, Programm*> :: iterator it;
    int disk_i=0;
    for(disk_i=0; disk_i<disk_vector.size(); disk_i++)
    {
       // puts("print_disk for");
        mp = disk_vector[disk_i];
        //printf("mp.size()=%d\n", mp.size());
        if(mp.size()>0)
        {
            printf("size>0\n");
            it = mp.begin();
            cout << it->first << ":  ";
            for(;it!=mp.end( );it++)
            {
                cout << it->second << "  ";
            }
            cout << "\n";

        }
        
        
    }
}