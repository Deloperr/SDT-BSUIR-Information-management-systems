#include <iostream>
#include <string>
#include <memory>
#include <stdexcept>

using namespace std;

class Product {
public:
    virtual ~Product() = default;
    virtual void ShowInfo() const = 0;
    virtual void UniqueOperation() const = 0;
};

class Smartphone : public Product {
    string brand;
    double price;
    string os;
public:
    Smartphone(string b, double p, string o)
        : brand(b), price(p), os(o) {}

    void ShowInfo() const override {
        cout << "\nСмартфон"
            << "\nМарка: " << brand
            << "\nЦена: $" << price
            << "\nОС: " << os << endl;
    }

    void UniqueOperation() const override {
        cout << "Сканер отпечатка пальца\n";
    }
};

class Computer : public Product {
    string model;
    double price;
    string gpu;
public:
    Computer(string m, double p, string g)
        : model(m), price(p), gpu(g) {}

    void ShowInfo() const override {
        cout << "\nКомпьютер"
            << "\nМодель: " << model
            << "\nЦена: $" << price
            << "\nВидеокарта: " << gpu << endl;
    }

    void UniqueOperation() const override {
        cout << "Присутствует дискретная видеокарта\n";
    }
};

class Factory {
public:
    virtual ~Factory() = default;
    virtual unique_ptr<Product> CreateProduct() const = 0;
};

class SmartphoneFactory : public Factory {
public:
    unique_ptr<Product> CreateProduct() const override {
        return make_unique<Smartphone>("OnePlus 13", 899.99, "Android 15");
    }
};

class ComputerFactory : public Factory {
public:
    unique_ptr<Product> CreateProduct() const override {
        return make_unique<Computer>("HP Vicrus 16", 939.99, "RTX 3050");
    }
};

unique_ptr<Factory> select_factory(const string& config) {
    if (config == "1") return make_unique<SmartphoneFactory>();
    if (config == "2") return make_unique<ComputerFactory>();
    throw invalid_argument("Неверный выбор");
}

int main() {
    system("chcp 1251");
    try {
        cout << "Выберите тип продукта:\n"
            << "1 - Смартфон\n"
            << "2 - Компьютер\n"
            << "Ваш выбор: ";

        string choice;
        cin >> choice;

        auto factory = select_factory(choice);
        auto product = factory->CreateProduct();

        product->ShowInfo();
        product->UniqueOperation();

    }
    catch (const exception& e) {
        cerr << "\nОшибка: Некорректный ввод. Выберите 1 или 2.\n";
        return 1;
    }

    return 0;
}
