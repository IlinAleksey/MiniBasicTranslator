#pragma once
#include <iostream>

class Hashtable
{
	struct row
	{
		int label;
		int value;
		int alternative;
	};
	static const int s_size = 100;
	static const int s_capacity = 300;
	static const int null = -1;
	int m_size;
	int m_capacity;
	row* m_table;
	int m_free_row;
	int next_free();
	int hash_function(int key) const;
	bool is_row_null(int row) const;
public:
	void add(int key, int value);
	int find(int key);
	int& operator[](int key);
	friend std::ostream& operator<<(std::ostream& out, const Hashtable& hashtable);
	Hashtable();
	Hashtable(int size, int capacity);
	~Hashtable();
};

