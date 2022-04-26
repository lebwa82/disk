#include <iostream>
#include <string> 
#include "header.h"


int disk_request(int real_time, int is_on_read, Programm* current_programm, 
                vector <multimap <int, Programm*> > disk_vector, 
                multimap <Programm*, Programm*> wait_map)
{//вернет список программ которые надо подождать
    
    Register *p=current_programm->head;


    int flag=0;//есть ли невозможные для записи клетки
    multimap <int, Programm*> blocked_cell; 

    for(int disk_i=p->data->get_start_section(); 
    disk_i<p->data->get_end_section(); disk_i++)//идем по области диска
    {
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

    if(flag==1)//если какой-то блок недоступен
    {
        multimap <int, Programm*> :: iterator it;
        it = blocked_cell.begin();
        for(;it!=blocked_cell.end( );it++)
        {//составляем список ожидания для каждой программы
            wait_map.insert(make_pair(current_programm, it->second));
            //wait_map[current_programm] = it->second; не понятно, почему не работает
            //ERROR
        }
    }

    else//то есть запись возможна
    {
        for(int disk_i=p->data->get_start_section(); 
        disk_i<p->data->get_end_section(); disk_i++)
        {//Пишем данные
            disk_vector[disk_i].insert(make_pair(1, current_programm));
        }
    }









}