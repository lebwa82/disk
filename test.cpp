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
        catch(int e)
        {

        }
    }
    
    Request *R0 = new Request(str[0], n[0], e[0], b[0]);
    Request *R1 = new Request(str[1], n[1], e[3], b[0]);

    if(*R1 >= *R0) 
    {
        //cout << "Success!" << endl;
    } 
    else { cout << "Error in test " << i << endl; }
    
    return 0;
}



