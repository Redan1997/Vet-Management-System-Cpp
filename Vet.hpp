#include"Animal.hpp"
#include <vector>
class Vet {
    std::vector<Animal*> m_animals;
public:
    void add_animal(Animal* &&animal);
    void show_sick();
    void show_sick_dogs();
    Vet& get_instance();
};