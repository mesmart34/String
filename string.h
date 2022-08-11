#pragma once
#include <memory>
#include <iostream>

class String
{
public:
	String() = default;
	String(const char* data);
	String(const String& other);
	String(String&& other);
	~String();

	char* getRaw() const;
	size_t getSize();

	String& operator=(const String& other);
	friend String operator+(const String& a, const String& b);
	bool operator<(const String& other);
	bool operator>(const String& other);

	friend std::ostream& operator <<(std::ostream& stream, const String& string);

private:
	char* m_data = nullptr;
	size_t m_size{ 0 };
};