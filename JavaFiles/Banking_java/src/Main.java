import jdk.jfr.Label;
import java.util.*;
import java.lang.*;
import java.util.Map.Entry;
class Bank
{
    Scanner sc = new Scanner(System.in);
    private
    int account_no;
    private String first_name;
    private String last_name;
    private int balance;
    private static HashMap<Integer, Bank> accounts = new HashMap<Integer, Bank>();
    private static int next_account = 0;
    private int pin;
    public Bank()
    {
        account_no = 0;
        balance = 0;

    }

    public int get_account_no() {
        return account_no;
    }

    public void open_account()
    {
        int flag = 3;
        Bank new_account = new Bank();
        System.out.println("Enter your First Name:");
        new_account.first_name = sc.next();
        System.out.println("Enter your Last Name:");
        new_account.last_name = sc.next();
        do
        {
            System.out.println("Enter depositing amount:");
            new_account.balance = sc.nextInt();
            if (new_account.balance >= 500)
            {
                next_account++;
                new_account.account_no = next_account;
                if (new_account.creat_pin())
                {
                    System.out.println("Please Wait\n");
                    new_account.store(new_account);
                    System.out.println("\nCongratulation your account has been created!!");
                    new_account.display(new_account.get_account_no());
                    break;
                }
            }
            else
            {

                flag--;
                if (flag == 0)
                {
                    System.out.println("Sorry try Again");
                    break;
                }
                System.out.println("Enter Initial Amount greater than 500\n");
            }

        }while (flag > 0);


    }

    public void balance_enquiry(int account_no)
    {

        //HashMap<Integer,Bank>::iterator itr=accounts.find(account_no);
        if (accounts.get(account_no) != null) {
            if (pin_verify(account_no))
                display(account_no);
            else
                System.out.println("Try Again");
        } else {
            System.out.println("Account don't exist\n");
            System.out.println("Try again");
        }


    }
    public void deposit(int account_no, int amount)
    {
        //  accounts:iterator itr=accounts.find(account_no);
        if (accounts.get(account_no) != null)
        {
            if (pin_verify(account_no))
            {
                accounts.get(account_no).balance += amount;
                //accounts.getKey();
                display(account_no);
            } else
                System.out.println("Try Again");
        }
        else
        {
            System.out.println("Account don't exist\n");
            System.out.println("Try again");
        }
    }

    public void withdraw(int account_no, int amount)
    {
        // map<Integer,Bank>::iterator itr=accounts.find(account_no);

        if (accounts.get(account_no) != null)
        {
            if (pin_verify(account_no))
            {
                amount = (accounts.get(account_no).balance) - amount;
                if (amount < 0)
                    System.out.println("Insufficient Balance");
                else {
                    accounts.get(account_no).balance = amount;
                    display(account_no);
                }
            }
            else
                System.out.println("Try Again");
        } else
        {
            System.out.println("Account don't exist\n");
            System.out.println("Try again");
        }

    }

    public void delete_account(int account_no)
    {
        // map<int,Bank>::iterator itr=accounts.find(account_no);
        if (accounts.get(account_no) != null)
        {
            if (pin_verify(account_no))
            {
                accounts.remove(account_no);
                System.out.println("Your account has been removed");
            }
            else
                System.out.println("Try Again");
        }
        else
        {
            System.out.println("Account don't exist\n");
            System.out.println("Try again");
        }


    }

    public void store(Bank p) {
        accounts.put(p.get_account_no(), p);

    }

    void display(int account_no)
    {
        System.out.println("Here are your details:");
        System.out.println("---------------------------------------------------------");
        System.out.println("Account Number:" + accounts.get(account_no).account_no );
        System.out.println("First Name:" + accounts.get(account_no).first_name );
        System.out.println("Last Name:" + accounts.get(account_no).last_name );
        System.out.println("Balance:" + accounts.get(account_no).balance );
        System.out.println("---------------------------------------------------------");

    }

    boolean admin_verification()
    {

        String admin_password;
        String entered_pass;
        System.out.print("\nEnter Password:");
        entered_pass = sc.next();
        admin_password = "kunal@123456";
        if (admin_password.equals(entered_pass))
            return true;
        else
            return false;
    }


    public void display_all()
    {

        //map<Integer,Bank>::iterator it;
        System.out.println("Only admin can access it");
        if (admin_verification())
        {
            for (Entry<Integer, Bank> entry : accounts.entrySet())
            {
                //System.out.println("inside true");
                display(entry.getValue().account_no);
                //System.out.println("\n");
            }
        }
        else
        {
            System.out.println("Entered Wrong Password\nTry Again");

        }
    }

    public boolean creat_pin()
    {
        int pin = 0, flag = 3, temp = 1, i;
        label:
        while (flag > 0)
        {
            System.out.println("Enter four digit Pin:");
            pin = sc.nextInt();
            temp = pin;
            for (i = 0; temp != 0; i++)
                temp = temp / 10;
            if (i == 4)
            {
                this.pin = pin;
                return true;
            }
            else
            {
                System.out.println("Please enter valid Pin\nTry again\n");
                flag--;
                System.out.println("You have " + flag + " chances");
                if (flag != 0)
                    continue;
                System.out.println("Sorry You have reached your limit");
                System.out.println("Try Again");
                return false;

            }
        }
        return true;

    }

    public boolean pin_verify(int account_no)
    {
        //map<Integer,Bank>::iterator itr=accounts.find(account_no);
        int flag_pin = 0, flag = 3;
        if (accounts.containsKey(account_no))
        {
            label:
            while (flag > 0) {
                System.out.println("Enter your Pin:");
                flag_pin = sc.nextInt();
                if (flag_pin == accounts.get(account_no).pin) {
                    System.out.println("Pin verified");
                    return true;
                } else {
                    System.out.println("Pin not verified");
                    System.out.println("Try Again");
                    flag--;
                    if (flag == 0)
                    {
                        System.out.println("Sorry You have reached your limit");
                        System.out.println("Try Again");
                        return false;
                    }
                    System.out.println("You have " + flag + " chances left");
                }
            }
        }
        else
        {
            System.out.println("Account don't exist");

        }
        return true;


    }
}


// map<int,Bank>accounts;
public class Main
{
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        int choice=1,amount=0;
        Bank b= new Bank();
        int account_no;
        String fname,lname;
        System.out.println("\n\n\t\t\t********Bank Management System********");
        System.out.println("\t\t   ***********Welcome to Yes Bank************");
        while(choice!=7)
        {
            System.out.println("\t\tSelect one option below ");
            System.out.println("\t\t1 Open an Account");
            System.out.println("\t\t2 Balance Enquiry");
            System.out.println("\t\t3 Deposit");
            System.out.println("\t\t4 Withdrawal");
            System.out.println("\t\t5 Close an Account");
            System.out.println("\t\t6 Show all account");
            System.out.println("\t\t7 Quit");
            System.out.print("Enter your choice:");
            choice=sc.nextInt();
            switch(choice)
            {
                case 1:
                    b.open_account();
                    break;

                case 2:
                    System.out.println("Enter account number:");
                    account_no=sc.nextInt();
                    b.balance_enquiry(account_no);
                    break;

                case 3:
                    System.out.println("Enter account number:");
                    account_no=sc.nextInt();
                    System.out.println("Enter Balance:");
                    amount=sc.nextInt();
                    b.deposit(account_no,amount);
                    break;


                case 4:
                    System.out.println("Enter account number:");
                    account_no=sc.nextInt();
                    System.out.println("Enter withdrawal amount");
                    amount=sc.nextInt();
                    b.withdraw(account_no,amount);
                    break;
                case 5:
                    System.out.println("Enter account no");
                    account_no=sc.nextInt();
                    b.delete_account(account_no);
                    break;

                case 6:
                    b.display_all();
                    break;
                case 7:
                    break;
                default:
                    System.out.println("Enter a valid choice");

            }
        }
    }
}


