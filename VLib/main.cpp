#include <cstdio>
#include <cstdlib>
#include "VLib.h"

using namespace VLib;

int main(int argc, char** argv)
{
	int a[] = { 1,2,3,4 };
	VVector<int> v1;
	v1 = VVector<int>(a,4);

	for (size_t i = 0; i < v1.size(); i++)
	{
		printf("%d\n", v1[i]);
	}

	getchar();
	return 0;
}