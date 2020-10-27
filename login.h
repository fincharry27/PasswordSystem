#include <iostream>
#include <string>

std::string inputUsername();

std::string inputPassword();

bool compare(std::string username, std::string hashedPassword, std::string savedUsername, std::string savedPassword);

std::string hashFunction(std::string password);
