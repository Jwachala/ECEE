#include <iostream>
class Animal{
    int age;
    std::string name;
public:
    Animal(int age, std::string name){
        this->age = age;
        this->name = name;
    }
    virtual void makeNoise(){
        std::cout << "noise!" << '\n';
    }
};
class Dog : public Animal{
    std::string breed;
public:
    Dog(int age, std::string name,std::string breed): Animal(age, name){
        this->breed = breed;
    }
    void makeNoise(){
        std::cout << "boof!" << '\n';
    }
};
int main(){
    Animal Frank(18, "Frank");
    Animal *David = new Animal(23,"David");
    
    Dog *Fido = new Dog(14,"Fido","greek");
    Animal *AFido;
    AFido = Fido;
    David->makeNoise();
    AFido->makeNoise();
    Fido->makeNoise();
    delete David;
    delete AFido;
}