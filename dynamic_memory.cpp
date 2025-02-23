
#include <stdio.h>
#include <iostream>

using namespace std;

//creating a class
 class Box{
    public :
    int length;
    char level;
 };

int main(){
    Box a;
    a.length = 10;
    a.level= 'A';
    cout<< a.level<<endl;
    Box *king = new Box();
    king -> length=20;
    cout<< king->length<<endl;
    // other way to access the value of pointer
    cout<<(*king).length<<endl;

}