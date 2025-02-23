#include <iostream>
#include <string.h>

using namespace std;

class Tea{
    public:
    virtual void prepare()= 0;
    virtual void serve()=0;

    void makeTea(){
        prepare();
        serve();
    }
};

class GingerTea : public Tea{
    public:
    void prepare() override{
        cout<<"Ginger tea is being prepared"<<endl;
    }

    void serve() override{
        cout<<"Ginger tea is being served"<<endl;
    }
};

class MasalaTea: public Tea{
    public:
    void prepare() override{
        cout<<"Masala tea is being prepared"<<endl;
    }
    void serve() override{
        cout<<"Masala tea is being served"<<endl;
    }
};

int main(){
    GingerTea greenTea;
    greenTea.makeTea();

    MasalaTea masalaTea;
    masalaTea.makeTea();
}