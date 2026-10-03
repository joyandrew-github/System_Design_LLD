#include "model/Address.hpp"

Address::Address(int id,
    const std::string& HouseNumber,
    const std::string& street,
    const std::string& city,
    const std::string& state,
    const std::string& Pincode)
    : id(id),
      HouseNumber(HouseNumber),
      street(street),
      city(city),
      state(state),
      Pincode(Pincode) {}

int Address::getId() const {
    return id;
}

std::string Address::getHouseNumber() const {
    return HouseNumber;
}

std::string Address::getStreet() const {
    return street;
}

std::string Address::getCity() const {
    return city;
}

std::string Address::getState() const {
    return state;
}

std::string Address::getPincode() const {
    return Pincode;
}
