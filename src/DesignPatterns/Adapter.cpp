#include <iostream>

// Ses Sistemi Arabirimi (Interface)
class AudioSystem {
public:
    virtual void play() const = 0;
};

// Analog Ses Sistemi
class AnalogAudioSystem : public AudioSystem {
public:
    void play() const override {
        std::cout << "Analog ses aktif." << std::endl;
    }
};

// Dijital Ses Sistemi
class DigitalAudioSystem : public AudioSystem {
public:
    void play() const override {
        std::cout << "Dijital ses aktif." << std::endl;
    }
};

// Adaptör Sınıfı
class AudioAdapter : public AudioSystem {
private:
    AudioSystem* audioSystem;

public:
    AudioAdapter(AudioSystem* system) : audioSystem(system){}

    // Adaptör, dijital ses sistemini kullanarak arayüzü (interface) sağlar
    void play() const override {
        std::cout << "Adaptor: ";
        audioSystem->play();
    }
};

 