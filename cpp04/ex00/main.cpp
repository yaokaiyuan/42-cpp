#include <iostream>
#include <string>

class Animal {
protected:
    std::string type;
public:
    Animal() : type("Animal") { std::cout << "Animal constructor called" << std::endl; }
    virtual ~Animal() { std::cout << "Animal destructor called" << std::endl; }
    virtual void makeSound() const { std::cout << "Animal sound" << std::endl; }
    std::string getType() const { return type; }
};

class Dog : public Animal {
public:
    Dog() { type = "Dog"; std::cout << "Dog constructor called" << std::endl; }
    ~Dog() { std::cout << "Dog destructor called" << std::endl; }
    void makeSound() const { std::cout << "Woof!" << std::endl; }
};

class Cat : public Animal {
public:
    Cat() { type = "Cat"; std::cout << "Cat constructor called" << std::endl; }
    ~Cat() { std::cout << "Cat destructor called" << std::endl; }
    void makeSound() const { std::cout << "Meow!" << std::endl; }
};

class WrongAnimal {
protected:
    std::string type;
public:
    WrongAnimal() : type("WrongAnimal") { std::cout << "WrongAnimal constructor called" << std::endl; }
    virtual ~WrongAnimal() { std::cout << "WrongAnimal destructor called" << std::endl; }
    void makeSound() const { std::cout << "WrongAnimal sound" << std::endl; }
    std::string getType() const { return type; }
};

class WrongCat : public WrongAnimal {
public:
    WrongCat() { type = "WrongCat"; std::cout << "WrongCat constructor called" << std::endl; }
    ~WrongCat() { std::cout << "WrongCat destructor called" << std::endl; }
    void makeSound() const { std::cout << "WrongAnimal sound" << std::endl; }
};

int main() {
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); // will output the cat sound!
    j->makeSound();
    meta->makeSound();

    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();
    std::cout << wrongCat->getType() << " " << std::endl;
    wrongCat->makeSound(); // will output the WrongAnimal sound!
    wrongMeta->makeSound();

    delete meta;
    delete j;
    delete i;
    delete wrongMeta;
    delete wrongCat;

    return 0;
}
