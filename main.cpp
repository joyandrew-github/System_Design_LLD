#include <iostream>
#include <iomanip>

#include "model/User.hpp"
#include "model/Customer.hpp"
#include "model/Address.hpp"
#include "model/Restaurant.hpp"

void printSeparator(char c = '=', int width = 50) {
    std::cout << std::string(width, c) << std::endl;
}

void printSection(const std::string& title) {
    printSeparator('=', 50);
    std::cout << "  " << title << std::endl;
    printSeparator('-', 50);
}

void printKV(const std::string& key, const std::string& value, int keyWidth = 20) {
    std::cout << "  " << std::left << std::setw(keyWidth) << key << ": " << value << std::endl;
}

void printAddress(const Address& addr, const std::string& prefix = "  ") {
    printKV("Address ID", std::to_string(addr.getId()));
    printKV("House Number", addr.getHouseNumber());
    printKV("Street", addr.getStreet());
    printKV("City", addr.getCity());
    printKV("State", addr.getState());
    printKV("Pincode", addr.getPincode());
}

int main() {
    // Create User
    User user(1, "John Doe", "john@gmail.com", "123-456-7890");
    
    // Create Customer with Address
    Customer customer(2, "Jane Doe", "jane@gmail.com", "098-765-4321");
    Address home(1, "123", "Main Street", "New York", "NY", "10001");
    customer.addAddress(home);
    
    // Create Restaurant with Address
    Address restaurantAddr(2, "456", "Broadway", "New York", "NY", "10002");
    Restaurant restaurant(1, "Pizza Place", restaurantAddr, true);
    restaurant.open();

    // Print structured output
    printSection("USER DETAILS");
    printKV("ID", std::to_string(user.getId()));
    printKV("Name", user.getName());
    printKV("Email", user.getEmail());
    printKV("Phone", user.getPhoneNumber());

    printSection("CUSTOMER DETAILS");
    printKV("ID", std::to_string(customer.getId()));
    printKV("Name", customer.getName());
    printKV("Email", customer.getEmail());
    printKV("Phone", customer.getPhoneNumber());

    printSection("CUSTOMER ADDRESSES");
    const auto& addresses = customer.getAddresses();
    for (size_t i = 0; i < addresses.size(); ++i) {
        std::cout << "  Address #" << (i + 1) << ":" << std::endl;
        printAddress(addresses[i], "    ");
    }

    printSection("RESTAURANT DETAILS");
    printKV("ID", std::to_string(restaurant.getId()));
    printKV("Name", restaurant.getName());
    printKV("Status", restaurant.getIsOpen() ? "Open" : "Closed");

    printSection("RESTAURANT ADDRESS");
    printAddress(restaurant.getAddress());

    printSeparator('=', 50);
    std::cout << "  All data printed successfully!" << std::endl;
    printSeparator('=', 50);

    return 0;
}