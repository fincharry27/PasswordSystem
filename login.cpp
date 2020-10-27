#include <iostream>
#include <sstream>
#include "authlib.h"
#include "login.h"
#include <openssl/sha.h>

using namespace std;

int main() 
{
 // bool auth = true;
 
 // if (auth) authenticated("user");
 // else rejected("user");
	cout << hashFunction("password") <<endl;
	return 0;
}


// This function was created with reference to this stack overflow page https://stackoverflow.com/questions/2262386/generate-sha256-with-openssl-and-c
string hashFunction(string password)
{
	unsigned char hash[SHA256_DIGEST_LENGTH];
	SHA256_CTX sha256;
	SHA256_Init(&sha256);
	SHA256_Update(&sha256, password.c_str(), password.length());
	SHA256_Final(hash, &sha256);

	string outPass = "";
	for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i)
	{
		stringstream ss;
    	ss << hex << (int) hash[i];
		outPass += ss.str();
	}
	return outPass;
}