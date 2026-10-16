# Vet Management System - C++

A C++ program to manage and check the health of animals at a veterinary clinic.

## Concepts demonstrated

- **Inheritance** — `Dog`, `Cat`, `Cow` all inherit from abstract base class `Animal`
- **Abstract classes** — `Animal` has a pure virtual `check_health()` method
- **Polymorphism** — `check_health()` overridden differently per animal type
- **RTTI** — `dynamic_cast` used in `show_sick_dogs()` to filter only `Dog` instances
- **Singleton design pattern** — `Vet` class implemented as a singleton via a static local instance
- **Smart pointers** — `std::unique_ptr<Animal>` used for automatic memory management (RAII)
- **Const-correctness** — `check_health()` and all read-only methods marked `const`
- **`noexcept` / rule of five** — Vet's copy/move constructors and assignment operators explicitly `=delete`d

## Features

- `Animal` abstract base class with four vital signs: temperature, respiration rate, heart rate, name
- Three concrete animal types with species-specific health ranges:

| Type        | Body Temp   | Breath Rate | Heart Rate   | Milk      |
| ----------- | ----------- | ----------- | ------------ | --------- |
| Dog (large) | 38–39.2°C   | 10–35 /min  | 60–100 /min  | —         |
| Dog (small) | 38–39.2°C   | 10–35 /min  | 100–140 /min | —         |
| Cat         | 38–39.2°C   | 16–40 /min  | 120–140 /min | —         |
| Cow         | 38.5–39.5°C | 26–50 /min  | 48–84 /min   | ≥30 L/day |

- `Vet` singleton manages a collection of animal pointers
- `show_sick()` — prints names of all sick animals
- `show_sick_dogs()` — uses RTTI to print only sick `Dog` instances

## Example

```cpp
Vet& vet = Vet::get_instance();

vet.add_animal(new Dog("dog1", 38.5, 20, 80, true));  // healthy large dog
vet.add_animal(new Dog("dog2", 40.0, 20, 80, true));  // sick: temp too high
vet.add_animal(new Cat("cat1", 38.7, 30, 130));        // healthy cat
vet.add_animal(new Cat("cat2", 38.7, 42, 130));        // sick: breath too high
vet.add_animal(new Cow("cow1", 39.0, 37, 70, 32));     // healthy cow
vet.add_animal(new Cow("cow2", 39.0, 37, 70, 20));     // sick: milk too low

vet.show_sick();       // dog2 cat2 cow2
vet.show_sick_dogs();  // dog2
```

## Build

```bash
g++ *.cpp -Wall -Wextra -Weffc++ -std=c++14 -pedantic -o program
```

Compiles with zero warnings under this flag set on both Windows and Linux.

## Files

| File                        | Description                                       |
| --------------------------- | ------------------------------------------------- |
| `Animal.hpp` / `Animal.cpp` | Abstract base class                               |
| `Dog.hpp` / `Dog.cpp`       | Dog with large/small breed health ranges          |
| `Cat.hpp` / `Cat.cpp`       | Cat with feline health ranges                     |
| `Cow.hpp` / `Cow.cpp`       | Cow with bovine health ranges and milk production |
| `Vet.hpp` / `Vet.cpp`       | Singleton vet managing the animal collection      |
