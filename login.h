#include <iostream>
#include <string>

std::string input();

bool compare(std::string username, std::string hashedPassword, std::string savedUsername, std::string savedPassword);

std::string hashFunction(std::string password);
