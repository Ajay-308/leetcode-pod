// Encapsulation is a way to restrict the direct access to some components of an object, so users cannot access state values for all of the variables of a particular object. 

# include <iostream>

using namespace std;

class BankAccount{
    private:
    int accountNumber;
    int balance;

    public:
    BankAccount(int a , int b){
        accountNumber = a;
        balance = b;
    }

    void deposit(int amount){
        if(amount>0){
            balance += amount;
            cout<<"Amount deposited successfully"<<endl;
        }
        else{
            cout<<"Invalid amount"<<endl;
        }
    }

    void withdraw(int amount){
        if(amount>0 && amount<=balance){
            balance -= amount;
            cout<<"Amount withdrawn successfully"<<endl;
        }
        else{
            cout<<"Invalid amount"<<endl;
        }
    }

    void display(){
        cout<<"account number:"<<accountNumber<<endl;
        cout<<"balance:"<<balance<<endl;
    }
};

int main(){
    BankAccount B1(1234,1000);
    B1.deposit(500);
    B1.display();
}