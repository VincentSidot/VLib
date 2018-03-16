#include "VString.h"



VString::VString()
{
	m_len = 0;
	m_str = new char[1];
	*m_str = 0;
}

VString::VString(const char * str)
{
	m_len = strlen(str);
	if (m_len != 0)
	{
		m_str = new char[m_len+1];
	}
	memcpy(m_str, str, m_len);
	*(m_str + m_len) = 0;
}

VString::VString(const char * str, size_t len)
{
	if (m_len != 0)
	{
		m_str = new char[m_len+1];
	}
	memcpy(m_str, str, m_len);
	*(m_str + m_len) = 0;
}

VString::VString(VString const & othr)
{
	this->operator=(othr);
}

VString::VString(long num)
{
	VString tmp;
	while (num > 0)
	{
		tmp += (num % 10 + '0');
		num /= 10;
	}
	if (num < 0)
		tmp += '-';
	this->operator=(tmp.reverse());
}

VString::VString(int num)
{
	VString tmp;
	while (num > 0)
	{
		tmp += (num % 10 + '0');
		num /= 10;
	}
	if (num < 0)
		tmp += '-';
	this->operator=(tmp.reverse());

}

VString::VString(unsigned int unum)
{
	VString tmp;
	while (unum > 0)
	{
		tmp += (unum % 10 + '0');
		unum /= 10;
	}
	this->operator=(tmp.reverse());
}

VString::VString(unsigned long unum)
{
	VString tmp;
	while (unum > 0)
	{
		tmp += (unum % 10 + '0');
		unum /= 10;
	}
	this->operator=(tmp.reverse());
}

VString::VString(double num, size_t dec)
{
	VString tmp,tmp1,tmp2;
	if (num < 0)
		tmp += '-';
	while (num > 0)
	{
		tmp1 += (int(num) % 10 + '0');
		num /= 10;
	}
	tmp += tmp1.reverse();
	tmp += '.';
	num *= dec;
	while (num > 0)
	{
		tmp2 += char(int(num) % 10 + '0');
		num /= 10;
	}
	tmp += tmp2;
	this->operator=(tmp);
}

VString::VString(float num, size_t dec)
{
	VString tmp, tmp1, tmp2;
	if (num < 0)
		tmp += '-';
	while (num > 0)
	{
		tmp1 += (int(num) % 10 + '0');
		num /= 10;
	}
	tmp += tmp1.reverse();
	tmp += '.';
	num *= dec;
	while (num > 0)
	{
		tmp2 += char(int(num) % 10 + '0');
		num /= 10;
	}
	tmp += tmp2;
	this->operator=(tmp);
}

VString::~VString()
{
	if (m_str != nullptr)
	{
		delete[] m_str;
	}
	m_len = 0;
}

void VString::append(const char * str)
{
	size_t len = strlen(str);
	this->append(str, len);
}

void VString::append(const char * str, size_t len)
{
	char* tmp = m_str;
	m_str = new char[m_len + len+1];
	memcpy(m_str, tmp, m_len);
	memcpy(m_str + m_len, str, len);
	m_str[m_len + len] = 0;
	m_len += len;
	delete[] tmp;
}

void VString::append(VString const & str)
{
	this->append(str.getChar(), str.length());
}

void VString::erase()
{
	this->~VString();
	m_str = new char[1];
	*m_str = 0;
	m_len = 0;
}

void VString::erase(size_t begin, size_t len)
{
	char* tmp = m_str;
	m_str = new char[m_len - len + 1];
	memcpy(m_str, tmp, begin);
	memcpy(m_str + begin, tmp + begin + len, m_len - begin - len + 1);
	m_len -= len;
	delete[] tmp;
}

VString& VString::reverse()
{
	char* tmp;
	tmp = new char[m_len + 1];
	for (size_t i = 0; i < m_len; i++)
	{
		tmp[i] = m_str[m_len - 1 - i];
	}
	tmp[m_len] = 0;
	this->operator=(VString(tmp));
	return *this;
}

char * VString::getChar() const
{
	return m_str;
}

size_t VString::length() const
{
	return m_len;
}

bool VString::search_string(VString const & str) const
{
	for (size_t i = 0; i < this->m_len - str.length()+1; i++)
	{
		size_t j = 0;
		while (this->m_str[i+j] == str[j])
		{
			j++;
			if (j == str.length())
			{
					return true;
			}
		}
	}
	return false;
}

VString VString::extract(size_t begin, size_t len) const
{
	return this->operator()(begin,len);
}

VString& VString::toLower()
{
	for (size_t i = 0; i < this->m_len; i++)
	{
		if (m_str[i] >= 'A' && m_str[i] <= 'Z')
		{
			m_str[i] = m_str[i] - 'A' + 'a';
		}
	}
	return *this;
}

VString& VString::toUpper()
{
	for (size_t i = 0; i < this->m_len; i++)
	{
		if (m_str[i] >= 'a' && m_str[i] <= 'z')
		{
			m_str[i] = m_str[i] - 'a' + 'A';
		}
	}
	return *this;
}

char & VString::operator[](size_t index)
{
	if (index < m_len)
	{
		return *(m_str + index);
	}
}

char VString::operator[](size_t index) const
{
	if (index < m_len)
	{
		return *(m_str + index);
	}
}

VString VString::operator()(size_t begin, size_t len) const
{
	if (begin + len > m_len)
	{
		len = this->m_len - begin;
	}
	char *str;
	str = new char[len+1];
	memcpy(str, this->m_str + begin, len);
	str[len] = 0;
	return VString(str);
}

VString & VString::operator=(VString const & othr)
{
	this->~VString();
	m_len = othr.length();
	m_str = new char[m_len+1];
	memcpy(m_str, othr.getChar(), m_len+1);
	return *this;
}

VString & VString::operator+=(VString const & othr)
{
	this->append(othr);
	return *this;
}

VString & VString::operator+=(const char car)
{
	this->append(&car,1);
	return *this;
}

bool VString::operator==(VString const & othr) const
{
	if (m_len != othr.length())
	{
		return false;
	}
	for (size_t i = 0; i < m_len; i++)
	{
		if (m_str[i] != othr[i])
			return false;
	}
	return true;
}

bool VString::operator!=(VString const & othr) const
{
	return !this->operator==(othr);
}


VString operator+(VString str1, VString const & str2)
{
	str1.append(str2);
	return str1;
}

bool operator>(VString s1, VString s2)
{
	s1.toLower();
	s2.toLower();
	size_t len = min(s1.length(), s2.length());
	for (size_t i = 0; i < len; i++)
	{
		if (s1[i] > s2[i])
		{
			return true;
		}
		else if (s1[i] < s2[i])
		{
			return false;
		}
	}
}

bool operator<(VString s1, VString s2)
{
	return s2>s1;
}

VString toLower(VString str)
{
	return str.toLower();
}

VString toUpper(VString str)
{
	return str.toUpper();
}

VString reverse(VString str)
{
	return str.reverse();
}

VString extract(VString const & str, size_t begin, size_t len)
{
	return VString();
}
