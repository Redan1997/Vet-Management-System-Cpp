#include"Dog.hpp"

Dog::Dog(std::string name, double temp, double breath, double heart, bool is_large)
    : Animal(name, temp, breath, heart), is_large(is_large) {}

bool Dog::check_health(){
    if(
        (m_temp>=38.0 && m_temp<=39.2)
        && (m_breath>=10 && m_breath<=35)
        && ((m_heart>=60 && m_heart<=100)&& is_large)
        && ((m_heart>=100 && m_heart<=140)&& !is_large))
            return true;
    return false;
}