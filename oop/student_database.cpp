#include<iostream>
#include<string.h>
using namespace std;

class private_details{
    public:
    long int contact_number;
    long int telephone_number;
    long int driving_license_number;
    public:
    friend class studemts;
};

class students{
    private_details p;

    private:
    string name;
    int roll_no;
    string Class;
    int division;
    string DOB;
    string blood_group;

    public:
    static int count;
    students(){
        count++;
        name = "ABC";
        roll_no = 123;
        Class = "SE";
        division = 2;
        DOB = "01/01/01";
        blood_group = "A+";
    }

    students(students & s){
        name = s.name;
        roll_no = s.roll_no;
        Class = s.Class;
        division = s.division;
        DOB = s.DOB;
        blood_group = s.blood_group;
    }

    students(string name,int roll_no,string Class,int division, string DOB, string blood_group,long int contact_number,long int telephone_number,
    long int driving_license_number){
        this->name = name;
        this->roll_no = roll_no;
        this->Class = Class;
        this->division = division;
        this->DOB = DOB;
        this->blood_group = blood_group;
        p.contact_number = contact_number;
        p.driving_license_number = driving_license_number;
        p.telephone_number = telephone_number;
    }
    static int getcount(){
        return count;
    }
    void getdetails(private_details & a){
        cout<<"enter name: "<<endl;
        cin>>name;
        cout<<"enter roll no: "<<endl;
        cin>>roll_no;
        cout<<"enter Class: "<<endl;
        cin>>Class;
        cout<<"enter division: "<<endl;
        cin>>division;
        cout<<"enter DOB: "<<endl;
        cin>>DOB;
        cout<<"enter blood group: "<<endl;
        cin>>blood_group;
        cout<<"enter contact number: "<<endl;
        cin>>a.contact_number;
        cout<<"enter driving license number: "<<endl;
        cin>>a.driving_license_number;
        cout<<"enter telephone number: "<<endl;
        cin>>a.telephone_number;
    }
    void displaydetails(private_details & t){
        cout<<"name: "<<name<<endl;
        cout<<"roll no: "<<roll_no<<endl;
        cout<<"Class: "<<Class<<endl;
        cout<<"division: "<<division<<endl;
        cout<<"DOB: "<<DOB<<endl;
        cout<<"blood group: "<<blood_group<<endl;
        cout<<"contact number: "<<t.contact_number<<endl;
        cout<<"driving license number: "<<t.driving_license_number<<endl;
        cout<<"telephone number: "<<t.telephone_number<<endl;
    }
    ~students(){
        cout<<"object destructed"<<endl;
        count--;
    }
};

int students::count=0;

int main()
{
    int n;
    cout<<"enter number of students: ";
    cin>>n;
    private_details x;
    students s1;

    s1.displaydetails(x);
     
    students s2= s1;
    s2.displaydetails(x);

    students *s;
    s = new students[n];

    for (int i=0;i<n;i++){
        s[i].getdetails(x);
        s[i].displaydetails(x);
    }
    delete []s;
    cout<<"number of students: "<<students::getcount();
    return 0;
 
}