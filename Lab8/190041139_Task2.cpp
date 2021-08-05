#include <iostream>
#include <vector>
#define ll long long 
using namespace std;

class Lab{
    string labName;
    int capacity;
public:
    Lab(string N="",int c=0){
        labName = N;
        capacity = c;
    }
    
    string getLabName(){ return labName; }
    int getCapacity(){ return capacity; }
    void setLabName(string s){ labName=s; }
    void setCapacity(int c){ capacity=c; }
    void show(){
        cout<<labName<<" "<<capacity<<" capacity\n";
    }
};

class LecturerRoom{
    string roomName;
    int roomNo,capacity;
public:
    LecturerRoom(string name="",int no=0,int c=0){
        roomName = name;
        roomNo = no;
        capacity = c;
    }

    string getRoomName(){ return roomName; }
    int getRoomNo() { return roomNo; }
    int getCapacity() { return capacity; }
    void setRoomName(string s){ roomName=s; }
    void setRoomNo(int n) { roomNo=n; }
    void setCapacity(int c) { capacity=c; }
    void show(){
        cout<<roomName<<" "<<roomNo<<" "<<capacity<<" capacity\n";
    }
};


class N28Building{
    vector<Lab>labList;
    vector<LecturerRoom>lecturerRoomList;
public:
    void addLab(Lab a){ labList.push_back(a); }
    void addLecturerRoom(LecturerRoom a){
        lecturerRoomList.push_back(a);
    }

    void showAllLabs(){
        cout<<"Showing all Labs : "<<"\n";
        for(auto i:labList) i.show();
    }

    void showAllLecturerRooms(){
        cout<<"Showing all Lecturer Rooms : "<<"\n";
        for(auto i:lecturerRoomList) i.show();
    }
};

int main(){
    Lab lab1("Chemistry",60),lab2("Physics",60),
        lab3("Math",50),lab4("Biology",50);
    LecturerRoom lecturerRoom1("Hassan",102,3),
                 lecturerRoom2("Rudhra",105,3),
                 lecturerRoom3("Mukhles",202,3),
                 lecturerRoom4("Hiesenbarg",208,3);

    N28Building Building;
    
    Building.addLab(lab1);  
    Building.addLab(lab2);  
    Building.addLab(lab3);  
    Building.addLab(lab4);  

    Building.addLecturerRoom(lecturerRoom1);
    Building.addLecturerRoom(lecturerRoom2);
    Building.addLecturerRoom(lecturerRoom3);
    Building.addLecturerRoom(lecturerRoom4);

    Building.showAllLabs();
    cout<<string(30,'-')<<"\n";
    Building.showAllLecturerRooms();

}
