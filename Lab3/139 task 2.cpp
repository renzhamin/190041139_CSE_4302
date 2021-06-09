#include <iostream>
using namespace std;

class RationalNumber {
    private:
        int numerator, denominator;
    public:
        void assign(int Numerator, int Denominator) {
            if (Denominator == 0) {
                cout<<"denominator cant be 0"<<"\n";
                return;
            numerator = Numerator;
            denominator = Denominator;
        }

        double convert() {
            return numerator/(double)denominator;
        }

        void invert() {
            if(numerator==0){
                cout<<"invalid operation"<<"\n";
                return;
            }
            swap(numerator, denominator);
        }

        void print() {
            cout << "The Rational Number is " << numerator << "/" << denominator << "\n";
        }
};

int main() {
    RationalNumber x;
    x.assign(3, 2);
    cout << x.convert() << "\n";
    x.print();
    x.invert();
    x.print();
}
