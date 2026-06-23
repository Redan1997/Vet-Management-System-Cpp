#include"Cow.hpp"

Cow::Cow(std::string name, double temp, double breath, double heart, double liters)
    : Animal(name, temp, breath, heart), m_milk(liters) {}
bool Cow::check_health(){
    if((m_temp>=38.5&& m_temp<=39.5)
        && (m_breath>=26.0 && m_breath<=50.0)
        && ((m_heart>=48.0&& m_heart<=84.0))
        && (m_milk>=30.0))
            return true;
    return false;
}