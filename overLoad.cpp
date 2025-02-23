#include <iostream>

using namespace std;

class calculator{
    public:
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

int main(){
    calculator cal;

    cout<< cal.add(1,2)<<endl;
    cout<< cal.add(5.5f,6.56f)<<endl;
    cout<<cal.add(2,3,4)<<endl;
}