#include <iostream>
#include<fstream>
using namespace std;

class Person
{

    public:
        int roll_no;
        string name;

        Person()
        {
            roll_no = 0;
            name = "";
        }

        void accept()
        {
            cout<<"Enter student name : "<<endl;
            getline(cin,name);
            cout<<"Enter roll : ";
            cin>>roll_no;
        }
};

int main()
{
Person p;
fstream f;

    int n,i;
    cout<<"Enter number of students : ";
    cin>>n;
   
    cin.ignore(1);
   
    f.open("New_file.txt",ios::out);
    for(i=0;i<=n-1;i++)
    {
        cout<<"\nEnter data for student "<<i+1<<" : ";
        p.accept();
    f<<"\nName : "<<p.name;
    f<<"\nRoll no : "<<p.roll_no;
    cin.ignore(1);
    }
    f.close();

f.open("New_file.txt",ios::in);
char x;
while(f.get(x))
{
cout<<x;
}
f.close();

return 0;
} 
