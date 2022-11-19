#include<bits/stdc++.h>
// #include<fstream>
#include<windows.h>
#include<conio.h>
using namespace std;
void delay()
{
    for(int i=0;i<3;i++)
    {
		cout<<".";
		Sleep(1000);
	}
}
class Bank
{
    private:
        int account_no;
        string first_name;
        string last_name;
        int balance;
        static map<int,Bank> accounts;
        static int next_account;
        int pin;
    public:
        Bank()
        {
            account_no=0;
            balance=0;

        }
        int get_account_no()
        {
            return account_no;
        }

        void open_account();
        void balance_enquiry(int account_no);
        void deposit(int account_no,int amount);
        void withdraw(int account_no,int amount);
        void store(Bank p);
        void display(Bank p);
        void display(int account_no);
        void display_all();
        bool creat_pin();
        bool pin_verify(int);
        void delete_account(int);
        static bool admin_verification();

};
int Bank::next_account=0;
map<int,Bank>Bank::accounts;
void Bank::open_account()
{
    int flag=3;
    Bank new_account;
    cout<<"Enter your First Name:";
    cin>>new_account.first_name;
    cout<<"Enter your Last Name:";
    cin>>new_account.last_name;
    label:

    cout<<"Enter depositing amount:";
    cin>>new_account.balance;
    if(new_account.balance>=500)
    {
        next_account++;
        new_account.account_no=next_account;
        if(new_account.creat_pin())
        {
            
            new_account.store(new_account);
            cout<<"\t\tYour new account is creating please wait";
            delay();
            cout<<"\nCongratulation your account has been created!!";
            cout<<"Here are your details:\n\n";
            new_account.display(new_account.get_account_no());
            cout<<"Press any key to continue";
            getch();
      
            
			
        }


    }
    else
    {
        cout<<"Enter Initial Amount greater than 500\n";
        flag--;
        if(flag>0)
            goto label;
        cout<<"Sorry try Again1";
    }


}
void Bank::balance_enquiry(int account_no)
{

    map<int,Bank>::iterator itr=accounts.find(account_no);
    if(accounts.find(account_no)!=accounts.end())
    {
        if(pin_verify(account_no))
        {
            cout<<"Here are your details:\n\n";
            display(account_no);
            cout<<"Press any key to continue";
            getch();
        }
        else
        {    
            cout<<"Try Again\n";
            cout<<"Press any key to continue";
            getch();
        }
    }
    else
    {
        cout<<"Account don't exist\n";
        cout<<"Try again";
        cout<<"Press any key to continue";
        getch();
    }


}
void Bank::deposit(int account_no,int amount)
{
    map<int,Bank>::iterator itr=accounts.find(account_no);
    if(accounts.find(account_no)!=accounts.end())
    {
        if(pin_verify(account_no))
        {
            itr->second.balance+=amount;
            cout<<"Here are your details:\n\n";
            display(account_no);
            cout<<"Press any key to continue";
            getch();

        }
        else{
            cout<<"Try Again\n";
            cout<<"Press any key to continue";
            getch();
        }
    }
    else
    {
        cout<<"Account don't exist\n";
        cout<<"Try again";
         cout<<"Press any key to continue";
        getch();
    }
}
void Bank::withdraw(int account_no,int amount)
{
    map<int,Bank>::iterator itr=accounts.find(account_no);

    if(accounts.find(account_no)!=accounts.end())
    {
        if(pin_verify(account_no))
        {
            amount= itr->second.balance-amount;
            if(amount<0){
                cout<<"Insufficient Balance";
                cout<<"Press any key to continue";
                getch();
            }
            
            else
            {
                itr->second.balance=amount;
                cout<<"Here are your details:\n";
                display(account_no);
                 cout<<"Press any key to continue";
                 getch();
            }
        }
        else{
                cout<<"Try Again";
        }
    }
    else
    {
        cout<<"Account don't exist\n";
        cout<<"Try again";
        cout<<"Press any key to continue";
        getch();
    }

}
void Bank::delete_account(int account_no)
{
    map<int,Bank>::iterator itr=accounts.find(account_no);
    if(accounts.find(account_no)!=accounts.end())
    {
        if(pin_verify(account_no))
        {
            accounts.erase(account_no);
            cout<<"Removing your account please wait";
            delay();
            cout<<"Your account has been removed";
            getch();
            
        }
        else{
            cout<<"Try Again";
            cout<<"Press any key for home page";
            getch();
        }
    }
    else
    {
        cout<<"Account don't exist\n";
        cout<<"Try again";
        getch();
    }


}
void Bank::store(Bank p)
{
    accounts.insert({p.get_account_no(),p});

}
void Bank::display(int account_no)
{
    map<int,Bank>::iterator itr=accounts.find(account_no);
    cout<<"Account Number:"<<itr->second.account_no<<endl;
    cout<<"First Name:"<<itr->second.first_name<<endl;
    cout<<"Last Name:"<<itr->second.last_name<<endl;
    cout<<"Balance:"<<itr->second.balance<<endl;
}
bool Bank:: admin_verification()
{
    string admin_password,entered_pass;
    cout<<"\nEnter Password:";
    cin>>entered_pass;
    admin_password="kunal@123456";
    if(entered_pass==admin_password)
    {
        return true;
    }
    else
        return false;


}


void Bank::display_all()
{

    map<int,Bank>::iterator it;
    cout<<"Only admin can access it";
    if( admin_verification())
    {
        cout<<"All account details:\n";
            for(it=accounts.begin(); it!=accounts.end(); it++)
        {
            display(it->second.account_no);
            cout<<"\n";
        }
    }
    else
    {
        cout<<"Entered Wrong Password\nTry Again";
        cout<<"Press Enter to continue ";
        getch();

    }
}
bool Bank::creat_pin()
{
    int pin=0,flag=3,temp=1,i;
    label:
    cout<<"Enter four digit Pin:";
    cin>>pin;
    temp=pin;
    for(i=0;temp!=0;i++)
        temp=temp/10;
    if(i==4)
    {
        this->pin=pin;
        return true;
    }
    else
    {
        cout<<"Please enter valid Pin\nTry again\n";
        flag--;
        cout<<"You have "<<flag<<" chances";
        if(flag!=0)
             goto label;
        cout<<"Sorry You have reached your limit";
        cout<<"Try Again";
        return false;

    }


}
bool Bank::pin_verify(int account_no)
{
    map<int,Bank>::iterator itr=accounts.find(account_no);
    int flag_pin=0,flag=3;
    if(itr!=accounts.end())
    {
        label:
        cout<<"Enter your Pin:";
        cin>>flag_pin;
        if(flag_pin==itr->second.pin)
        {
            cout<<"Pin verified\n";
            return true;
        }
        else
        {
            cout<<"Pin not verified\n";
            cout<<"Try Again\n";
            flag--;

            if(flag==0)
            {
                cout<<"Sorry You have reached your limit";
                cout<<"Try Again";
                return false ;
            }
            cout<<"You have "<<flag<<" chances\n";
            goto label;
        }
    }
    else
        cout<<"Account don't exist";
}
void start()
{
    char arr[]={'B','A','N','K',' ','M','A','N','A','G','E','M','E'
			,'N','T',' ','S','Y','S','T','E','M'};
			cout<<"\n\n\n\n\n\t\t\t";
			for(int i=0;i<24;i++){
				cout<<arr[i];
				Sleep(30);
			}
			Sleep(1000);
			system("CLS");
}


int main()
{
    int choice=1,amount=0;
    Bank b,c;
    int account_no;
    string fname,lname;
    start();
    while(choice!=7)
    {
        cout<<"\n\n\t\t\tBank Management System"<<endl;
        cout<<"\n\t\tSelect one option below "<<endl;
        cout<<"\t\t1 Open an Account"<<endl;
        cout<<"\t\t2 Balance Enquiry"<<endl;
        cout<<"\t\t3 Deposit"<<endl;
        cout<<"\t\t4 Withdrawal"<<endl;
        cout<<"\t\t5 Close an Account"<<endl;
        cout<<"\t\t6 Show all account"<<endl;
        cout<<"\t\t7 Quit"<<endl;
        cout<<"\t\tEnter your choice:";
         cin>>choice;
       
        system("ClS");
        switch(choice)
        {
            case 1:
                b.open_account();
                system("ClS");
                break;

            case 2:
                cout<<"Enter account number:";
                cin>>account_no;
                b.balance_enquiry(account_no);
                system("ClS");
                break;


            case 3:
                 cout<<"Enter account number:";
                cin>>account_no;
                cout<<"Enter Depositing amount:";
                cin>>amount;
                b.deposit(account_no,amount);
                system("ClS");
                break;


            case 4:
                 cout<<"Enter account number:";
                cin>>account_no;
                cout<<"Enter withdrawal amount:";
                cin>>amount;
                b.withdraw(account_no,amount);
                system("ClS");
                break;
            case 5:
                cout<<"Enter account no:";
                cin>>account_no;
                b.delete_account(account_no);
                system("ClS");
                break;

            case 6:
               b.display_all();
               system("ClS");
               break;
            case 7:
                system("ClS");
                break;
            default:
                cout<<"Enter a valid choice";
            
        }


    }


    return 0;
}
