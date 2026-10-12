#include<iostream>
using namespace std;

int main(){
int queue[5];
int front = 0;
int rear = 0;
cout<<"Enter Token Numbers Of 5 Customers:\n";

for(int i =0; i <5; i++){
    cin >> queue[rear];
    rear ++;}

cout<<"\n token numbers:\n";
while (front <rear)
{
  cout<<"token numbers:" <<queue[front]<<endl;
  front++;
}
return 0;
}
