#include "Animal.hpp"

struct Dog : public Animal {
    bool is_large;                  // true if the dog is large breed, false if the dog is small breed
    Dog(std::string name, double temp, double breath, double heart, bool is_large);
    bool check_health() override;
};