#include "model/Restaurant.hpp"

Restaurant::Restaurant(int id,
    const std::string& name,
    const Address& address,
    bool isOpen)
    : id(id),
      name(name),
      address(address),
      isOpen(isOpen) {}

int Restaurant::getId() const {
    return id;
}

std::string Restaurant::getName() const {
    return name;
}

const Address& Restaurant::getAddress() const {
    return address;
}

bool Restaurant::getIsOpen() const {
    return isOpen;
}

void Restaurant::open() {
    isOpen = true;
}

void Restaurant::close() {
    isOpen = false;
}