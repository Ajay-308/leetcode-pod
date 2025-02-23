
#include <iostream>

using namespace std;

class calculator{
    public:
    virtual void show() = 0;
    // compile time polymorphism  --> constructor overloading , function overlading
    //example of constructor overloading

    calculator(){
        cout<<"i am non parameterized constructor"<<endl;
    }
    calculator(int a){
        cout<<"i am parameterized constructor"<<endl;
    }
    // function overloading --> same function name but different paramerters

    int add(int a, int b) {
        return a+b;
    }

    float add(float a, float b){
         return a+b;
    }

    int add(int a, int b,int c){
        return a+b+c;
    }
};

class Derived : public calculator{
    public:
    void show() override{
        cout<<"i am virtual"<<endl;
    }
};

int main(){
    Derived cal;

    cout<< cal.add(1,2)<<endl;
    cout<< cal.add(5.5f,6.56f)<<endl;
    cout<<cal.add(2,3,4)<<endl;

    cal.show();

}