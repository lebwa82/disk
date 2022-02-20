#include <iostream>
#include <string>

using namespace std;

int test1();

class Request
{  
public:
    string requester_name;
    int start_section;
    int end_section;
    bool type_request; //0 - read, 1 - write
    Request(string requester_name, int start_section, int end_section, bool type_request)
    {
        this->requester_name = requester_name;
        this->start_section = start_section;
        this->end_section = end_section;
        this->type_request = type_request;
        if(start_section>=end_section || start_section<0 || end_section <0)
        {
            cout << "error when creating...  ";
            //надо как-то обработать ошибку, но пока так
            this->start_section = -1;
            this->end_section = -1;
        }
        
    }
    void change_type_request()
    {
        type_request = !type_request;
    }
    
    int operator>(Request other)
    {
        if(start_section > other.start_section) return 1;
        else return 0; 
    }

    int operator==(Request other)
    {
        if(start_section == other.start_section) return 1;
        else return 0; 
        
    }
    int operator>=(Request other)
    {
        if(start_section >= other.start_section) return 1;
        else return 0; 
        
    }
    int operator<=(Request other)
    {
        if(start_section <= other.start_section) return 1;
        else return 0; 
        
    }
};

class Single_cell_request
{
public:
    string requester_name;
    int start_section;
    bool type_request;
    int time;

    Single_cell_request(string requester_name, int start_section, string time)
    {
        this->requester_name = requester_name;
        this->start_section = start_section;
        this->type_request = type_request;
        if(time=="false")
        {
            this->time = 0;
        }
        else
        {
            try{
                this->time = stoi(time);
            }
            catch(std::invalid_argument e) {
                this->time = -1;
                cout << "Caught Invalid Argument Exception\n";
                
            }
            
        }
    }
};





