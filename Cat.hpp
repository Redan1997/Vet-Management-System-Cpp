#ifndef CAT_HPP
#define CAT_HPP
#include "Animal.hpp"

struct Cat : public Animal {
    Cat(std::string name, double temp, double breath, double heart);
    bool check_health() const override;
};
#endif // CAT_HPP