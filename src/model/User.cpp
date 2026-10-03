#include "model/User.hpp"

User::User(int id, const std::string& name, const std::string& email, const std::string& phoneNumber)
    : id(id), name(name), email(email), phoneNumber(phoneNumber) {}

int User::getId() const {
    return id;
}

std::string User::getName() const {
    return name;
}

std::string User::getEmail() const {
    return email;
}

std::string User::getPhoneNumber() const {
    return phoneNumber;
}