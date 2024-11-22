#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Product {
private:
    string name;
    double price;
    bool onPromotion;

public:
    Product(string n, double p, bool promo = false) : name(n), price(p), onPromotion(promo) {}

    string getName() const { return name; }
    double getPrice() const { return price; }
    bool isOnPromotion() const { return onPromotion; }

    void setPrice(double p) { price = p; }
    void setPromotion(bool promo) { onPromotion = promo; }

    void display() const {
        cout << "Product: " << name << ", Price: $" << price;
        if (onPromotion) cout << " (On Promotion)";
        cout << endl;
    }
};

class Category {
private:
    string name;
    vector<Product> products;

public:
    Category(string n) : name(n) {}

    string getName() const { return name; }

    void addProduct(const Product& p) {
        products.push_back(p);
    }

    void removeProduct(const string& productName) {
        products.erase(remove_if(products.begin(), products.end(),
            [&](const Product& p) { return p.getName() == productName; }), products.end());
    }

    void updateProduct(const string& productName, double newPrice, bool promoStatus) {
        for (auto& product : products) {
            if (product.getName() == productName) {
                product.setPrice(newPrice);
                product.setPromotion(promoStatus);
            }
        }
    }

    const vector<Product>& getProducts() const {
        return products;
    }
};

class OnlineShop {
private:
    string shopName;
    vector<Category> categories;

public:
    OnlineShop(string name) : shopName(name) {}

    void addCategory(const Category& c) {
        categories.push_back(c);
    }

    void removeCategory(const string& categoryName) {
        categories.erase(remove_if(categories.begin(), categories.end(),
            [&](const Category& c) { return c.getName() == categoryName; }), categories.end());
    }

    void displayAllProducts() const {
        for (const auto& category : categories) {
            cout << "\nCategory: " << category.getName() << endl;
            for (const auto& product : category.getProducts()) {
                product.display();
            }
        }
    }

    void displayProductsOnPromotion() const {
        for (const auto& category : categories) {
            for (const auto& product : category.getProducts()) {
                if (product.isOnPromotion()) {
                    product.display();
                }
            }
        }
    }

    void searchProducts(const string& name = "", double minPrice = 0, double maxPrice = 1e6) const {
        cout << "\nSearch Results:" << endl;
        for (const auto& category : categories) {
            for (const auto& product : category.getProducts()) {
                if ((name.empty() || product.getName().find(name) != string::npos) &&
                    product.getPrice() >= minPrice && product.getPrice() <= maxPrice) {
                    product.display();
                }
            }
        }
    }
};

int main() {
    OnlineShop shop("My Online Store");

    Category electronics("Electronics");
    electronics.addProduct(Product("Laptop", 999.99));
    electronics.addProduct(Product("Smartphone", 499.49, true));

    Category clothing("Clothing");
    clothing.addProduct(Product("T-shirt", 19.99));
    clothing.addProduct(Product("Jeans", 49.99, true));

    shop.addCategory(electronics);
    shop.addCategory(clothing);

    cout << "\nAll Products in the Shop:";
    shop.displayAllProducts();

    cout << "\nProducts on Promotion:";
    shop.displayProductsOnPromotion();

    cout << "\nSearching for products between $20 and $1000:";
    shop.searchProducts("", 20, 1000);

    return 0;
}
