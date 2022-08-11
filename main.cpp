#include "string.h"
#include <vector>
#include <iostream>
#include <algorithm>

int main(int argc, char** argv)
{
    int n = 0;
    std::cout << "Enter a number of words: " << std::endl;
    scanf("%d", &n);
    std::vector<String> strings{};
    for(int i = 0; i < n; i++)
    {
        char data[256];
        scanf("%s", data);
        strings.push_back(data);
    }
    std::sort(strings.begin(), strings.end(), [](const String& str1, const String& str2){return str1 > str2;});
    for(const auto str : strings)
        std::cout << str << std::endl;
	return (0);
}
