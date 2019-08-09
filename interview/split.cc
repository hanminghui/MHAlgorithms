#include <string>
#include <iostream>
#include <vector>

void split(const std::string& s,
		   const std::string& delimiter,
		   std::vector<std::string>& strs);

int main(int argc, char *argv[])
{
	std::vector<std::string> results;
	split("a:", "a", results);
	for(auto r : results)
		std::cout << r << std::endl;
    return 0;
}

/* if delimiter is at the beginning, the first substring is empty
 * if delimiter is at the end, there is no last empty substring
 */
void split(const std::string& s,
		   const std::string& delimiter,
		   std::vector<std::string>& strs)
{
	int start = 0, pos = 0;
	while((pos = s.find(delimiter, start)) != -1)
	{
		strs.push_back(s.substr(start, pos-start));
		start = pos + delimiter.length();
	}
	if(start < s.length())
	    strs.push_back(s.substr(start, s.length() - start));
}
