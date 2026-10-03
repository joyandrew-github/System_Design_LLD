#pragma once
#include "model/User.hpp"
#include "model/Address.hpp"
#include <vector>

class Customer: public User{
    private:
        std::vector<Address> addresses;
    public:
        Customer(
            int id,
            const std::string& name,
            const std::string& email,
            const std::string& phoneNumber
        );
        void addAddress(const Address& address);
        const std::vector<Address>& getAddresses() const;
};
