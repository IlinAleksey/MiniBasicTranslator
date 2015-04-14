#pragma once
#include "Hashtable.h"
class HashtableDel :
	public Hashtable
{
	int next_free();

public:
	void remove(int key);
	HashtableDel();
	~HashtableDel();
};

