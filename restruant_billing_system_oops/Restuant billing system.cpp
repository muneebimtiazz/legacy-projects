#include <iostream>
#include <vector>

class MenuItem {
private:
    std::string name;
    double price;

public:
    MenuItem(const std::string& name, double price)
        : name(name), price(price) {}

    std::string getName() const {
        return name;
    }

    double getPrice() const {
        return price;
    }
};

class Order {
private:
    std::vector<MenuItem> items;
    double total;

public:
    Order() : total(0.0) {}

    void addItem(const MenuItem& item) {
        items.push_back(item);
        total += item.getPrice();
    }

    void displayOrder() const {
        std::cout << "Order Details:\n";
        for (std::vector<MenuItem>::const_iterator it = items.begin(); it != items.end(); ++it) {
            std::cout << "Item: " << it->getName() << ", Price: $" << it->getPrice() << std::endl;
        }
        std::cout << "Total: $" << total << std::endl;
    }
};

class Restaurant {
private:
    std::vector<MenuItem> menu;

public:
    void addMenuItem(const MenuItem& item) {
        menu.push_back(item);
    }

    void displayMenu() const {
        std::cout << "Menu:\n";
        for (std::vector<MenuItem>::const_iterator it = menu.begin(); it != menu.end(); ++it) {
            std::cout << "Item: " << it->getName() << ", Price: $" << it->getPrice() << std::endl;
        }
        std::cout << std::endl;
    }

    Order takeOrder() const {
        Order order;
        std::string itemName;
        char choice;

        do {
            std::cout << "Enter item name to add to the order: ";
            std::cin >> itemName;

            bool itemFound = false;
            for (std::vector<MenuItem>::const_iterator it = menu.begin(); it != menu.end(); ++it) {
                if (it->getName() == itemName) {
                    order.addItem(*it);
                    itemFound = true;
                    break;
                }
            }

            if (!itemFound) {
                std::cout << "Invalid item name. Please try again.\n";
            }

            std::cout << "Do you want to add more items to the order? (y/n): ";
            std::cin >> choice;
        } while (choice == 'y' || choice == 'Y');

        return order;
    }
};

int main() {
    Restaurant restaurant;

    // Add menu items
    restaurant.addMenuItem(MenuItem("Burger", 9.99));
    restaurant.addMenuItem(MenuItem("Pizza", 12.99));
    restaurant.addMenuItem(MenuItem("Salad", 6.99));
    restaurant.addMenuItem(MenuItem("Pasta", 10.99));

    // Display the menu
    restaurant.displayMenu();

    // Take an order
    Order order = restaurant.takeOrder();

    // Display the order details
    order.displayOrder();

    return 0;
}

