#include <iostream>
#include <string>

std::string inputUsername();

std::string inputPassword();

std::string hashFunction(std::string password);

bool checkLogInFile(std::string username, std::string hashedPassword);