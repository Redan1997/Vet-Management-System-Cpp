#include"Vet.hpp"
#include <iostream>
#include "Dog.hpp"

/*the method add_animal will receive an rvalue of a pointer of a dynamically
allocated animal (dog/cat/cow) and will add it to the vector*/
void Vet::add_animal(Animal* &&p_animal){
    if(p_animal){
        m_animals.push_back(std::unique_ptr<Animal>(p_animal));//"move ptr"
        p_animal = nullptr;
    }
}

/*will print to cout the name of each animal that is sick (meaning its check_health
returned false)*/
void Vet::show_sick()const {//vet.show_sick(); //should print: dog2 dog3 cat2 cow2 
    for(const auto& animal : m_animals){
        if(!animal->check_health()){
            std::cout << animal->m_name << " ";
        }
    }
}
/*will print to cout the name of each Dog instance that is sick (ignoring otheranimal instances)*/
void Vet::show_sick_dogs()const{
    for(const auto &animal : m_animals){
        Dog* dog = dynamic_cast<Dog*>(animal.get());//use dynamic because animal is polymorphic and we want to check if it is a Dog instance can use also first typeid and then using static_cast
        if(dog && !dog->check_health()){
            std::cout << dog->m_name << " ";
        }
    }
}

/*a static method with a static local instance of Vet. will return a reference to thatinstance.*/
Vet& Vet::get_instance(){
    static Vet instance;
    return instance;
}