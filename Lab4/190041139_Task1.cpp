#include <iostream>

using namespace std;

class Calculator {
    private:
        int val;
    public:
        Calculator() : val(0) {}
        Calculator(int input_value) : val(input_value) {}
        ~Calculator() {cout << "Calculator object is destroyed.\n";}
        int getinput_value() {return val;}
        void setvalue(int input_value) {val = input_value;}
        void add(int input_value) {val += input_value;}
        void subtract(int input_value) {val -= input_value;}
        void multiply(int input_value) {val *= input_value;}
        void divideBy(int input_value) {
            if (input_value == 0) {
                cout << "cant be devided by 0.\n";
            } else {
                val /= input_value;
            }
        };
        void clear() {val = 0;}
        void display() {
            cout << "Calculator display: " << val << "\n";
            cout<<string(50,'-')<<"\n";
        }
};

int main() {
    Calculator c;
    c.add(10);
    c.display();
    c.subtract(7);
    c.display();
    c.multiply(4);
    c.display();
    c.divideBy(2);
    c.display();
    c.clear();
    c.display();
}
