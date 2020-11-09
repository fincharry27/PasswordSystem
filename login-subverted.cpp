#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <iomanip>
#include "authlib.h"
#include "login.h"

using namespace std;

#include <openssl/sha.h>

string fileName = "3791570.txt";
string userName;
string password;
string hashedPassword;
int listSize = 2;
int listDepth = 0;


//recieves username
string inputUsername()
{
	cout << "Please enter your username. " << endl; //get username input
	cin >> userName; // assign to variable
	return userName; //returns username
}

//recieves password and then hashes it
string inputPassword()
{
	cout << "Please enter the password. " << endl; //recieves password input
	cin >> password; // assign to variable
	return password; // returns hashed password
}

int main() {
	string username;
	string hashPass;
	string userPassword;
	bool logInSuccess;
	username = inputUsername();
	userPassword = inputPassword();
	hashPass = hashFunction(userPassword);
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

//Takes in a username and a hashed password and compares them to the usernames and passwords on file
//Returns boolean variable based on log in success
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
    string master[count][2];

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

        master[i][0] = unformattedList[0];
        master[i][1] = unformattedList[1];
        i++;
    }
    //after the file has been read and the string split into two lists we begin
    //with comparing the user entered data to the data stored on file
    bool authenticate = false;
	int counter = 0;

	//find the size of the list (not hard coded to allow easy expansion)

	//while there are still items in the lists and we are not already logged in
	while (counter < listSize && authenticate == false)
	{
		//if the username provided matches on on file then check password, if it doesn't then dont check the password
		if (username == master[counter][listDepth])
		{	
			//if the password provided mathces any password in the file then provisionally authorise
			if (hashedPassword == master[counter][listDepth+1])
			{
				authenticate = true;
				//std::cout << "Log In successfull" << std::endl;
				//authenticated(username);
			}
			else
			{
				std::cout << "Incorrect password" << std::endl;
				authenticate = false;
			}
			//if password matches the password stored against the username entered, confirm authorisation
			if(password == master[counter][listDepth])
			{
				authenticate = true;
			} 
		}
		else
		{
			std::cout << "Incorrect username" << std::endl;
			authenticate = false;
		}
		counter++;
	}

	//returns true if log in was successfull and false if not
	return authenticate;
}