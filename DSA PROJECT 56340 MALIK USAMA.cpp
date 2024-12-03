#include <iostream>
#include <ctime>
using namespace std;
class Time 
{
    public:
        string timestamp;
        Time()
		{
            time_t now = time(0);
            timestamp = ctime(&now);
        }
};
class IncomeNode 
{
    public:
        Time time_Income;
        double amount;
        IncomeNode* next;
        IncomeNode(Time time, double amt) 
		{
        this->amount = amt;
        this->time_Income = time;
        this->next = NULL;
        }
};
class IncomeQueue 
{
private:
    IncomeNode* front;
    IncomeNode* rear;

public:
    IncomeQueue()
	{
        front = rear = NULL;
    }
    void enqueue(Time income, double amt)
	{
        IncomeNode* newNode = new IncomeNode(income, amt);
        if (rear == NULL)
		{
            front =newNode;
			rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
        cout << "\n\t\t\t|*************************************************************|\n";
        cout << "\t\t\t Income added successfully: "<< rear->amount<<" on "<<rear->time_Income.timestamp;
        cout << "\t\t\t|*************************************************************|\n";
    }
    void dequeue()
	{
        if (isEmpty())
		{
            cout << "\n\t\t\t\t       ***  No income records to delete.  ***\n";
            return;
        }
        IncomeNode* temp = front;
        cout << "\n\t\t\t|*************************************************************|\n";
        cout << "\t\t\t  First income of "<< front->amount << " on "<<front->time_Income.timestamp<<" deleted.\n";
        cout << "\t\t\t|*************************************************************|\n";
        front = front->next;
        if (front == NULL) rear = NULL;
        delete temp;
    }
    void viewFront()
	{
        if (isEmpty())
		{
            cout << "\n\t\t\t\t       ***  No income records available.  ***\n";
            return;
        }
        cout << "\n\t\t\t|*************************************************************|\n";
        cout << "\t\t\t  First Income - Amount: "<<front->amount<<", Date: "<<front->time_Income.timestamp;
        cout << "\t\t\t|*************************************************************|\n";
    }
    void display()
	{
        if (isEmpty())
		{
            cout << "\n\t\t\t\t       ***  No income records available.  ***\n";
            return;
        }
        cout << "\n\t\t\t\t            ***  Income Records  ***\n";
        cout << "\t\t\t---------------------------------------------------------------" << endl;
        cout << "\t\t\t| No | \tAmount\t|\t\tDate & Time\t\t      |"<<endl;
        cout << "\t\t\t---------------------------------------------------------------" << endl;
        IncomeNode* current = front;
        int count=0;
        double total=0;
        while (current != NULL)
		{
			count=count+1;
		    total=total+current->amount;
			cout << "\t\t\t| "<<count<<"  |\t "<<current->amount<<"\t|\t   "<<current->time_Income.timestamp<<endl;
            current = current->next;
        }
            cout << "\t\t\t---------------------------------------------------------------" << endl;
            cout << "\t\t\t\t\t\t   Total  Saving  =  "<<total<< endl;
            cout << "\t\t\t---------------------------------------------------------------" << endl;
    }
    bool isEmpty()
	{
        return front == NULL;
    }
};
class SavingNode 
{
    public:
        Time time_Saving;
        double amount;
        SavingNode* next;
        SavingNode(Time time, double amt)
		{
			this->amount = amt;
			this->time_Saving = time;
			this->next = NULL;
		}
};  
class SavingStack 
{
    private:
        SavingNode* top;
    public:
        SavingStack() 
		{
        	this->top = NULL;
		}
        void push(Time save, double amt) 
		{
            SavingNode* newNode = new SavingNode(save, amt);
            newNode->next = top;
            top = newNode;
            cout << "\n\t\t\t|*************************************************************|\n";
            cout << "\t\t\t Saving added successfully: " << top->amount << " on " << top->time_Saving.timestamp;
            cout << "\t\t\t|*************************************************************|\n";
        }
        void pop() 
		{
            if (isEmpty()) 
			{
                cout << "\n\t\t\t\t       ***  No savings records to delete.  ***\n";
                return;
            }
            SavingNode* temp = top;
            cout << "\n\t\t\t|*************************************************************|\n";
            cout << "\t\t\tB  Last Saving Deleted "<<top->amount<<" on "<<top->time_Saving.timestamp;
            cout << "\t\t\t|*************************************************************|\n";
            top = top->next;
            delete temp;
        }
        void viewTop() 
		{
            if (isEmpty()) 
			{
                cout << "\n\t\t\t\t       ***  No savings records available.  ***\n";
                return;
            }
            cout<<"\n\t\t\t|*************************************************************|\n";
            cout<<"\t\t\t  Last Saving - Amount: " << top->amount << ", Date: " << top->time_Saving.timestamp;
            cout<<"\t\t\t|*************************************************************|\n";
        }
        void display() 
		{
            if (isEmpty()) 
			{
                cout << "\n\t\t\t\t       ***  No savings records available.  ***\n";
                return;
            }
                cout<<"\n\n\t\t\t\t            ***  Savings Records  ***\n";
                cout<<"\t\t\t---------------------------------------------------------------" << endl;
                cout<<"\t\t\t| No | \tAmount\t|\t\tDate & Time\t\t      |"<<endl;
                cout<<"\t\t\t---------------------------------------------------------------" << endl;
                SavingNode* current = top;
                int count=0;
                double total=0.0;
            while (current != NULL) 
			{
		        count=count+1;
		        total=total+current->amount;
				cout << "\t\t\t| "<<count<<"  |\t "<<current->amount<<"\t|\t   "<<current->time_Saving.timestamp<<endl;
                current = current->next;
                
            }
                cout<<"\t\t\t---------------------------------------------------------------" << endl;
                cout<<"\t\t\t\t\t\t   Total  Saving  =  "<<total<< endl;
                cout<<"\t\t\t---------------------------------------------------------------" << endl;
        }
        bool isEmpty() 
		{
            return top == NULL;
        }
};
class ExpenseNode
{
    public:
        Time time_Expense;
        double amount;
        string description;
        ExpenseNode* next;
        ExpenseNode(Time time, double amt,string descr)
		{
            this->amount = amt;
            this->time_Expense = time;
            this->description=descr;
            this->next = NULL;
        }
};
class ExpenseQueue 
{
    private:
        ExpenseNode* front;
        ExpenseNode* rear;
    public:
        ExpenseQueue() 
		{
            front = rear = NULL;
        }
        void enqueue(Time expense, double amt, string descr) 
		{
            ExpenseNode* newNode = new ExpenseNode(expense, amt, descr);
            if (rear == NULL)
			{
                front = rear = newNode;
                return;
            }
            rear->next = newNode;
            rear= newNode;
            cout<<"\n\t\t\t|*************************************************************|\n";
            cout<<"\t\t\t\t       ***  Expense Added Successfully  ***\n";
            cout<<"\t\t\t|*************************************************************|\n";
        }
        void dequeue() 
		{
            if (isEmpty()) 
			{
                cout << "\n\t\t\t\t       ***  No expense records to delete.  ***\n";
                return;
            }
            ExpenseNode* temp = front;
            cout<<"\n\t\t\t|*************************************************************|\n";
            cout<<"\t\t\t  First Expense Deleted "<<front->amount<<" on "<<front->time_Expense.timestamp<<endl;
            cout<<"\t\t\t|*************************************************************|\n";
            front = front->next;
            if (front == NULL) rear = NULL;
            delete temp;
        }
        void viewFront()
		{
            if (isEmpty())
			{
                cout << "\n\t\t\t\t       ***  No expense records available.  ***\n";
                return;
            }
            cout<<"\n\t\t\t|*************************************************************|\n";
            cout<<"\t\t\t  First Expense - Amount: "<<front->amount<<", Date: "<<front->time_Expense.timestamp;
            cout<<"\t\t\t|*************************************************************|\n";
        }
        void display()
		{
            if (isEmpty())
			{
                cout<<"\n\t\t\t\t       ***  No expense records available.  ***\n";
                return;
            }
            cout<<"\n\t\t\t\t            ***  Expense Records  ***\n";
            ExpenseNode* current = front;
            int count=0;
            double total=0.0;
            cout<<"\t\t\t---------------------------------------------------------------" << endl;
            cout<<"\t\t\t| No |\t\tDescription\t|    Amount\t|\tDate & Time\t    |"<<endl;
            cout<<"\t\t\t---------------------------------------------------------------" << endl;
            while (current != NULL) 
			{
		        count=count+1;
		        total=total+current->amount;
				cout << "\t\t\t| "<<count<<"  |";
				cout<<" "<<current->description;
				cout<<" | "<<current->amount;
				cout<<"|\t"<<current->time_Expense.timestamp<<endl;
                current = current->next;
                
            }
                cout<<"\t\t\t---------------------------------------------------------------" << endl;
                cout<<"\t\t\t\t\t\t   Total  Expenses  =  "<<total<< endl;
                cout<<"\t\t\t---------------------------------------------------------------" << endl;
        }
        bool isEmpty()
		{
            return front == NULL;
        }
};

class InvestmentNode
{
    public:
        Time time_Investment;
        double amount;
        double profitRate;  
        string frequency;  
        double totalProfit; 
        InvestmentNode* next;
        InvestmentNode(Time time, double amt, double rate, string freq) 
		{
            this->amount = amt;
            this->profitRate = rate;
            this->frequency = freq;
            this->totalProfit = 0;
            this->next = NULL;
            this->time_Investment = time;
            calculateProfit();
        }
        void calculateProfit()
		{
            if (frequency == "daily")
			{
                totalProfit = amount * (profitRate / 100);
            }
            else if (frequency == "monthly")
			{
                totalProfit = amount * (profitRate / 100) * 30;
            }
        }
};
class InvestmentStack 
{
    private:
        InvestmentNode* top;

    public:
        InvestmentStack() 
		{
            top = NULL;
        }
        void push(Time investment, double amt, double rate, string freq)
		{
            InvestmentNode* newNode = new InvestmentNode(investment, amt, rate, freq);
            newNode->next = top;
            top = newNode;
            cout << "\n\t\t\t|*************************************************************|\n";
            cout << "\t\t\t Investment added successfully: " << top->amount << " on " << top->time_Investment.timestamp;
            cout << "\t\t\t Total Profit: " << top->totalProfit << " (" << freq << ")\n";
            cout << "\t\t\t|*************************************************************|\n";
        }
        void pop() 
		{
            if (isEmpty())
			{
                cout << "\n\t\t\t\t       ***  No investment records to delete.  ***\n";
                return;
            }
            InvestmentNode* temp = top;
            cout << "\n\t\t\t|*************************************************************|\n";
            cout << "\t\t\t  Last investment of " << top->amount << " on " << top->time_Investment.timestamp << " deleted.\n";
            cout << "\t\t\t Total Profit: " << top->totalProfit << "\n";
            cout << "\t\t\t|*************************************************************|\n";
            top = top->next;
            delete temp;
        }

        void viewTop()
		{
            if (isEmpty())
			{
                cout << "\n\t\t\t\t       ***  No investment records available.  ***\n";
                return;
            }
            cout << "\n\t\t\t|*************************************************************|\n";
            cout << "\t\t\tLast Investment - Amount: " << top->amount << ", Profit: " << top->totalProfit;
            cout << ", Date: " << top->time_Investment.timestamp << "\n";
            cout << "\t\t\t|*************************************************************|\n";
        }

        void display()
		{
            if (isEmpty())
			{
                cout << "\n\t\t\t\t       ***  No investment records available.  ***\n";
                return;
            }
            cout << "\n\t\t\t\t            ***  Investment Records  ***\n";
            InvestmentNode* current = top;
            while (current != NULL)
			{
                cout << "\tAmount: " << current->amount << ", Profit: " << current->totalProfit
                     << ", Frequency: " << current->frequency << ", Date: " << current->time_Investment.timestamp;
                current = current->next;
            }
        }
        bool isEmpty()
		{
            return top == NULL;
        }
};
class node
{
    public:
        string user_Name;
        string user_password;
        int user_ID;
        SavingStack savings;
        ExpenseQueue expenses;
        InvestmentStack investments;
        IncomeQueue incomes;
        node* next;
        node(string name, string password, int id) 
		{
			this->user_Name = name;
			this->user_password = password;
			this->user_ID = id;
			this->next = NULL;
		}
};
class linkedlist 
{
    private:
        node* head;

    public:
        linkedlist() 
		{
        	this->head = NULL;
		}
        void insert_userData(string name, string password, int id) 
		{
            node* newnode = new node(name, password, id);
            if (head == NULL) 
			{
                head = newnode;
                return;
            }
            node* temp = head;
            while (temp->next != NULL) 
			{
                temp = temp->next;
            }
            temp->next = newnode;
        }
        node* find_User(string name, string password, int id) 
		{
            node* temp = head;
            while (temp != NULL) 
			{   
			    if (temp->user_Name == name && temp->user_password == password && temp->user_ID == id) 
				{
                    return temp;
                }
                temp = temp->next;
            }
            return NULL;
        }
        node* check_User(string name, string password, int id) 
		{
            node* temp = head;
            while (temp != NULL) 
			{   
			    if (temp->user_Name == name || temp->user_ID == id) 
				{
                    return temp;
                }
                temp = temp->next;
            }
            return NULL;
        } 
        void display_data(node* user) 
		{
            int choice;
          
            do {
                cout << "\n\t\t\t            ('-') WELCOME TO DASHBOARD ('-') \n";
                cout << "\t\t\t _________________________________________________________\n";
                cout << "\t\t\t|                                                         |\n";
                cout << "\t\t\t|----------------------   1. Income      -----------------|\n";
                cout << "\t\t\t|----------------------   2. Saving      -----------------|\n";
                cout << "\t\t\t|----------------------   3. Expenses    -----------------|\n";
                cout << "\t\t\t|----------------------   4. Investments -----------------|\n";
                cout << "\t\t\t|----------------------   5. Exit        -----------------|\n";
                cout << "\t\t\t|_________________________________________________________|\n";
                cout << "\t\t\t                     Enter your choice : ";
                cin >> choice;
                cout<<endl;
                switch (choice) 
				{
                    case 1:
                    	incomeMenu(user);
                        break;
                    case 2:
                        savingMenu(user);
                        break;
                    case 3:
                        manageExpense(user);
                        break;
                    case 4 :
					    investment_data(user);
                        break;   
                    case 5:
                        cout << "\n\tReturning to Main Menu...\n";
                        break;
                    default:
                        cout << "\n\tInvalid Choice! Please try again.\n";
                        break;
                }
            } while (choice != 5);
        }
        void incomeMenu(node* user)
		{
            int choice;
            double amount;
            do
			{
                    cout << "\n\t\t\t                  ***  MANAGE INCOME  ***\n";
                    cout << "\t\t\t__________________________________________________________\n";
                    cout << "\t\t\t|                                                         |\n";
                    cout << "\t\t\t|-------------------  1. Add Income          -------------|\n";
                    cout << "\t\t\t|-------------------  2. View All Incomes    -------------|\n";
                    cout << "\t\t\t|-------------------  3. Remove First Income -------------|\n";
                    cout << "\t\t\t|-------------------  4. View First Income   -------------|\n";
                    cout << "\t\t\t|-------------------  5. Back to Dashboard   -------------|\n";
                    cout << "\t\t\t|_________________________________________________________|\n";
                    cout << "\t\t\tEnter your choice: ";
                    cin >> choice;
           switch (choice)
		   {
            case 1:
                cout << "\nEnter income amount: ";
                cin >> amount;
                user->incomes.enqueue(Time(), amount);
                break;
            case 2:
                user->incomes.display();
                break;
            case 3:
                user->incomes.dequeue();
                break;
            case 4:
                user->incomes.viewFront();
                break;
            case 5:
                return;
            default:
                cout << "\nInvalid option! Try again.\n";
        }
    } while (choice != 5);
}
        void savingMenu(node* user) 
		{
            int choice;
            double amount;
            do {
            
                cout << "\n\n\t\t\t\t             *** SAVING OPTIONS ***\n";
                cout << "\t\t\t _____________________________________________________________\n";
                cout << "\t\t\t|                                                             |\n";
                cout << "\t\t\t|------------------    1. Add Saving           ---------------|\n";
                cout << "\t\t\t|------------------    2. View All Savings     ---------------|\n";
                cout << "\t\t\t|------------------    3. Delete Last Saving   ---------------|\n";
                cout << "\t\t\t|------------------    4. View Last Saving     ---------------|\n";
                cout << "\t\t\t|------------------    5. Back to Dashboard    ---------------|\n";
                cout << "\t\t\t|_____________________________________________________________|\n";
                cout << "\t\t\t                     Enter your choice : ";
                cin >> choice; 
                switch (choice) 
				{
                    case 1:
                        cout << "\n\tEnter amount to save: ";
                        cin >> amount;
                        user->savings.push(Time(), amount);
                        break;
                    case 2:
                        user->savings.display();
                        break;
                    case 3:
                        user->savings.pop();
                        break;
                    case 4:
                        user->savings.viewTop();
                        break;
                    case 5:
                        cout << "\n\tReturning to Dashboard...\n";
                        break;
                    default:
                        cout << "\n\tInvalid Choice! Please try again.\n";
                        break;
                }
            } while (choice != 5);
        }
         void manageExpense(node* user) 
		{
            int option;
            double amount;
            string description;
            do
			{
                cout << "\n\t\t\t                 ***  MANAGE EXPENSES  ***\n";
                cout << "\t\t\t _________________________________________________________\n";
                cout << "\t\t\t|                                                         |\n";
                cout << "\t\t\t|------------------- 1. Add Expense          -------------|\n";
                cout << "\t\t\t|------------------- 2. View All Expenses    -------------|\n";
                cout << "\t\t\t|------------------- 3. Remove First Expense -------------|\n";
                cout << "\t\t\t|------------------- 4. View First Expense   -------------|\n";
                cout << "\t\t\t|------------------- 5. Back to Dashboard    -------------|\n";
                cout << "\t\t\t _________________________________________________________\n";
                cout << "\t\t\tEnter your choice: ";
                cin >> option;      
                switch(option)
				{
                    case 1:
                        cout << "\nEnter expense amount: ";
                        cin >> amount;
                        cout << "\nEnter expense amount: ";
                        cin>>description;
                        user->expenses.enqueue(Time(), amount, description);
                        break;
                    case 2:
                        user->expenses.display();
                        break;
                    case 3:
                        user->expenses.dequeue();
                        break;
                    case 4:
                        user->expenses.viewFront();
                        break;
                    case 5:
                        return;
                    default:
                        cout << "\nInvalid option! Try again.\n";
                }
            } while (option != 5);
        }
        void investment_data(node* user)
		{
            int choice;
            double amount, rate;
            string freq;
            do {
                cout << "\n\t\t\t                       MANAGE  INVESTMENT                \n";
                cout << "\t\t\t _________________________________________________________\n";
                cout << "\t\t\t|                                                         |\n";
                cout << "\t\t\t|------------------  1. Add Investment        ------------|\n";
                cout << "\t\t\t|------------------  2. View All Investments  ------------|\n";
                cout << "\t\t\t|------------------  3. Remove Last Investment------------|\n";
                cout << "\t\t\t|------------------  4. View Last Investment  ------------|\n";
                cout << "\t\t\t|------------------  5. Back to Dashboard    -------------|\n";
                cout << "\t\t\t|_________________________________________________________|\n";
                cout << "\t\t\t                     Enter your choice : ";
                cin >> choice;
                switch (choice)
				{
                    case 1:
                        cout << "\nEnter investment amount: ";
                        cin >> amount;
                        cout << "Enter profit rate (percentage): ";
                        cin >> rate;
                        cout << "Is this a daily or monthly investment? (Enter 'daily' or 'monthly'): ";
                        cin >> freq;
                        user->investments.push(Time(), amount, rate, freq);
                        break;
                    case 2:
                        user->investments.display();
                        break;
                    case 3:
                        user->investments.pop();
                        break;
                    case 4:
                        user->investments.viewTop();
                        break;
                    case 5:
                        cout << "\n\tReturning to Main Menu...\n";
                        break;
                    default:
                        cout << "\n\tInvalid Choice! Please try again.\n";
                        break;
                }
            } while (choice != 5);
        }
        
};
int main() 
{
    linkedlist li;
    string name, password;
    int id, select;
    node* user = NULL; 
    cout << "\n\t\t\t              ('-') PERSONAL FINANCE TRACKING ('-') \n";
    do 
	{
        cout << "\t\t\t _________________________________________________________\n";
        cout << "\t\t\t|                                                         |\n";
        cout << "\t\t\t|----------------------   1. Sign up ---------------------|\n";
        cout << "\t\t\t|----------------------   2. Login   ---------------------|\n";
        cout << "\t\t\t|----------------------   3. Exit    ---------------------|\n";
        cout << "\t\t\t|_________________________________________________________|\n";
        cout << "\t\t\t                     Enter your choice : ";
        cin >> select;
        switch (select) 
		{
            case 1:
                cout << "\n\t\t\t|*********************************************************|\n";
                cout << "\t\t\t                     Enter Your Name : ";
                cin >> name;
                cout << "\t\t\t                     Enter Your Password  : ";
                cin >> password;
                cout << "\t\t\t                     Enter Your ID : ";
                cin >> id;
                cout << "\t\t\t|*********************************************************|";

                if (li.check_User(name, password, id)) 
				{
					cout << "\n\t\t\t\t       User Already Registered! Please login.\n";
                } 
				else 
				{
                    li.insert_userData(name, password, id);
                    cout << "\n\t\t\t\t          You are Successfully Registered\n\n";
                }
                break;
            case 2:
                cout << "\n\t\t\t|*********************************************************|\n";
                cout << "\t\t\t                     Enter Your Name : ";
                cin >> name;
                cout << "\t\t\t                     Enter Your Password  : ";
                cin >> password;
                cout << "\t\t\t                     Enter Your ID : ";
                cin >> id;
                cout << "\t\t\t|*********************************************************|";
                user = li.find_User(name, password, id);
                if (user) 
				{    
				    li.display_data(user);   
                } 
				else 
				{
					cout << "\t\t\t                     Invalid Name & Password";
                }
                break;
            case 3:
                cout << "\n\t\t\t|____________________ Exiting Program...... __________________|\n\n";
                break;

            default:
                cout << "\n\t\t\t|_____________ Invalid Choice! Please try again ______________|\n\n";
        }
    } while (select != 3);
    return 0;
}

