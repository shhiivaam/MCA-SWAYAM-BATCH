#include <iostream>
#include <string>
using namespace std;
class Person {
public:
    string name;
    int age;
};
class Mohan : public Person {
public:
    void MyName(string name) {
        this->name = name;
    }

    void showName() {
        cout << "My name is " << this->name << endl;
    }
};

int main() {
    Mohan mo;
    mo.MyName("Mohan Kumar");
    mo.showName();
    return 0;
}