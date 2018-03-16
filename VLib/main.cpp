#include <cstdio>
#include <cstdlib>
#include "VString.h"

int main(int argc, char** argv)
{
	VString v1("Phrase"), v2;
	v2 = v1;
	v2[0] = 'p';
	v2.append(VString(" de de test"));
	v2.erase(7, 3);
	v1.reverse();
	v1.toUpper();
	printf("%s\n%s\n%d", v1.getChar(), v2.getChar(),(v2>v1));
	getchar();
	return 0;
}