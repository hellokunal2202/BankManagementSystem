
        cout<<"\n\n\t\t\t********Bank Management System********"<<endl;
        cout<<"\t\t      ***********Welcome to Yes Bank************";
    cout<<"\n\n\t\t\t\tSelect one option below "<<endl;
        cout<<"\t\t\t\t1 Open an Account"<<endl;
        cout<<"\t\t\t\t2 Balance Enquiry"<<endl;
        cout<<"\t\t\t\t3 Deposit"<<endl;
        cout<<"\t\t\t\t4 Withdrawal"<<endl;
        cout<<"\t\t\t\t5 Close an Account"<<endl;
        cout<<"\t\t\t\t6 Show all account"<<endl;
        cout<<"\t\t\t\t7 Quit"<<endl;
        cout<<"\t\t\t\tEnter your choice:";
         cin>>choice;   //selecting choice
       
        system("ClS");
        switch(choice)
        {
            case 1:                           //opening account
                b.open_account();
                system("ClS");
                break;
            case 2:                           //balance enquiry  
                cout<<"Enter account number:";
                cin>>account_no;
                b.balance_enquiry(account_no);
                system("ClS");
                break;
            case 3:                           //depositing amount 
                 cout<<"Enter account number:";
                cin>>account_no;
                cout<<"Enter Depositing amount:";
                cin>>amount;
                b.deposit(account_no,amount);
                system("ClS");
                break;
            case 4:                         //withdrawing amount 
                 cout<<"Enter account number:";
                cin>>account_no;
                cout<<"Enter withdrawal amount:";
                cin>>amount;
                b.withdraw(account_no,amount);
                system("ClS");
                break;
            case 5:                        //deleting account 
                cout<<"Enter account no:";
                cin>>account_no;
                b.delete_account(account_no);
                system("ClS");
                break;
            case 6:                       //diplaying all account information
               b.display_all();
               getch();
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
