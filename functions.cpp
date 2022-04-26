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
    Register *Register1= new Register(Request1);//здесь хрень какая-то
    Programm1->add_register_to_programm(Register1);//почему-то не сортирует
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
        Register *p=current_programm->head;
        int time_start_programm = current_programm->time_start_programm;
        while(p!=NULL)//перебираем запросы
        {
            int is_request_on_write = p->data->get_is_request_on_write();
            int time_request = time_start_programm + p->data->get_time();//насколько надо упарываться и для каждого поля делать get метод?

            if(time_request == real_time)//если сейчас время выполнить запрос
            {
                if(is_request_on_write==1)//пытаемся писать
                {
                    int flag=0;//есть ли невозможные для записи клетки
                    multimap <int, Programm*> blocked_cell; 

                    for(int disk_i=p->data->get_start_section(); 
                    disk_i<p->data->get_end_section(); disk_i++)//идем по области диска
                    {
                        if(!disk_vector[disk_i].empty())//если не пустой
                        {
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
                
                //disk_request(real_time, !bool(is_request_on_write), 
                //current_programm, disk_vector, wait_map); попробовать запустить это
                
                
                }



                


            }




            p=p->next;
        }


        




    }

    


return 0;
}