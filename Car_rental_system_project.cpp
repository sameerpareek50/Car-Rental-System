#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Car
{
public:
    Car(const string &make, const string &model, int year, double price)
        : make_(make), model_(model), year_(year), price_(price) {}

    void DisplayCarInfo() const
    {
        cout << "Make: " << make_ << "\nModel: " << model_
             << "\nYear: " << year_ << "\nPrice per day: $" << price_ << endl;
    }

    void UpdateCarInfo(const string &make, const string &model, int year, double price)
    {
        make_ = make;
        model_ = model;
        year_ = year;
        price_ = price;
    }

private:
    string make_;
    string model_;
    int year_;
    double price_;
};

class CarRentalSystem
{
public:
    void AddCar(const Car &car)
    {
        cars_.push_back(car);
    }

    void ModifyCar(int carIndex, const Car &newCarInfo)
    {
        if (carIndex >= 0 && carIndex < cars_.size())
        {
            cars_[carIndex] = newCarInfo;
            cout << "Car information updated successfully." << endl;
        }
        else
        {
            cout << "Invalid car index. Please enter a valid index." << endl;
        }
    }

    void ViewCars() const
    {
        if (cars_.empty())
        {
            cout << "No cars available in the rental system." << endl;
        }
        else
        {
            cout << "Available cars in the rental system:" << endl;
            for (size_t i = 0; i < cars_.size(); ++i)
            {
                cout << "Car " << i + 1 << ":\n";
                cars_[i].DisplayCarInfo();
                cout << "-----------------------------" << endl;
            }
        }
    }

private:
    vector<Car> cars_;
};

int main()
{
    CarRentalSystem rentalSystem;

    // Add some initial cars to the system
    rentalSystem.AddCar(Car("Toyota", "Camry", 2020, 50.0));
    rentalSystem.AddCar(Car("Honda", "Civic", 2021, 45.0));

    int choice;

    do
    {
        cout << "\nCar Rental System Menu:\n"
             << "1. Add a new car\n"
             << "2. Modify car information\n"
             << "3. View available cars\n"
             << "4. Quit\n"
             << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string make, model;
            int year;
            double price;

            cout << "Enter car make: ";
            cin >> make;
            cout << "Enter car model: ";
            cin >> model;
            cout << "Enter car year: ";
            cin >> year;
            cout << "Enter car price per day: $";
            cin >> price;

            rentalSystem.AddCar(Car(make, model, year, price));
            cout << "Car added successfully." << endl;
        }
        break;

        case 2:
        {
            int carIndex;
            cout << "Enter the index of the car you want to modify: ";
            cin >> carIndex;

            string make, model;
            int year;
            double price;

            cout << "Enter new car make: ";
            cin >> make;
            cout << "Enter new car model: ";
            cin >> model;
            cout << "Enter new car year: ";
            cin >> year;
            cout << "Enter new car price per day: $";
            cin >> price;

            Car newCarInfo(make, model, year, price); // Construct newCarInfo with parameters

            rentalSystem.ModifyCar(carIndex - 1, newCarInfo);
        }
        break;

        case 3:
            rentalSystem.ViewCars();
            break;
        case 4:
            cout << "Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice. Please select a valid option." << endl;
        }

    } while (choice != 4);

    return 0;
}
