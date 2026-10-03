#pragma once
#include <string>
#include <vector>
#include "model/Address.hpp"

class Restaurant{
    private:
        int id;
        std::string name;
        Address address;
        bool isOpen;

    public:
        Restaurant(
            int id,
            const std::string& name,
            const Address& address,
            bool isOpen
        );
        int getId() const;
        std::string getName() const;
        const Address& getAddress() const;
        bool getIsOpen() const;

        void open();
        void close();
};