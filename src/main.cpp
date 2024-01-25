#include <iostream>


#include "DesignPatterns/AbstractFactory.cpp"
#include "DesignPatterns/Adapter.cpp"
#include "DesignPatterns/Bridge.cpp"
#include "DesignPatterns/Builder.cpp"
#include "DesignPatterns/ChainOfResponsibility.cpp"


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
 
 
   
    ClassA a1(1);
    a1.x =2;

    func(a1);

    std::cout<<"x : "<< a1.x <<std::endl;
   

    return 0;
}



