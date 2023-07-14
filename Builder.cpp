#include<iostream>
#include <string>

class Car {

    private:
    std::string brand;
    std::string model;
    std::string engine;
    int numSeats; 

    public:
    void setBrand(std::string brand) {
        brand = brand;
    }

    void setModel(std::string model) {
        model = model;
    }

    void setEngine(std::string engine) {
        engine = engine;
    }

    void setNumSeats(int numSeats) {
        numSeats = numSeats;
    }

    void displayInfo(Car* car) {
        std::cout << "Car: " << car->brand << " " << car->model << std::endl;
        std::cout << "Engine: " << car->engine << std::endl;
        std::cout << "Number of Seats: " << car->numSeats << std::endl;
    }   
};


class CarBuilder {

    Car* car;

    public:
    Car* getCar() {
        return car;
    }

    Car* createNewCar() {
        car = new Car();
        return car;
    }

    virtual void buildBrand() = 0;
    virtual void buildEngine() = 0;
    virtual void buildModel() = 0;
    virtual void buildNumSeats() = 0;

};


class SportsCarBuilder : public CarBuilder {

    Car* car;

    public:
    void buildBrand() {
        car->setBrand("Ferrari");
    }

    void buildModel() {
        car->setModel("488 GTB");
    }

    void buildEngine() {
        car->setEngine("3.9L V8");
    }

    void buildNumSeats() {
        car->setNumSeats(2);
    }

    Car* getCar() {
        return car;
    }
};


class SUVBuilder : public CarBuilder {

    Car* car;

    public:
    void buildBrand() {
        car->setBrand("Toyota");
    }

    void buildModel() {
        car->setModel("Highlander");
    }

    void buildEngine() {
        car->setEngine("3.5L V6");
    }

    void buildNumSeats() {
        car->setNumSeats(7);
    }

    Car* getCar() {
        return car;
    }
};


class Manufacturer {

    CarBuilder* carBuilder;

    public:
    void setCarBuilder(CarBuilder* builder) {
        carBuilder = builder;
    }

    Car* getCar() {
        return carBuilder->getCar();
    }

    void constructCar() {
        carBuilder->createNewCar();
        carBuilder->buildBrand();
        carBuilder->buildModel();
        carBuilder->buildEngine();
        carBuilder->buildNumSeats();
    }
};

int main() {

    Manufacturer manufacturer;
    SportsCarBuilder sportsCarBuilder;
    SUVBuilder suvBuilder;

    // Build sports car
    manufacturer.setCarBuilder(&sportsCarBuilder);
    manufacturer.constructCar();
    Car* sportsCar = manufacturer.getCar();
    sportsCar->displayInfo(sportsCar);


    // Build SUV
    // manufacturer.setCarBuilder(&suvBuilder);
    // manufacturer.constructCar();
    // Car* suv = manufacturer.getCar();
    // suv->displayInfo();

}
