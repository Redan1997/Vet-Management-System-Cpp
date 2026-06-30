#ifndef VET_HPP
#define VET_HPP

#include"Animal.hpp"
#include <vector>
#include <memory>
class Vet {
    std::vector<std::unique_ptr<Animal>> m_animals;

    ~Vet()=default;
    Vet()=default;
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