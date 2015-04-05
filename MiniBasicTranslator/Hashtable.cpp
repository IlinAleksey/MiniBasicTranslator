#include "Hashtable.h"
#include <iomanip>

Hashtable::Hashtable()
{
	m_size = s_size;
	m_capacity = s_capacity;
	m_free_row = m_size + 1;
	m_table = new row[m_capacity];
	for (size_t i = 0; i < m_capacity; i++)
	{
		m_table[i] = row{ -1, -1, -1 };
	}
	m_table[0].alternative = 0;
}

Hashtable::Hashtable(int size, int capacity)
{
	m_size = size;
	m_capacity = capacity;
	m_free_row = m_size + 1;
	m_table = new row[m_capacity];
	for (size_t i = 0; i < m_capacity; i++)
	{
		m_table[i] = row{ -1, -1, -1 };
	}
	m_table[0].alternative = 0;
}


Hashtable::~Hashtable()
{
	delete[] m_table;
}

int Hashtable::hash_function(int key)const
{ 
	return key % (m_size) + 1;
}
bool Hashtable::is_row_null(int row) const
{
	return	(m_table[row].label == -1) && (m_table[row].value == -1) && (m_table[row].alternative == -1);
}
int Hashtable::next_free()
{
	int to_ret = m_free_row;
	m_free_row++;
	return to_ret;
}
int Hashtable::add(int key, int value)
{
	int pos = hash_function(key);
	if (is_row_null(pos))
	{
		m_table[pos].label = key;
		m_table[pos].value = value;
		return pos;
	}
	else
	{
		int cur = pos;
		while (m_table[cur].alternative != -1 && m_table[cur].label != key)
		{
			cur = m_table[cur].alternative;
		}
		if (m_table[cur].label != key)
		{
			int free = next_free();
			m_table[cur].alternative = free;
			m_table[free].label = key;
			m_table[free].value = value;
			return free;
		}
		else
		{
			return cur;
		}
	}

}

int& Hashtable::operator[](int key)
{
	int pos = hash_function(key);
	if (is_row_null(pos))
	{
		m_table[pos].label = key;
		return m_table[pos].value;
	}
	else
	{
		int cur = pos;
		while (m_table[cur].alternative != -1 && m_table[cur].label != key)
		{
			cur = m_table[cur].alternative;
		}
		if (m_table[cur].label != key)
		{
			int free = next_free();
			m_table[cur].alternative = free;
			m_table[free].label = key;
			return m_table[free].value;
		}
		else
		{
			return m_table[cur].value;
		}
	}
}

std::ostream& operator<<(std::ostream& out, const Hashtable& hashtable)
{
	// _____________________________
	// | 1234 | 1234 | 1234 | 1234 |
	for (int i = 0; i < 25 ; i++)
	{
		out << '_';
	}
	out << std::endl;
	for (int i = 0; i < hashtable.m_capacity; i++)
	{
		if (!hashtable.is_row_null(i))
		{
			out << '|';
			out << std::setw(5) << i;
			out << '|';
			out << std::setw(5) << hashtable.m_table[i].label;
			out << '|';
			out << std::setw(5) << hashtable.m_table[i].value;
			out << '|';
			out << std::setw(5) << hashtable.m_table[i].alternative;
			out << '|';
			out << std::endl;
		}
	}
	return out;
}