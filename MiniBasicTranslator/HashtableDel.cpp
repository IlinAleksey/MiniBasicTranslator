#include "HashtableDel.h"


HashtableDel::HashtableDel() : Hashtable()
{
}


HashtableDel::~HashtableDel()
{
}

void HashtableDel::remove(int key)
{
	int pos = hash_function(key);
	int prev = -1;
	while (pos != -1 && m_table[pos].label != key)
	{
		prev = pos;
		pos = m_table[pos].alternative;
	}
	m_table[prev].alternative = m_table[pos].alternative;
	
	int top_of_stack = m_table[0].alternative;
	m_table[pos].alternative = top_of_stack;
	m_table[0].alternative = pos;
}

int HashtableDel::next_free()
{
	int top_of_stack = m_table[0].alternative;
	if (top_of_stack == 0)
	{
		return Hashtable::next_free();
	}
	else
	{
		int to_ret = top_of_stack;
		m_table[0].alternative = m_table[top_of_stack].alternative;
		return to_ret;
	}
}
