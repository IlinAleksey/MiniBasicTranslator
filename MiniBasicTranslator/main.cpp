#include "Hashtable.h"
#include "HashtableDel.h"
#include "Lexer.h"
#include "Synt.h"
#include <string>
int main()
{
	/*Lexer lxr;
	lxr.start("data.txt");*/
	Synt snt;
	snt.start("data.txt");
	snt.start_syntax();
	return 0;
}