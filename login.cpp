#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <iomanip>
#include "authlib.h"
#include "login.h"

using namespace std;

#include <openssl/sha.h>

int SUCCESS = 0;
int FAILURE = 5;
string fileName = "3791570.txt";

//recieves username
string inputUsername()
{
	string userName;
	cout << "Please enter your username. " << endl; //get username input
	cin >> userName; // assign to variable
	return userName; //returns username
}

//recieves password and then hashes it
string inputPassword()
{
	string userPassword;
	string hashedPassword;
	cout << "Please enter the password. " << endl; //recieves password input
	cin >> userPassword; // assign to variable

	//hashing the password immediatley 
	hashedPassword = hashFunction(userPassword);
	return hashedPassword; // returns hashed password
}

int main() {
	string username;
	string hashPass;
	bool logInSuccess;
	username = inputUsername();
	hashPass = inputPassword();
	logInSuccess = checkLogInFile(username,hashPass);
	if(logInSuccess == true)
	{
		authenticated(username);
	}
	else
	{
		rejected(username);
	}

	return 0;
}

// This function was created with reference to this stack overflow page https://stackoverflow.com/questions/2262386/generate-sha256-with-openssl-and-c
string hashFunction(const string password)
{
	unsigned char hash[SHA256_DIGEST_LENGTH];
	SHA256_CTX sha256;
	SHA256_Init(&sha256);
	SHA256_Update(&sha256, password.c_str(), password.size());
	SHA256_Final(hash, &sha256);

	string outPass = "";
	for (int i = 0; i < SHA256_DIGEST_LENGTH; i++)
	{
		stringstream ss;
    	ss << hex << setw(2) << setfill('0') << (int) hash[i];
		outPass += ss.str();
	}
	return outPass;
}

bool checkLogInFile(string username, string hashedPassword){
    string line;
    //Seeing how large arrays need to be
    int count = 0;
    ifstream fileCount(fileName);
    while (getline(fileCount, line)){
        count++;
    }
    string unFormatted[count];
    string names[count];
    string passwords[count];
    //Reading in each line of the file
    int i= 0;
    ifstream fileRead(fileName);
    while (getline(fileRead, line)){
        unFormatted[i] = line;
        //Splitting each line of the file into separate arrays for password and username
        stringstream unFormattedStringOpen(unFormatted[i]);
        string components;
        vector<string> unformattedList;
        while(getline(unFormattedStringOpen, components, ':'))
        {
            unformattedList.push_back(components);

        }
        names[i] = unformattedList[0];
        passwords[i] = unformattedList[1];
        i++;
    }

    bool authenticate = false;
	int counter = 0;

	int liSize = *(&names+1) - names;

	while (counter < liSize && authenticate == false)
	{
		std::cout << "names[counter]: " << names[counter] << std::endl;
		std::cout << "passwords[counter]: " << passwords[counter] << std::endl;
		if (username == names[counter])
		{
			if (hashedPassword == passwords[counter])
			{
				authenticate = true;
				std::cout << "Log In successfull" << std::endl;
				//authenticated(username);
			}
			else
			{
				std::cout << "Incorrect password" << std::endl;
				//rejected(username);
			} 	
		}
		else
		{
			std::cout << "Incorrect username" << std::endl;
			//rejected(username);
		}
		counter++;
	}

	return authenticate;
}
