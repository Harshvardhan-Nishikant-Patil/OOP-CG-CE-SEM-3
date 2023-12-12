#include<iostream>
using namespace std;

class publication{
    protected:
    string title;
    float price;

    public:
    publication(){
        title = "ABC";
        price = 0.0;
        cout<<"this is publication constructer"<<endl;
    }

    void getdetails(){
        cout<<"enter title: ";
        cin>>title;
        cout<<"enter price: ";
        cin>>price;
    }

    void displaydetails(){
        cout<<"title: "<<title<<endl;
        cout<<"price: "<<price<<endl;
    }
    ~publication(){
        cout<<"this is publication destructor";
    }
};

class book:public publication{
    private:
    int page_count;

    public:
    book():publication(){
        page_count = 0;
        cout<<"book class constructor"<<endl;
    }
    void getdetails(){
        cout<<"enter total number of pages: ";
        cin>>page_count;
    }
    void displaydetails(){
        cout<<"total number of pages of book are: "<<page_count<<endl;
    }

    ~book(){
        cout<<"this is book class destructor"<<endl;
    }
};

class tape:public publication{
    private:
    int time_count;

    public:
    tape():publication(){
        time_count = 0;
        cout<<"tape class constructor"<<endl;
    }
    void getdetails(){
        cout<<"enter total play time: ";
        cin>>time_count;
    }
    void displaydetails(){
        cout<<"total play time: "<<time_count<<endl;
    }

    ~tape(){
        cout<<"this is tape class destructor"<<endl;
    }
};

int main()
{
    book b1;
    tape t1;

    cout<<"book: ";
    b1.getdetails();
    cout<<"tape: ";
    t1.getdetails();
    cout<<"book: ";
    b1.displaydetails();
    cout<<"tape: ";
    t1.displaydetails();
    return 0;
}