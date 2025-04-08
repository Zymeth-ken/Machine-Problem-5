#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Sarisari {
public:
    string id;
    string product_name;
    string price_tag;
    string shelf_life;
    float pcs_product;
    double total_price;

public:
    void setData(string id, string pname, string ptag, string slife, float pproduct) {
        this->id = id;
        this->product_name = pname;
        this->price_tag = ptag;
        this->shelf_life = slife;
        this->pcs_product = pproduct;
        this->total_price = 0;
    }

    void CalculateTotal(int quantity) {
        float price = stof(price_tag);
        total_price = price * quantity;
    }

    string getId() const {
        return id;
    }

    string getProductName() const {
        return product_name;
    }

    float getPrice() const {
        return stof(price_tag);
    }
};

int main() {
    vector<Sarisari> products;

    Sarisari product1, product2, product3, product4, product5, product6, product7, product8;

    product1.setData("10245", "Mangoes", "20", "60", 100);
    product2.setData("20255", "Apple", "15", "38", 50);
    product3.setData("30356", "C2 Red", "30", "360", 200);
    product4.setData("12347", "Bukopie", "40", "120", 150);
    product5.setData("77878", "Magic_sarap", "10", "520", 1000);
    product6.setData("10255", "C2 Green", "25", "60", 300);
    product7.setData("12032", "Boy_Bawang", "18", "60", 140);
    product8.setData("11234", "Banana", "7", "24", 30);

    products.push_back(product1);
    products.push_back(product2);
    products.push_back(product3);
    products.push_back(product4);
    products.push_back(product5);
    products.push_back(product6);
    products.push_back(product7);
    products.push_back(product8);

    string searchInput;
    cout << "Enter the product ID or Name to search: ";
    cin >> searchInput;

    bool found = false;
    for (auto& product : products) {
        if (product.getId() == searchInput || product.getProductName() == searchInput) {
            found = true;

            int quantity;
            cout << "Enter the quantity of the product: ";
            cin >> quantity;

            product.CalculateTotal(quantity);
            cout << "Total Price for " << quantity << " " << product.getProductName() << "(s): " << product.total_price << endl;
            break;
        }
    }

    if (!found) {
        cout << "Product with ID or Name '" << searchInput << "' not found." << endl;
    }

    return 0;
}
