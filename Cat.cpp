#include"Cat.hpp"

Cat::Cat(std::string name, double temp, double breath, double heart)
    : Animal(name, temp, breath, heart) {}

bool Cat::check_health(){
    if((m_temp>=38.0 && m_temp<=39.2)
        && (m_breath>=16 && m_breath<=40)
        && ((m_heart>=120&& m_heart<=140)))
            return true;
    return false;
}