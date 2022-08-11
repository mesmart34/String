#pragma once
#include <memory>
#include <iostream>
#include <string.h>

class String
{
public:
    String() = default;
	String(const char* data);
	String(const String& other);
	String(String&& other);
	~String();

	String& operator=(const String& other);
	friend String operator+(const String& a, const String& b);
    bool operator<(const String& other) const;
    bool operator>(const String& other) const;
    friend std::ostream& operator <<(std::ostream& stream, const String& string);

private:
    char* m_data = nullptr;
	size_t m_size{ 0 };
};
