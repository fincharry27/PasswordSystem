#include <iostream>
#include "authlib.h"
#include "login.h"

using namespace std;

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