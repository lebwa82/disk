#include <iostream>
#include <string>

using namespace std;

int test1();
class Single_cell_request
{
public:
    string requester_name;
    int start_section;
    bool is_request_on_write;
    int time;
    Single_cell_request()
    {

    }
    Single_cell_request(const string requester_name,const int start_section,const string time)
    {
        this->requester_name = requester_name;
        this->start_section = start_section;
        this->is_request_on_write = is_request_on_write;
        if(time=="false")
        {
            this->time = 0;
        }
        else
        {
            try{
                this->time = stoi(time);
            }
            catch(invalid_argument e) {
                this->time = -1;
                cout << "Caught Invalid Argument Exception\n";
                
            }
            
        }
    }
    void change_is_request_on_write()
    {
        //пока не понятно зачем менять тип запроса, если можно создать новый запрос
        is_request_on_write = !is_request_on_write;
    }

    const int operator>(const Single_cell_request& other) const
    {
        return start_section > other.start_section;  
    }

        const int operator<(const Single_cell_request& other) const
    {
        return start_section < other.start_section;  
    }

    const int operator==(const Single_cell_request& other) const
    {
        return start_section == other.start_section;
    }
    const int operator>=(const Single_cell_request& other) const
    {
        return start_section >= other.start_section;   
    }
    const int operator<=(const Single_cell_request& other) const
    {
        return start_section <= other.start_section; 
    }

};

class Request : public Single_cell_request
{
    friend int test1(); 
    friend int  main();//временно для отладки 
    
private:

    string requester_name;
    int start_section;
    int end_section;
    bool is_request_on_write;
    int time;
    //0 - read, 1 - write

public:
    Request()
    {

    }
    Request(const string requester_name,const int start_section,
    const int end_section,const bool is_request_on_writem, int time=0)
    {
        this->requester_name = requester_name;
        this->start_section = start_section;
        this->end_section = end_section;
        this->is_request_on_write = is_request_on_write;
        this->time = time;
        if(start_section>=end_section || start_section<0 || end_section <0)
        {
            //cout << "error when creating...  ";
            //надо как-то обработать ошибку, но пока так
            this->start_section = -1;
            this->end_section = -1;
        }
        
    }
    
};


class Register{
public:
    Single_cell_request *data;
    Register *next;
    Register() {this->next=NULL;}
    Register(Single_cell_request *data1)
    {
        this->data = data1;
        this->next=NULL;
    }

};


int add_register(Register *head, Register *R);


class Programm
{
public:
    string programm_name;
    Register *head;
    int time_start_programm;

    Programm(const string &name, const int time_start_programm=0)
    {
        this->programm_name = name;
        this->time_start_programm = time_start_programm;
        head->next=NULL; 
    }
    
    int add_register_to_programm(Register *R)
    {
    Register *p = head;
    while(p->next != NULL)
    {
        if(R->data < p->data)
        {
            p=p->next;
        }
        else
        {
            break;
        } 
    } 
    R->next = p->next;
    p->next = R;
    return 0;
    

    }
};
/*
class Programm_list //желательно сделать Singleton (взять из лекции)
{
public: 
    Programm data;
    Programm_list * next;

    Programm_list()
    {
        this->next=NULL;
    }

    int add_programm_to_list(Programm *new_programm, Programm_list *head)
    {
    Register *p = head;
    while(p->next != NULL)
    {
        if(R->data < p->data)
        {
            p=p->next;
        }
        else
        {
            break;
        } 
    } 
    R->next = p->next;
    p->next = R;
    return 0;
    }



};
*/

