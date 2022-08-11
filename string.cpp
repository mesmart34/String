#include "string.h"

String::String(const char* data)
{
    m_size = strlen(data);
    m_data = (char*)malloc(m_size + 1);
    strcpy(m_data, data);
}

String::String(const String& other)
{
    m_size = other.m_size;
    if (m_size == 0)
        return;
    if (m_data == nullptr)
        m_data = (char*)malloc(m_size + 1);
    strcpy(m_data, other.m_data);
}

String::String(String&& other)
    : m_data{ other.m_data }, m_size(other.m_size)
{
    other.m_data = nullptr;
    other.m_size = 0;
}

String::~String() {
    if(m_data != nullptr)
        free(m_data);
    m_data = nullptr;
}

String& String::operator=(const String& other)
{
    m_size = other.m_size;
    m_data = (char*)malloc(m_size + 1);
    strcpy(m_data, other.m_data);
    return *this;
}

bool String::operator<(const String& other) const
{
    return strcasecmp(m_data, other.m_data) < 0;
}

bool String::operator>(const String& other) const
{
    return strcasecmp(m_data, other.m_data) > 0;
}

String operator+(const String& a, const String& b)
{
    String string{};
    string.m_size = a.m_size + b.m_size;
    if (string.m_size > 0)
    {
        string.m_data = (char*)malloc(string.m_size + 1);
        if (a.m_size > 0)
            strcpy(string.m_data, a.m_data);
        if (b.m_size > 0)
            strcpy(string.m_data + a.m_size, b.m_data);
    }
    return string;
}

std::ostream& operator<<(std::ostream& stream, const String& string)
{
//    if (string.m_size > 0)
        stream << string.m_data;
    return stream;
}
