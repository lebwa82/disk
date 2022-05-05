#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int test1();
int test2();


class Single_cell_request
{
protected:
    string requester_name;
    int start_section;
    bool is_request_on_write;
    int time;

public:
    Single_cell_request()
    {

    }
    Single_cell_request(const string requester_name,const int start_section, bool is_request_on_write, const string time="0")
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
        //printf("operator>: %d %d", start_section, other.start_section);
        return start_section > other.start_section;  
    }

    const int operator<(const Single_cell_request& other) const
    {
        //printf("operator<: %d %d", start_section, other.start_section);
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


    virtual void print()
    {
        //printf("%s,  %d,   %d,   %d\n", requester_name, start_section,
        //is_request_on_write, time);
        cout << requester_name << "   " << start_section << "   ";
        cout << is_request_on_write << "   " << time << endl;

    }

    virtual string get_requester_name()
    {
        return requester_name;
    }

    virtual int get_start_section()
    {
        return start_section;
    }

    virtual int get_end_section()
    {
        return start_section+1;
    }

    virtual bool get_is_request_on_write()
    {
        return is_request_on_write;
    }

    virtual int get_time()
    {
        return time;
    }    
    //сделать виртуальный метод который запрашивает начало и конец и перегрузить его в наследнике
    void increase_time_by_1()
    {
        time++;
    }
};

class Request : public Single_cell_request
{
    friend int test1(); 
    friend int  main();//временно для отладки 
    
private:
    int end_section;

public:
    Request()
    {

    }
    Request(string requester_name, const int start_section,
    const int end_section, const bool is_request_on_write, string time="0"):
    Single_cell_request(requester_name,start_section, is_request_on_write,time)
    { 
        this->end_section = end_section;
        if(start_section >= end_section || start_section<0 || end_section <0)
        {
            //cout << "error when creating...  ";
            throw 1;
        }
        
    }

    int get_end_section()
    {
        return end_section;
    }

    void print()
    {
        //printf("%s,  %d,   %d,   %d,   %d\n", requester_name.c_str(), start_section, 
        //end_section, is_request_on_write, time);
        cout << requester_name << "   " << start_section << "   " << end_section << "   ";
        cout << is_request_on_write << "   " << time << endl;

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

    void print()
    {
        data->print();
    }

};


class Programm
{
public:
    string programm_name;
    Register *head;
    int time_start_programm;
    
    Programm(const string name, const int time_start_programm=0)
    {
        this->programm_name = name;
        this->time_start_programm = time_start_programm;
        Request *R = new Request("zero_request", 0, 1, 0); //вспомагательный "нулевой" элемент
        head = new Register(R);
        
    }

    string get_programm_name()
    {
        return programm_name;
    }
    
    int add_register_to_programm(Register *R)
    {
        Register *p = head;
        while(p->next != NULL)
        {
            //cout << "\n" << endl;
            //printf("%d %d   ", R->data->get_start_section(), p->next->data->get_start_section());
            if(*(R->data) > *(p->next->data))
            {
                //cout << "if" << endl;
                p=p->next;
            }
            else
            {   
                //cout << "else" << endl;
                break;
            } 
        } 
        R->next = p->next;
        p->next = R;
        return 0;
    }

    int delete_reqister_from_programm(Register *R)
    {
        Register *p = head;
        while(p->next != NULL)
        {
            if(p->next == R)
            {
                Register *y = R->next;
                delete(R);
                p->next = y;
                return 0;
            }
        }
        return 1;//такого регистра в программе нет
    }



    void print()
    {
        cout << "programm_name = " << programm_name << ", start program at " << time_start_programm << "\n" << endl;
        cout << "requester_name, start_section, is_request_on_write, time" << endl;
        Register *p = head;
        while(p != NULL)
        {
            p->data->print();
            p=p->next;
        }   
    }


    

};



int disk_request(int real_time, int is_on_read, Programm* current_programm, 
                vector <multimap <int, Programm*> > &disk_vector, 
                multimap <Programm*, Programm*> &wait_map, Register *p);

int model(vector <Programm*> &programm_vector);
int delete_programm_if_it_empty(Programm* current_programm, vector <multimap <int, Programm*> > &disk_vector, vector <Programm*> &programm_vector);
int is_deadlock(multimap <Programm*, Programm*> wait_map);



