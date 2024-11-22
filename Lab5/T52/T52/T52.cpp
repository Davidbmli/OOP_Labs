#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Product {
protected:
    string name;
    double price;

public:
    Product(string n, double p) : name(n), price(p) {}

    string getName() const { return name; }
    double getPrice() const { return price; }

    virtual void display() const {
        cout << name << " - $" << price << endl;
    }

    bool operator<(const Product& other) const {
        return name < other.name;
    }

    bool operator>(const Product& other) const {
        return price > other.price;
    }
};

class Shoes : public Product {
public:
    Shoes(string n, double p) : Product(n, p) {}

    void display() const override {
        cout << "Shoe: ";
        Product::display();
    }
};

class Toys : public Product {
public:
    Toys(string n, double p) : Product(n, p) {}

    void display() const override {
        cout << "Toy: ";
        Product::display();
    }
};

class Department {
private:
    string departmentName;
    vector<Product*> products;

public:
    Department(string name) : departmentName(name) {}

    void addProduct(Product* product) {
        products.push_back(product);
    }

    void addProducts(const vector<Product*>& newProducts) {
        products.insert(products.end(), newProducts.begin(), newProducts.end());
    }

    Product* findProduct(const string& productName) {
        for (auto& product : products) {
            if (product->getName() == productName)
                return product;
        }
        return nullptr;
    }

    void removeProduct(Product* product) {
        auto it = find(products.begin(), products.end(), product);
        if (it != products.end()) {
            products.erase(it);
        }
    }

    void removeProducts(const vector<Product*>& productsToRemove) {
        for (auto& product : productsToRemove) {
            removeProduct(product);
        }
    }

    void displayProductsSortedByName() const {
        vector<Product*> sortedProducts = products;
        sort(sortedProducts.begin(), sortedProducts.end());
        for (auto& product : sortedProducts) {
            product->display();
        }
    }

    void displayProductsSortedByPrice() const {
        vector<Product*> sortedProducts = products;
        sort(sortedProducts.begin(), sortedProducts.end(), [](Product* a, Product* b) {
            return a->getPrice() < b->getPrice();
            });
        for (auto& product : sortedProducts) {
            product->display();
        }
    }

    void displayAllProducts() const {
        for (auto& product : products) {
            product->display();
        }
    }

    const vector<Product*>& getProducts() const {
        return products;
    }

    string getDepartmentName() const {
        return departmentName;
    }
};

class Order {
private:
    vector<Product*> products;

public:
    void addProduct(Product* product) {
        products.push_back(product);
    }

    void displayOrder() const {
        cout << "Order contains: " << endl;
        for (auto& product : products) {
            product->display();
        }
    }

    double computeTotal() const {
        double total = 0;
        for (auto& product : products) {
            total += product->getPrice();
        }
        return total;
    }

    vector<Product*> getProducts() const {
        return products;
    }
};

class Store {
private:
    Department shoesDepartment;
    Department toysDepartment;
    vector<Order> orders;

public:
    Store() : shoesDepartment("Shoes"), toysDepartment("Toys") {}

    void addOrder(Order& order) {
        orders.push_back(order);
    }

    void displayShoes() const {
        shoesDepartment.displayAllProducts();
    }

    void displayToys() const {
        toysDepartment.displayAllProducts();
    }

    void searchProductInOrders(const string& productName) const {
        cout << "Searching for " << productName << " in orders:" << endl;
        for (const auto& order : orders) {
            for (const auto& product : order.getProducts()) {
                if (product->getName() == productName) {
                    product->display();
                }
            }
        }
    }

    double computeTotalOrderValues() const {
        double totalValue = 0;
        for (const auto& order : orders) {
            totalValue += order.computeTotal();
        }
        return totalValue;
    }

    Department& getShoesDepartment() {
        return shoesDepartment;
    }

    Department& getToysDepartment() {
        return toysDepartment;
    }
};

int main() {
    Store store;

    Shoes* shoe1 = new Shoes("Nike Air Max", 120);
    Shoes* shoe2 = new Shoes("Adidas Ultraboost", 150);
    Toys* toy1 = new Toys("LEGO Set", 50);
    Toys* toy2 = new Toys("Action Figure", 25);

    store.getShoesDepartment().addProduct(shoe1);
    store.getShoesDepartment().addProduct(shoe2);
    store.getToysDepartment().addProduct(toy1);
    store.getToysDepartment().addProduct(toy2);

    store.displayShoes();
    store.displayToys();

    vector<Product*> newProducts = { new Shoes("Puma Running", 80), new Toys("Drone", 200) };
    store.getShoesDepartment().addProducts(newProducts);
    store.getToysDepartment().addProducts(newProducts);

    cout << "\nShoes sorted by name:" << endl;
    store.getShoesDepartment().displayProductsSortedByName();

    cout << "\nToys sorted by price:" << endl;
    store.getToysDepartment().displayProductsSortedByPrice();

    Order order1;
    order1.addProduct(shoe1);
    order1.addProduct(toy1);
    store.addOrder(order1);

    cout << "\nOrder 1:" << endl;
    order1.displayOrder();

    cout << "Total order value: $" << order1.computeTotal() << endl;

    store.searchProductInOrders("Nike Air Max");

    cout << "Total value of all orders: $" << store.computeTotalOrderValues() << endl;

    delete shoe1;
    delete shoe2;
    delete toy1;
    delete toy2;

    return 0;
}
