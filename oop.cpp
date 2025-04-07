#include <iostream>
#include <string>
using namespace std;

class Cars {
    public:
        string company_name;
        string model_name;
        string fuel_type;
        float mileage;
        double price;
        double discount;
        double discounted_price; // Add this member variable

    public:
        void setData(string cname, string mname, string ftype, float m, double p, double d) {
            company_name = cname;
            model_name = mname;
            fuel_type = ftype;
            mileage = m;
            price = p;
            discount = d;
        }
        void displayData() {
            cout << "Car Properties" << endl;
            cout << "Company Name: " << company_name << endl;
            cout << "Model Name: " << model_name << endl;
            cout << "Fuel Type: " << fuel_type << endl;
            cout << "Mileage (km per litre): " << mileage << endl;
            cout << "Price: " << price << endl;
        }
        void calculateDiscount() {
            discounted_price = price - (price * discount);
            cout << "Discounted Price: " << discounted_price << endl;
        }

        void discountPrice() {
            cout << "Discounted Price: " << price - (price * discount) << endl;
        }
};

int main() {
    Cars car1, car2, car3;
    car1.setData("Toyota", "Fortuner", "Petrol", 10.5, 3500000, 0.1);
    car2.setData("Maruti", "Swift", "Diesel", 20.5, 800000, 0.2);
    car3.setData("Hyundai", "Creta", "Petrol", 15.5, 1200000, 0.15);

    car1.calculateDiscount();
    car2.calculateDiscount();

    cout << "Total Discounted Price (Car1 + Car2): " 
         << car1.discounted_price + car2.discounted_price << endl;

    return 0;
}