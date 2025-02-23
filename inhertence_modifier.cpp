#include <iostream>
using namespace std;

// Public members of the base class → Protected in the derived class.
// Protected members of the base class → Protected in the derived class.
// Private members of the base class → Never accessible.


class Animal {
public:
    void eat() { cout << "Animal eats" << endl; }  // Public
protected:
    void sleep() { cout << "Animal sleeps" << endl; }  // Protected
private:
    void breathe() { cout << "Animal breathes" << endl; }  // Private
};

class Dog : protected Animal {
public:
    void show() {
        eat();    // ✅ Allowed: Public → Protected
        sleep();
        //breathe();
    }
};

int main() {
    Dog d;
    // d.eat();    // ❌ Error: eat() is now protected.
    // d.sleep();  // ❌ Error: sleep() is now protected.
    Animal a;
    a.eat(); // its work here because eat is public
    //a.sleep(); // not work here because sleep is protected

    d.show();      // ✅ Works because it's within the class.
    return 0;
}



// Base Class Access 	Original in Animal	   After Protected Inheritance in Dog	  Accessible in show()?	    Accessible in main()?
// eat()             	Public                 	Protected	                            ✅ Yes (inside Dog)	❌ No (outside Dog)
// sleep()            	Protected	            Protected	                            ✅ Yes (inside Dog)	❌ No (outside Dog)
// breathe()	        Private                	Not Inherited	                          ❌ No	             ❌ No


// https://chatgpt.com/share/67bafbad-b5b8-800f-99b1-5182f05c1d02