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
        //cout << R.requester_name <<" " << R.start_section <<" " << R.end_section <<" " << R.type_request << endl;
        if(R.requester_name==str[i]&&R.start_section==n_good[i]&&R.end_section==e_good[i]&&R.type_request==b[i])
        {
            cout << "Success!" << endl;
        }
        else
        {
            cout << "Error in test " << i << endl;
        }
        //if(R.end_section==n_good[i])
        //cout << R.end_section << n_good[0] <<endl;
    }

    


    return 0;


}

