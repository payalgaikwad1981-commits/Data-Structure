#include<iostream>
#include<string>
#include<limits>
using namespace std;
struct patient
{
int id;
string name;
int age;
string name;
string deasease;
patient*next;
patient*hashNext;
};
Patient*head = NULL;
const int SIZE = 10;
Patient*hashTable[SIZE] = {NULL};
int hashFunction(int id)
{
  return id%SIZE;
}
patient*p = newPatient()
cout<<"Enter Patient ID: "; cin>>p->id;
int index = hashFunction(p->id);
Patient*temp = hashTable[index];
while(temp!= NULL)
{
 if (temp->id = id)
{
 cout<<"\nPatient Found:\n";
 cout<<"ID: "<<temp->id<<endl;
 cout<<"Name: "<<temp->name<<endl;
 cout<<"Age: "<<temp->age<<endl;
 cout<<"Diease: "<<temp->disease<<endl;

return;
}

temp = temp->hashNext;
}
cout<<"patient not found!\n";
}
void displayPatient()
{
  Patient*temp = head;

if (temp ==NULL)
{
 cout<<"No patient records avaliable;\n";

return;
}

cout<<"\n---All Patient Records---\n";
while(temp !=NULL)
{
 cout<<"\nPatient ID: "<<temp->id<<endl;
 cout<<"Name: "<<temp->name<<endl;
 cout<<"Age: "<<temp->age<<endl;
 cout<<"Diesease:"<<temp->diesease<,endl;
temp = temp->next;
}
}

int main()
{
  int choice;

do
{
cout<<"\n----Hospital Management Syatem----\n";
cout<<"1. Register Patient:\n";
cout<<"2. Search Patient:\n";
cout<<"3. Display All Patients:\n";
cout<<"4. Exit\n";
cin>>choice;

switch (choice)
{
case 1:
    registerPatient();
    break;
case 2:
searchPatient();
break;
case 3:
displayPatient();
break;
case 4:
cout<<"Exitng Program...\n";
brak;

default:
cout<<"Invalid choice:\n";
}
}
  while)choice !=4);
return 0;
}
