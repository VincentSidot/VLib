#pragma once
#include <cstring>

#define min(a,b) (a>b)?b:a
#define max(a,b) (a>b)?a:b

namespace VLib
{
	class VString
	{
	public:
		VString();
		VString(const char* str);
		VString(const char* str, size_t len);
		VString(VString const &othr);
		VString(long num);
		VString(int num);
		VString(unsigned int unum);
		VString(unsigned long unum);
		VString(double num, size_t dec = 3);
		VString(float num, size_t dec = 3);

		~VString();

		void append(const char* str);
		void append(const char* str, size_t len);
		void append(VString const &str);


		void erase();
		void erase(size_t begin, size_t len);

		VString& reverse();

		char* getChar() const;

		size_t length() const;

		bool search_string(VString const &str) const;

		VString extract(size_t begin, size_t len) const;

		VString& toLower();
		VString& toUpper();

		VString operator()(size_t begin, size_t len) const;
		char& operator[](size_t index);
		char operator[](size_t index) const;

		VString& operator=(VString const &othr);
		VString& operator+=(VString const &othr);
		VString& operator+=(const char car);

		bool operator==(VString const &othr) const;
		bool operator!=(VString const &othr) const;

	protected:
		char* m_str = nullptr;
		size_t m_len = 0;

	};


	VString operator+(VString str1, VString const &str2);

	bool operator>(VString s1, VString s2);
	bool operator<(VString s1, VString s2);

	VString toLower(VString str);
	VString toUpper(VString str);
	VString reverse(VString str);
	VString extract(VString const &str, size_t begin, size_t len);
}
