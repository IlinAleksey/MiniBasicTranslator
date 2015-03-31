#include "Hashtable.h"
int main()
{
	Hashtable hash;
	hash.add(10, 10);
	hash.add(20, 11);
	hash.add(30, 12);
	hash.add(110, 110);
	hash.add(210, 210);
	hash.add(310, 310);
	hash.add(410, 410);
	hash.add(510, 510);
	hash.add(109, 100);
	hash[100] = 60;
	hash[200] = 60;
	std::cout << hash << std::endl;
	return 0;
}