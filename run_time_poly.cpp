
#include <iostream>

using namespace std;

// run time polymorphism -->  
// 
class Tea{
    public:
    void prepare(){
        cout<<"Tea is being prepared"<<endl;
    }
    void serve(){
        cout<<"tea is being served"<<endl;
    }
};

class GingerTea : public Tea{
    public:
    void prepare(){
        cout<<"ginger tea is being prepared"<<endl;
    }
};

int main(){
    GingerTea greenTea;
    greenTea.prepare();

}