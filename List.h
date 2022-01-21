#pragma once
#include "windows.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;


template<class T>
class list
{
	T** data;
	int _length;
	string filename;

public:
	list(string filename)
	{
		this->data = NULL;
		this->_length = 0;
		this->filename = filename;
	}
	list(const list<T>& e)
	{
		this->filename = e.filename;
		if (e.data == NULL)
		{
			this->data = NULL;
			this->_length = 0;
		}
		else
		{
			this->data = new T * [e._length];
			for (int i = 0; i < e._length; i++)
			{
				*(data + i) = new T(**(e.data + i));
			}
			this->_length = e._length;
		}

	}
	~list()
	{
		this->clear();
	}

	T* operator [](int i)
	{
		return *(this->data + i);
	}

	void add(T* e)
	{
		if (this->data == NULL)
		{
			this->data = new T * [1];
			*(this->data) = e;
			this->_length++;
			return;
		}

		T** tmp = new T * [this->_length + 1];

		for (int i = 0; i < this->_length; i++)
			tmp[i] = this->data[i];

		tmp[this->_length] = e;

		this->_length++;

		delete[] this->data;
		this->data = tmp;
	}
	void del(int n)
	{
		if (this->data == NULL)
			return;
		if (n<0 || n>this->_length - 1)
			return;

		if (this->_length == 1)
		{
			delete* (this->data);
			delete[] this->data;
			this->data = NULL;
		}
		else
		{
			T** tmp = new T * [this->_length - 1];

			for (int i = 0, j = 0; i < this->_length; i++)
			{
				if (i != n)
				{
					tmp[j] = this->data[i];
					j++;
				}
			}
			delete this->data[n];
			delete[] this->data;
			this->data = tmp;
		}
		this->_length--;

	}
	void clear()
	{
		if (this->data == NULL)
			return;

		for (int i = 0; i < this->_length; i++)
			delete* (this->data + i);

		delete[] this->data;
		this->data = nullptr;
		this->_length = 0;
	}
	void swap(int i, int j)
	{
		if (i > this->_length - 1 || j > this->_length - 1)
			return;

		T* tmp = *(this->data + i);
		*(this->data + i) = *(this->data + j);
		*(this->data + j) = tmp;

	}

	int length()
	{
		return this->_length;
	}
	int lengthFiltered()
	{
		int j = 0;
		for (int i = 0; i < this->_length; i++)
		{
			if ((*this)[i].isFiltered())
				j++;
		}
		return this->_length - j;
	}

	void save()
	{
		if (this->data == NULL)
			return;
		std::ofstream fs(filename, std::ios::out | std::ios::binary | std::ios::trunc);
		for (int i = 0; i < this->_length; i++)
		{		
			fs.write((char*)this->data[i], sizeof T);
		}
		fs.close();
	}
	void load()
	{
		this->clear();
		ifstream loadfile(filename, ios_base::binary);
		if (loadfile.good())
		{
			while (true)
			{
				auto item = new T();

				loadfile.read((char*)item, sizeof T);
				if (loadfile.eof())
				{
					break;
				}
				this->add(item);
			}
		}
		loadfile.close();
	}
};