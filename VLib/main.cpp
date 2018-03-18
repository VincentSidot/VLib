#include <cstdio>
#include <cstdlib>
#include "VLib.h"

using namespace VLib;

int main(int argc, char** argv)
{
	VVector<VString> v1;
	v1 = VVector<VString>({ "lol","lal","lul" }).sort();
	for (size_t i = 0; i < v1.size(); i++)
	{
		printf("%s\n", v1[i].getChar());
	}

	getchar();
	return 0;
}