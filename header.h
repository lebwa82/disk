#include <iostream>
#include <string>

using namespace std;

int test1();


class Request
{
    friend int test1(); 
    friend int  main();//временно для отладки 
    
private:

    string requester_name;
    int start_section;
    int end_section;
    bool is_request_on_write;
    //0 - read, 1 - write

public:
    Request()
    {

    }
    Request(const string requester_name,const int start_section,const int end_section,const bool is_request_on_write)
    {
        this->requester_name = requester_name;
        this->start_section = start_section;
        this->end_section = end_section;
        this->is_request_on_write = is_request_on_write;
        if(start_section>=end_section || start_section<0 || end_section <0)
        {
            //cout << "error when creating...  ";
            //надо как-то обработать ошибку, но пока так
            this->start_section = -1;
            this->end_section = -1;
        }
        
    }
    void change_is_request_on_write()
    {
        //пока не понятно зачем менять тип запроса, если можно создать новый запрос
        is_request_on_write = !is_request_on_write;
    }
    
    const int operator>(const Request& other) const
    {
        return start_section > other.start_section;  
    }

     const int operator<(const Request& other) const
    {
        return start_section < other.start_section;  
    }

    const int operator==(const Request& other) const
    {
        return start_section == other.start_section;
    }
    const int operator>=(const Request& other) const
    {
        return start_section >= other.start_section;   
    }
    const int operator<=(const Request& other) const
    {
        return start_section <= other.start_section; 
    }
};

class Single_cell_request
{
public:
    string requester_name;
    int start_section;
    bool is_request_on_write;
    int time;

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
};

class Register{
public:
    Request data;
    Register *next;

    Register(const Request &data)
    {
        this->data = data;
        this->next=NULL;
    }

};



int add_register(Register *head, Register *R);




