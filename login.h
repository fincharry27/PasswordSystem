#include <iostream>
#include <string>

std::string inputUsername();

std::string inputPassword();

int compare(std::string username, std::string hashedPassword, std::string savedUsername_li[], std::string savedPassword_li[]);

std::string hashFunction(std::string password);

int readFile(std::string username, std::string hashedPassword);