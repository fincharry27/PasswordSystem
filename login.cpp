#include <iostream>
#include "authlib.h"
#include "login.h"

using namespace std;



getInput()
{
	string userName;
	string userPassword;

	cout << "Please enter your username. " << endl;
	 cin >> userName;

	cout << "Please enter the password. " << endl;
	cin >> userPassword;

	
	//cout << userName << endl <<  userPassword  ; //just to see if it works

	//code to call hashPassword function

	//return userName + HashedPassword;
}

int main() {
  bool auth = true;
 
  if (auth) authenticated("user");
  else rejected("user");
}

string hashfunction(string password)
{

}

bool compare(string username, string hashedPassword, string savedUsername, string savedPassword)
{
	bool authenticate = false;

	if (username == savedUsername)
	{
		if (hashedPassword == savedPassword)
		{
			authenticate = true;
		}
		else
		{
			std::cout << "Incorrect password" << std::endl;
			return authenticate;
		} 	
	}
	else
	{
		std::cout << "Incorrect username" << std::endl;
		return authenticate;
	} 	
}