#include <iostream>
#include "authlib.h"






int main() {
  bool auth = true;
 
  if (auth) authenticated("user");
  else rejected("user");
}


//recieves username
string inputUsername()
{
	string userName;
	

	cout << "Please enter your username. " << endl;
	 cin >> userName;

	//cout << userName ;
	
	return userName;
}


//recieves password to be hashed
string inputPassword()
{
	string userPassword;
	cout << "Please enter the password. " << endl;
	cin >> userPassword;

	//cout << userPassword ;

	return userPassword;
}
