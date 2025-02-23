#include <stdio.h>
#include <iostream>

using namespace std;

class chai{
    private:
    string name;
    int total;

    public:
    chai(string n,int t){
        name = n;
        total = t;
    }
    friend bool compare(chai &c1, chai &c2);
};

bool compare(chai &c1, chai &c2){
    return c1.total> c2.total;
}

int main(){
    chai c1("chai1",100);
    chai c2("chai2",20);
    cout<<compare(c1,c2)<<endl;
    
    //cout<<king->name<<endl; // here give me error that name is private or not accessible
}
