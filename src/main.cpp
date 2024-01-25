#include <iostream>


#include "DesignPatterns/AbstractFactory.cpp"
#include "DesignPatterns/Adapter.cpp"
#include "DesignPatterns/Bridge.cpp"
#include "DesignPatterns/Builder.cpp"
#include "DesignPatterns/ChainOfResponsibility.cpp"

void AbstractFactory() {
    // Windows temasını kullanmak için WindowsFactory
    GUIFactory* windowsFactory = new WindowsFactory();
    Application windowsApp(windowsFactory);
    windowsApp.createUI();

    // Mac temasını kullanmak için MacFactory
    GUIFactory* macFactory = new MacFactory();
    Application macApp(macFactory);
    macApp.createUI();

    delete windowsFactory;
    delete macFactory;
}

void Adapter() {
    // Dijital ses sistemini oluştur
    DigitalAudioSystem digitalSystem;
    AnalogAudioSystem analogSystem;


    // Adaptörü oluştur ve dijital ses sistemini adaptör içine yerleştir
    AudioAdapter audioAdapter1(&digitalSystem);

    AudioAdapter audioAdapter2(&analogSystem);

    // Arabirim (interface) kullanılarak adaptörü çağır
    audioAdapter1.play();
    audioAdapter2.play();

}

void Bridge() {
    CustomerManager customerManager;
    customerManager.messageSenderBase = new ChatSender();
    customerManager.updateCustomer();
}

void Builder() {

    ProductDirector director;

    OldCustomerProductBuilder* obuilder = new OldCustomerProductBuilder();
    NewCustomerProductBuilder* nbuilder = new NewCustomerProductBuilder();


    director.GenerateProduct(obuilder);
    director.GenerateProduct(nbuilder);

    
    ProductViewModel model = obuilder->GetModel();
    //ProductViewModel model = obuilder->GetModel();

    std::cout<<"model.Id :"<< model.Id <<std::endl;
    std::cout<<"model.CategoryName :"<< model.CategoryName <<std::endl;
    std::cout<<"model.DiscountApplied :"<< model.DiscountApplied <<std::endl;
    std::cout<<"model.DiscountedPrice :"<< model.DiscountedPrice <<std::endl;
    std::cout<<"model.ProductName :"<< model.ProductName <<std::endl;
    std::cout<<"model.UnitPrice :"<< model.UnitPrice <<std::endl;
 
}

void ChainOfResponsibilityMain() {

    Manager* manager = new Manager;
    VicePresident* vicePresident = new VicePresident;
    President* president = new President;

    manager->SetSuccessor(vicePresident);
    vicePresident->SetSuccessor(president);

    Expense expense {.Detail = "Training", .Amount = 300};
    manager->HandleExpense(expense);
}



class ClassA{
    public:
    ClassA(int i=0){
        x = i;
    }
    int x;
};

void func(ClassA& a){

std::cout<<"x : "<< a.x <<std::endl;
a.x=3;

}


int main() {

   AbstractFactory();
   Adapter();
   Bridge();
   Builder();
   ChainOfResponsibilityMain();

   
    ClassA a1(1);
    a1.x =2;

    func(a1);

    std::cout<<"x : "<< a1.x <<std::endl;
   

    return 0;
}



