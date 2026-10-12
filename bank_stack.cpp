#include<iostream>
using namespace std;

int main() {
  int stack[5];
  int top = -1;

cout <<"Enter 5 recently sarved customers token numbers:\n";

for(int i =0;i<5;i++)
{
  cin >> stack[++top];
}
  cout <<"\nservice history of the customers:\n";

while (top>=0)
{
  cout << stack[top]<<endl;
  top--;
}

return 0;
}
