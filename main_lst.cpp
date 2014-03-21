#include <iostream>
 
#include "List.h"
using namespace std; 

void main()

  
{
        List<int> list;
		int n;
		int val;
		for (int id = 0; id< n ; id++)
		{
			cin>>val;
			list.push_back(val);
		}
        
       
       
        list.print();
        
        system("pause");
}