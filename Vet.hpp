#include"Animal.hpp"
#include <vector>
#include <memory>
class Vet {
    std::vector<std::unique_ptr<Animal>> m_animals;
public:
    void add_animal(Animal* &&animal);
    void show_sick();
    void show_sick_dogs();
    Vet& get_instance();
};