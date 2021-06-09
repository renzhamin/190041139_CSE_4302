#include <iostream>
using namespace std;

class Counter{
    private:
        int count, increment_steps;
    public:
        Counter() : count(0), increment_steps(0) {}

        void setIncrementStep(int step_val) {
            increment_steps = step_val;
        }

        int getCount() {
            return count;
        }

        void increment() {
            count += increment_steps;
        }

        void resetCount() {
            count = 0;
        }
};

int main() {
    Counter counter;
    counter.setIncrementStep(5);
    cout << counter.getCount() << "\n";
    counter.increment();
    cout << counter.getCount() << "\n";
    counter.resetCount();
    cout << counter.getCount() << "\n";
}
