#include "Hashtable.h"
#include "Lexer.h"
#include <string>
int main()
{
	Lexer lxr;
	lxr.start("data.txt");
	std::cout << lxr.lexeme_list_str();
	return 0;
}