#include <iostream>
#include "authlib.h"
#include "login.h"

using namespace std;

int main() {
  bool auth = true;
 
  if (auth) authenticated("user");
  else rejected("user");
}

string hashfunction(string password){
	
}