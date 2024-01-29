#include <iostream>


 class ClassBase{

public:
    ClassBase(int argc){
        baseX=argc;
    }

    virtual int virtualFunc(){
        return 0;
    }
    int nonVirtualFunc(){
        return -1;
    }
     
private:
    virtual int pureVirtualConstFunc() const = 0;
    virtual int pureVirtualFunc() = 0;


protected:
    ClassBase* base;
    int baseX=0;
 };



class ClassA : public ClassBase{
    public:
        ClassA(int i) :ClassBase(i){
           x = i;
        }
        int x;


        int pureVirtualConstFunc() const override { return x*2; }
        int pureVirtualFunc() override { return x*3; }
        //int virtualFunc() override { return x*4; }
        int nonVirtualFunc() { return x*5; }//TODO:Base Class nasıl kullanılır?


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
    
    std::cout<<"x : "<< a1.pureVirtualConstFunc() <<std::endl;
    std::cout<<"x : "<< a1.pureVirtualFunc() <<std::endl;
    std::cout<<"x : "<< a1.virtualFunc() <<std::endl;
    std::cout<<"x : "<< a1.nonVirtualFunc() <<std::endl;

   

    return 0;
}



