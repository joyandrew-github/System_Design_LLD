#pragma once

#include <string>

class Address{
    private:
        int id;
        std::string HouseNumber;
        std::string street;
        std::string city;
        std::string state;
        std::string Pincode;
    public:
        Address(
            int id,
            const std::string& HouseNumber,
            const std::string& street,
            const std::string& city,
            const std::string& state,
            const std::string& Pincode
        );
        int getId() const;
        std::string getHouseNumber() const;
        std::string getStreet() const;
        std::string getCity() const;
        std::string getState() const;
        std::string getPincode() const;
};