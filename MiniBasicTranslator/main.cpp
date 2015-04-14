#include "Hashtable.h"
#include "HashtableDel.h"
#include "Lexer.h"
#include <string>
int main()
{
	/*Lexer lxr;
	lxr.start("data.txt");
	std::cout << lxr;*/

	HashtableDel hdel = HashtableDel();
	hdel[10] = 1;
	hdel[110] = 2;
	hdel[210] = 3;
	std::cout << hdel;
	hdel.remove(110);
	std::cout << hdel;
	hdel[410] = 4;
	std::cout << hdel;
	return 0;
}