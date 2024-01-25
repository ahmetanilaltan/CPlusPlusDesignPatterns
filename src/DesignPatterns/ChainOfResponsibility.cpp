#include <iostream>
#include <string>

 struct Expense{
      std::string Detail; 
      float Amount; 
 };

class ExpenseHandlerBase{
    public:
        virtual void HandleExpense(Expense expense) const = 0;

        void SetSuccessor(ExpenseHandlerBase* exp){
            this->successor = exp;
        }
    protected:
        ExpenseHandlerBase* successor;    
};

class Manager :public ExpenseHandlerBase{
    public:
        void HandleExpense(Expense expense)const override{
        
            if (expense.Amount<=100)
            {
                std::cout<<"Manager handled the expense!"<<std::endl;
            }
            else if(successor!= NULL)
            {
                successor->HandleExpense(expense);
            }
        }
};

class VicePresident :public ExpenseHandlerBase{
    public:
        void HandleExpense(Expense expense)const override{
        
            if (expense.Amount > 100 &&expense.Amount<=1000)
            {
                std::cout<<"Vice President handled the expense!"<<std::endl;
            }
            else if(successor!= NULL)
            {
                successor->HandleExpense(expense);
            }
        }
};

class President :public ExpenseHandlerBase{
    public:
        void HandleExpense(Expense expense)const override{
        
            if (expense.Amount >1000)
            {
                std::cout<<"President handled the expense!"<<std::endl;
            } 
        }
};

/*

void ChainOfResponsibilityMain() {

Manager* manager = new Manager;
VicePresident* vicePresident = new VicePresident;
President* president = new President;

manager->SetSuccessor(vicePresident);
vicePresident->SetSuccessor(president);

Expense expense {.Detail = "Training", .Amount = 300};
manager->HandleExpense(expense);

}

*/ 
 
