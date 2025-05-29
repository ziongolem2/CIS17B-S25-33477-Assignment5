// Saul Resendiz
// CIS-17B
// Template Assignment


#include <iostream>
#include <string>
#include <array>
#include <typeinfo>

template<typename T>
class Package {
private:
    T item;
public:
    Package(T i) : item(i) {}
    void label() {
        std::cout << "Generic package containing: " << typeid(T).name() << "\n";
    }
};

// Specialization for std::string
template<>
class Package<std::string> {
private:
    std::string item;
public:
    Package(std::string i) : item(i) {}
    void label() {
        std::cout << "Book package: \"" << item << "\"\n";
    }
};

// Partial specialization for pointers
template<typename T>
class Package<T*> {
private:
    T* item;
public:
    Package(T* i) : item(i) {}
    void label() {
        std::cout << "Fragile package for pointer to type: " << typeid(T).name() << "\n";
    }
};

template<typename T, int Size>
class Box {
private:
    std::array<T, Size> items;
    int count = 0;
public:
    bool addItem(const T& item) {
        if (count < Size) {
            items[count++] = item;
            std::cout << "Added item to box: \"" << item << "\"\n";
            return true;
        }
        return false;
    }

    void printItems() const {
        std::cout << "Box contents:\n";
        for (int i = 0; i < count; ++i) {
            std::cout << " - " << items[i] << "\n";
        }
    }
};

template<typename T>
void shipItem(const T& item) {
    std::cout << "Shipping item of type: " << typeid(T).name() << "\n";
}

template<>
void shipItem(const double& item) {
    std::cout << "Shipping temperature-controlled item: " << item << "°C\n";
}

int main() {
    // MAIN

    // Calling our generic package of type int - display
    Package<int> intPackage(30);
    intPackage.label();

    // Calling our specialized package for type string - display
    Package<std::string> bookPackage("The Lorax");
    bookPackage.label();

    // Calling partial specialization 
    double fragItem = 6.49;
    Package<double*> fragilePackage(&fragItem);
    fragilePackage.label(); // Displaying 

    // Calling our box class with size as parameter
    Box<std::string, 2> bookBox;
    bookBox.addItem("The Giving Tree");
    bookBox.addItem("C++ Data Structures");
    bookBox.printItems();

    // Calling shipping template and displaying the shipping type details to console
    shipItem(45);
    shipItem(std::string("iPhone"));
    shipItem(20.5);

    return 0;
}
