#include "Animal.hpp"

struct Cat : public Animal {
    Cat(std::string name, double temp, double breath, double heart);
    bool check_health() override;
};