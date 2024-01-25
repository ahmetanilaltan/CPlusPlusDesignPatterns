#include <iostream>
#include <string>

class Body{
public:
     std::string Title; 
     std::string Text; 
};

class MessageSenderBase{
public:
    virtual void send(Body* body) const = 0;

    void save(){
        std::cout<<"Message saved!" << std::endl;

    }
};

class EmailSender :public MessageSenderBase{
public:
    void send(Body* body) const override {
        std::cout<<body->Title << "was sent via EmailSender" << std::endl;
    }
};

class SmsSender:public MessageSenderBase{
public:
    void send(Body* body) const override {
        std::cout<<body->Title << "was sent via SmsSender" << std::endl;
    }

};

class ChatSender:public MessageSenderBase{
public:
    void send(Body* body) const override {
        std::cout<<body->Title << "was sent via ChatSender" << std::endl;
    }

};

class CustomerManager{
public:
    
    MessageSenderBase* messageSenderBase;

    void updateCustomer(){

        if(messageSenderBase != NULL)
        {
            Body b;
            b.Title = "About the course!";

            messageSenderBase->send(&b);
            std::cout << "Customer updated" << std::endl;
        }
    }

};


/*

int main() {
    CustomerManager customerManager;
    customerManager.messageSenderBase = new ChatSender();
    customerManager.updateCustomer();

    return 0;
}

*/