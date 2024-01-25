
#include <iostream>

// AbstractProduct sınıfı
class Button {
public:
    virtual void render() const = 0;
};

// ConcreteProduct sınıfı
class WindowsButton : public Button {
public:
    void render() const override {
        std::cout << "Render Windows Button" << std::endl;
    }
};

// ConcreteProduct sınıfı
class MacButton : public Button {
public:
    void render() const override {
        std::cout << "Render Mac Button" << std::endl;
    }
};

// AbstractProduct sınıfı
class Checkbox {
public:
    virtual void render() const = 0;
};

// ConcreteProduct sınıfı
class WindowsCheckbox : public Checkbox {
public:
    void render() const override {
        std::cout << "Render Windows Checkbox" << std::endl;
    }
};

// ConcreteProduct sınıfı
class MacCheckbox : public Checkbox {
public:
    void render() const override {
        std::cout << "Render Mac Checkbox" << std::endl;
    }
};

// AbstractFactory sınıfı
class GUIFactory {
public:
    virtual Button* createButton() const = 0;
    virtual Checkbox* createCheckbox() const = 0;
};

// ConcreteFactory sınıfı
class WindowsFactory : public GUIFactory {
public:
    Button* createButton() const override {
        return new WindowsButton();
    }

    Checkbox* createCheckbox() const override {
        return new WindowsCheckbox();
    }
};

// ConcreteFactory sınıfı
class MacFactory : public GUIFactory {
public:
    Button* createButton() const override {
        return new MacButton();
    }

    Checkbox* createCheckbox() const override {
        return new MacCheckbox();
    }
};

// İstemci (Client) sınıfı
class Application {
private:
    GUIFactory* guiFactory;

public:
    Application(GUIFactory* factory) : guiFactory(factory) {}

    void createUI() {
        Button* button = guiFactory->createButton();
        Checkbox* checkbox = guiFactory->createCheckbox();

        button->render();
        checkbox->render();

        delete button;
        delete checkbox;
    }
};

/*

#include "DesignPatterns/AbstractFactory/AbstractFactory.cpp"


int main() {
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

    return 0;
}

*/
