#include "string.h"
#include <vector>
#include <iostream>
#include <algorithm>


int main(int argc, char** argv)
{
	std::vector<String> strings{
		"ccc", "cab", "abc", "bca", "aaa", "bb", "bc"
	};
	std::sort(strings.begin(), strings.end());
	std::cout << (String("ca") >  String("abb")) << std::endl;
	std::cout << (String("aaa") < String("bbb")) << std::endl;
	return (0);
}