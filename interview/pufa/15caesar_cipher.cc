#include <iostream>
#include <string>

std::string encode(std::string& plain);
std::string decode(std::string& cipher);

int main(int argc, char *argv[])
{
	std::string plain{"test, XYZ, abc!!!"};
	std::cout << "plain:"<< plain << std::endl;
	std::string cipher = encode(plain);
	std::cout << "cipher:"<< cipher << std::endl;
	std::string plain_back = decode(cipher);
	std::cout << "plain_back:"<< plain_back << std::endl;

    return 0;
}

std::string encode(std::string& plain)
{
	std::string cipher;
	for(int i = 0; i < plain.size(); i++)
	{
		if(plain[i] >= 'a' && plain[i] <= 'z')
		{
			cipher += 'a' + (plain[i] - 'a' + 5) % 26;
		}
		else if(plain[i] >= 'A' && plain[i] <= 'Z')
		{
			cipher += 'A' + (plain[i] - 'A' + 5) % 26;
		}
		else
		{
		    cipher += plain[i];
		}
	}
	return cipher;
}

std::string decode(std::string& cipher)
{
	std::string plain;
	for(int i = 0; i < cipher.size(); i++)
	{
		if(cipher[i] >= 'a' && cipher[i] <= 'z')
		{
			plain += 'a' + (cipher[i] - 'a' + 21) % 26;
		}
		else if(cipher[i] >= 'A' && cipher[i] <= 'Z')
		{
			plain += 'A' + (cipher[i] - 'A' + 21) % 26;
		}
		else
		{
		    plain += cipher[i];
		}
	}
	return plain;
}
