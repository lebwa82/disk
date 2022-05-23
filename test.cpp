#include <iostream>
#include <string> 
#include "header.h"


int test1()
{
    string str[]={"programm1","abc", "123", "qwerty"};
    int n[]={3,25,-1, 12};
    int e[]={5, -2, 7, 134};
    int b[]={0,0,1, 1};
    int n_good[]={3,-1,-1, 12};
    int e_good[]={5, -1, -1, 134};
    string time[]={"1","2","3","4","5"};
    int i;
    int count=0;
    printf("Test1:\n");
    for(i=0; i< sizeof(n)/sizeof(int); i++)
    {
        try
        {
            Request *R= new Request(str[i], n[i], e[i], b[i], time[i]);
            //cout << R.requester_name <<" " << R.start_section <<" " << R.end_section <<" " << R.is_request_on_write << endl;
            if(R->requester_name==str[i]&&R->start_section==n_good[i]&&R->end_section==e_good[i]&&R->is_request_on_write==b[i])
            {
                //cout << "Success!" << endl;
            }
            else
            {
                cout << "Error in test " << i << endl;
                //printf("%s == %s\n", R->requester_name, str[i]);
                //printf("%d == %d\n", R->start_section,n_good[i]); 
                //printf("%d == %d\n", R->end_section,e_good[i]);
                //printf("%d == %d\n", R->is_request_on_write, b[i]);
            }

        }
        catch(exception)
        {
            //cout << "Error in creating";
        }
    }
    
    Request *R0 = new Request(str[0], n[0], e[0], b[0]);
    Request *R1 = new Request(str[1], n[1], e[3], b[0]);

    if(*R1 < *R0) 
    { 
        cout << "Error in test " << i << endl; 
    }
    return 0;
}


int test2()
{
    int i;

    map <char, Programm*> mp1;
    vector <map <char, Programm*> > dick_vectorl;
    //vector <Programm*> vector_programm;
    string strp[]={"request1_programm1","request2_programm1", "request4_programm1", "request3_programm1", "request5_programm2"};
    int start[]={3,1,5,10,15};
    int end[]={7,8,9,12,21};
    bool write[]={0,0,1,0,1};
    string t[]={"2","3","5","7","8"}; 

    string name="programm1";
    Programm *Programm1 = new Programm(name);

    for(i=0; i<5; i++)
    {
        Request *Request1= new Request(strp[i], start[i], end[i], write[i], t[i]);
        Register *Register1= new Register(Request1);
        Programm1->add_register_to_programm(Register1);
    }

    //Programm1->print();
    printf("Test2:\n");
    if(Programm1->programm_name!=name) printf("Error in test 0");
    i=0;
    Register *p = Programm1->head;
    while(p!=NULL)
    {
        i++;
        p=p->next;
    }
    if(i!=6) printf("Error in add Registers");
    Programm1->delete_reqister_from_programm(Programm1->head->next);
    Programm1->delete_reqister_from_programm(Programm1->head->next);
    i=0;
    p = Programm1->head;
    while(p!=NULL)
    {
        i++;
        p=p->next;
    }
    if(i!=4) printf("Error in delete Registers. i must be 4 and i=%d", i);


    //Programm1->print();
    vector <Programm*> programm_vector;
    printf("size = %d\n", programm_vector.size());
    programm_vector.push_back(Programm1);
    printf("size = %d\n", programm_vector.size());
    programm_vector[0]->print();
    model(programm_vector);


    return 0;
}


