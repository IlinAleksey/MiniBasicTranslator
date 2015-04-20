#include "Hashtable.h"
#include "HashtableDel.h"
#include "Lexer.h"
#include <string>
int main()
{
	Lexer lxr;
	lxr.start("data.txt");
	std::cout << lxr;

	return 0;
}