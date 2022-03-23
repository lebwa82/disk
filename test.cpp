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
    int i;

    for(i=0; i< sizeof(n)/sizeof(int); i++)
    //for(i=0; i< 1; i++)
    {
        Request R=Request(str[i], n[i], e[i], b[i]);
        //cout << R.requester_name <<" " << R.start_section <<" " << R.end_section <<" " << R.is_request_on_write << endl;
        if(R.requester_name==str[i]&&R.start_section==n_good[i]&&R.end_section==e_good[i]&&R.is_request_on_write==b[i])
        {
            cout << "Success!" << endl;
        }
        else
        {
            cout << "Error in test " << i << endl;
        }
    }

        Request R0 = Request(str[0], n[0], e[0], b[0]);
        Request R1 = Request(str[1], n[1], e[1], b[1]);
        if(R0 > R1) 
        {
            cout << "Success!" << endl;

        } 
        else { cout << "Error in test " << i << endl; }
    
    return 0;
}

int add_register(Register *head, Register *R)
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




int programm(Register *head)
{
    if(head->next == NULL)
    {
        return 0;
    }

    Register *p = head->next;

    //TO DO



}