//created by redan ganim
#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <string>

struct Animal {
    std::string m_name;         // the name of the animal
    double m_temp;                // the temperature of the animal in celsius
    double m_breath;              // respiration rate - the amount of breaths per minute
    double m_heart;               // heart rate - the amount of heart beats per minute

    Animal(std::string name, double temp, double breath, double heart);
    virtual ~Animal() = default;//if there at least one virtual function, the destructor should be virtual

    virtual bool check_health()const = 0;//pure virtual function
};
#endif // ANIMAL_HPP