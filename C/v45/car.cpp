#include <iostream>
#include <string>
#include <memory>

class Car {
    public:
        std::string brand;
        std::string model;
        int year;
        double mileage;

    Car(std::string brand, std::string model, int year, double mileage)
        : brand(brand), model(model), year(year), mileage(mileage) {};

    Car(Car& car) {
        brand = car.brand;
        model = car.model;
        year = car.year;
        mileage = car.mileage;
        std::cout << "\n------------\nCopy of car made\n------------" << std::endl;
    }

    void drive(double distance) {
        mileage += distance;
    }

    void displayInfo() {
        std::cout << "\nBrand: " << brand << std::endl;
        std::cout << "Model: " << model << std::endl;
        std::cout << "Year: " << year << std::endl;
        std::cout << "Mileage: " << mileage << std::endl;
    }

    int getYear() {
        return year;
    }

    double getMileage() {
        return mileage;
    }

    virtual ~Car() {
        std::cout << "\n------------\nCar deleted\n------------\n";
    }
}; 

int main() {
    Car* car = new Car("Ferrari", "F1", 2024, 500);
    car->displayInfo();

    car->drive(50);
    car->displayInfo();

    Car copy(*car);

    delete car;

    copy.displayInfo();

    return 0;
}