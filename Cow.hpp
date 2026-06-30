#ifndef COW_HPP
#define COW_HPP
#include "Animal.hpp"

struct Cow : public Animal {
    double m_milk;
    Cow(std::string name, double temp, double breath, double heart, double liters);
    bool check_health() const override;
};
#endif // COW_HPP