#include <iostrem>
using namespace std;

int main()
{
  int queue[5];
  int front = 0;
  int rear = 0;
  
// add orders 
	cout <<"enter 5 customer order numbers:\n";
    
    for(int i =0;i <5; i++)
         {
           cin >> queue[rear];
           rear ++;
         }
         
// process orders
   cout <<"\n processing orders;\n";
   
while (front < rear)
     {
        count <<"processing order:" <<queue[front]<<endl;
        front++;
      }
      return 0;
     }
