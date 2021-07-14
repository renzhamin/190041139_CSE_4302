#include <bits/stdc++.h>
#define ll long long 
using namespace std;

class Coordinate{
    double x,y;
public:
    Coordinate(double _x=0,double _y=0):x(_x),y(_y) {}
    ~Coordinate() {}

    double getDistance(const Coordinate &b) const {
        return sqrt((x-b.x)*(x-b.x)+(y-b.y)*(y-b.y));
    }

    double getDistance() const {
        return getDistance(Coordinate(0,0));
    }

    void move_x(double v){
        x+=v;
    }
    void move_y(double v){
        y+=v;
    }
    void move(double v){
        move_x(v); move_y(v);
    }
    Coordinate operator ++ () {
        return Coordinate(++x,++y);
    } 

    Coordinate operator ++ (int) {
        return Coordinate(x++,y++);
    }

    Coordinate operator -- () {
        return Coordinate(--x,--y);
    } 

    Coordinate operator -- (int) {
        return Coordinate(x--,y--);
    }

    bool operator == (Coordinate c) {
        return getDistance(*this) == getDistance(c);
    }

    bool operator != (Coordinate c) {
        return getDistance(*this) != getDistance(c);
    }

    bool operator <= (Coordinate c) {
        return getDistance(*this) <= getDistance(c);
    }

    bool operator >= (Coordinate c) {
        return getDistance(*this) >= getDistance(c);
    }

    bool operator > (Coordinate c) {
        return getDistance(*this) > getDistance(c);
    }

    bool operator < (Coordinate c) {
        return getDistance(*this) < getDistance(c);
    }

    void display(){
        cout<<"(x,y) = "<<"("<<x<<","<<y<<")\n";
    }
};

int main(){
    Coordinate a(sqrt(2),sqrt(2)),b(1,1);
    cout<<a.getDistance(b)<<"\n";
}
