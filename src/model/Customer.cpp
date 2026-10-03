#include "model/Customer.hpp"

Customer::Customer(int id,
const std::string& name,
const std::string& email,
const std::string& phoneNumber): 
User(id, name, email, phoneNumber) {}

void Customer::addAddress(const Address& address){
    addresses.push_back(address);
}

const std::vector<Address>& Customer::getAddresses() const{
    return addresses;
}