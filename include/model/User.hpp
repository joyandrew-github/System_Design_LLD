#pragma once
#include <string>

class User {
    private:
        int id;
        std::string name;
        std::string email;
        std::string phoneNumber;
    public:
        User(
            int id,
            const std::string& name,
            const std::string& email,
            const std::string& phoneNumber
        );
        int getId() const;
        std::string getName() const;
        std::string getEmail() const;
        std::string getPhoneNumber() const;
};;