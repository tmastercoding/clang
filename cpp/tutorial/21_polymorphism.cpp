#include <iostream>
using namespace std;

// Parent class
class Animal {
    public: 
        // method that prints
        void animalSound() {
            // this text
            cout << "The animal makes a sound" << endl;
        }
};

// derived class from Animal
class Pig : public Animal{
    public:
        // has same method, but changing contents of method
        void animalSound(){
            cout << "The pig says: wee wee" << endl;
        }
};

// derived class from Animal
class Dog : public Animal{
    public:
        // has same method, but changing contents of method
        void animalSound(){
            cout << "The dog says: bark bark" << endl;
        }
};

int main(){
    // create objects of animal, pig and dog
    Animal myAnimal;
    Pig myPig;
    Dog myDog;

    // they all print different things
    myAnimal.animalSound();
    myPig.animalSound();
    myDog.animalSound();

    return 0;  
}