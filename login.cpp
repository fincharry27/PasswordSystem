#include <iostream>
#include "authlib.h"



inputUsername()
{
	string userName;
	

	cout << "Please enter your username. " << endl;
	 cin >> userName;

	//cout << userName ;
	
	return userName;
}

inputPassword()
{
	string userPassword;
	cout << "Please enter the password. " << endl;
	cin >> userPassword;

	//cout << userPassword ;

	return userPassword;
}


int main() {
  bool auth = true;
 
  if (auth) authenticated("user");
  else rejected("user");
}
