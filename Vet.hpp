#ifndef VET_HPP
#define VET_HPP

#include"Animal.hpp"
#include <vector>
#include <memory>
class Vet {
    std::vector<std::unique_ptr<Animal>> animals;
    //std::vector<Animal*> animals; //****use for raw ptr****   !!!need to change add_animal to receive a raw pointer must check if animal not nullptr and remove .get() from show_sick_dogs

    ~Vet()=default;//its safe to be private because the singleton instance is local static and it have full access to the private destructor at end of the program the static instance will be destroyed and the destructor will be called
    Vet();
    Vet(const Vet&)=delete;
    Vet(Vet&&)=delete;
    Vet& operator=(const Vet&)=delete;
    Vet& operator=(Vet&&)=delete;

public:
    void add_animal(Animal* &&p_animal);
    void show_sick()const;
    void show_sick_dogs()const;
    static Vet& get_instance();
};

#endif // VET_HPP