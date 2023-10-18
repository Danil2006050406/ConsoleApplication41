#include <iostream>
#include <string>
#include <Windows.h>

class Engine {
private:
    int horsepower;

public:
    Engine(int hp) : horsepower(hp) {}

    int getHorsepower() const {
        return horsepower;
    }
};


class Body {
private:
    std::string color;

public:
    Body(const std::string& c) : color(c) {}

    const std::string& getColor() const {
        return color;
    }
};


class Wheels {
private:
    int size;

public:
    Wheels(int s) : size(s) {}

    int getSize() const {
        return size;
    }
};


class Car {
private:
    Engine engine;
    Body body;
    Wheels wheels;

public:
    
    Car(const Engine& eng, const Body& b, const Wheels& w) : engine(eng), body(b), wheels(w) {}

    
    Car(const Car& other) : engine(other.engine), body(other.body), wheels(other.wheels) {}

    
    void changeBodyColor(const std::string& newColor) {
        body = Body(newColor);
    }

    
    void displayInfo() const {
        std::cout << "Автомобіль із двигуном потужністю " << engine.getHorsepower() << " к.с., має кузов кольору " << body.getColor()
            << " та колеса розміром " << wheels.getSize() << " дюймів." << std::endl;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Engine carEngine(150);
    Body carBody("червоний");
    Wheels carWheels(17);

    Car myCar(carEngine, carBody, carWheels);
    myCar.displayInfo();

    
    Car myNewCar(myCar);
    myNewCar.changeBodyColor("синій");

    myCar.displayInfo();
    myNewCar.displayInfo();

    return 0;
}
