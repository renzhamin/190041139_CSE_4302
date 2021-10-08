#include <iostream>
#include <fstream>
#include <iostream>
#include <typeinfo>
using namespace std;
const int LEN = 32;  
const int MAX = 100;

enum StudentType{
    School,UnderGrad
};

class Student{
private:
    char Name[LEN];
    char Fathers_Name[LEN];
    char Mothers_Name[LEN];
    static int n;
    static Student *list[MAX];

public:
    virtual void getdata() {
        cin.ignore(10, '\n');
        cout << " Enter Student name : ";
        cin >> Name;
        cout << " Enter Fathers name : ";
        cin >> Fathers_Name;
        cout << " Enter Mothers Name : ";
        cin >> Mothers_Name;
    }
    virtual void putdata() {
        cout << "\n Name : " << Name<<"\n Fathers Name: "<<Fathers_Name;
        cout << "\n Mothers Name : " << Mothers_Name;
    }
    virtual StudentType get_type();
    static void add();                
    static void display();            
    static void read();               
    static void write();              
};
int Student::n;
Student *Student::list[MAX];

class SchoolStudent: public Student {
private:
    int Roll;
    int ClassNo;

public:
    void getdata() {
        Student::getdata();
        cout << " Enter Roll: ";
        cin >> Roll;
        cout << " Enter Class: ";
        cin >> ClassNo;
    }
    void putdata() {
        Student::putdata();
        cout << "\n Roll: " << Roll;
        cout << "\n Class: " << ClassNo;
    }
  
};

class UnderGradStudent: public Student {
private:
    int Roll;
    char dept[LEN];

public:
    void getdata() {
        Student::getdata();
        cout << " Enter Roll: ";
        cin >> Roll;
        cout << " Enter Department: ";
        cin >> dept;
    }
    void putdata() {
        Student::putdata();
        cout << "\n Roll: " << Roll;
        cout << "\n Department: " << dept;
    }
  
};

StudentType Student::get_type()
{
    if (typeid(*this) == typeid(SchoolStudent))
        return School;
    else if (typeid(*this) == typeid(UnderGradStudent))
        return UnderGrad;
    else {
        cerr << "\nBad Student type";
        exit(1);
    }
}

void Student::add(){
    char ch;
    cout << "'s' to add a School Student"
    "\n'u' to add a UnderGrad Student"
    "\nEnter selection : ";
    cin >> ch;
    switch (ch)
    { //create specified Student type
    case 's':
        list[n] = new SchoolStudent;
        break;
    case 'u':
        list[n] = new UnderGradStudent;
        break;
    default:
        cout << "\nUnknown Student type\n";
        return;
    }
    list[n++]->getdata();
}

void Student::display(){
    for (int j = 0; j < n; j++) {
        switch (list[j]->get_type()) {
        case School:
            cout << "Type : SchoolStudent";
            break;
        case UnderGrad:
            cout << "Type : UnderGradStudent";
            break;
        default:
            cout << "Unknown type";
        }
        list[j]->putdata();
        cout << endl;
    }
}

void Student::read()
{
    int size;            
    StudentType ptype;
    ifstream inf;       
    inf.open("Student.DAT", ios::binary);
    if (!inf) {
        cout << "\nCan't open file\n";
        return;
    }
    n = 0;
    while (true)
    { 
        inf.read((char *)&ptype, sizeof(ptype));
        if (inf.eof()) 
            break;
        if (!inf) {
            cout << "\nCan't read type from file\n";
            return;
        }
        switch (ptype){              
        case School: 
            list[n] = new SchoolStudent;
            size = sizeof(SchoolStudent);
            break;
        case UnderGrad:
            list[n] = new UnderGradStudent;
            size = sizeof(UnderGradStudent);
            break;
        default:
            cout << "\nUnknown type in file\n";
            return;
        } 
        inf.read((char *)list[n], size);
        if (!inf) {
            cout << "\nCan't read data from file\n";
            return;
        }
        n++; 
    }        
    cout << "Reading " << n << " Student(s)\n";
}

void Student::write()
{
    int size;
    cout << "Writing " << n << " Students\n";
    ofstream ouf;
    StudentType ptype; 
    ouf.open("Student.DAT", ios::trunc | ios::binary);
    if (!ouf) {
        cout << "\nCan't open file\n";
        return;
    }
    for (int j = 0; j < n; j++) //for every Student object
    {                           //get its type
        ptype = list[j]->get_type();
        //write type to file
        ouf.write((char *)&ptype, sizeof(ptype));
        switch (ptype) {
        case School:
            size = sizeof(SchoolStudent);
            break;
        case UnderGrad:
            size = sizeof(UnderGradStudent);
            break;
        }
        ouf.write((char *)(list[j]), size);
        if (!ouf) {
            cout << "\nCan't write to file\n";
            return;
        }
    }
}

int main(){
    char ch;
    while (true) {
        cout << "'a' -- add data for a Student"
                "\n'd' -- display data for all Students"
                "\n'w' -- write all Student data to file"
                "\n'r' -- read all Student data from file"
                "\n'x' -- exit"
                "\nEnter selection: ";
        cin >> ch;
        switch (ch) {
        case 'a':
            Student::add();
            break;
        case 'd':
            Student::display();
            break;
        case 'w':
            Student::write();
            break;
        case 'r':
            Student::read();
            break;
        case 'x':
            exit(0);
        default:
            cout << "\nUnknown command";
        }
    }     
}
