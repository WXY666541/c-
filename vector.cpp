#include<iostream>

template<typename T>
class Link
{
public:
	Link()
	{
		T* parr = new T[2];
		cursize = 0;
		totalsize = 2;
	}
	void resize()
	{
		T* pdata = new T[totalsize * 2]();
		memcpy(pdata, parr, sizeof(int) * totalsize);
		delete[] parr;
		parr = pdata;
		totalsize *= 2;
	}
	void InsertPos(int pos, T val)
	{
		if (full())
		{
			resize();
		}
		if (pos < 0 || pos >cursize)
		{
			throw std::exception("insert position is error!");
		}
		for (int i = cursize; i > pos; i--)
		{
			parr[i] = parr[i - 1];
		}
		parr[pos] = val;
		cursize++;
	}
	void InsertTail(T val)
	{
		InsertPos(cursize, val);
	}
	bool empty()
	{
		return cursize == 0;
	}
	void deletepos(int pos)
	{
		if (empty())
		{
			throw std::exception("Link is empty");
		}
		if (pos <= 0 || pos >= cursize)
		{
			throw std::exception("delete position is error!");
		}
		for (int i = pos; i < cursize - 1; i++)
		{
			parr[i] = parr[i+1];
		}
		cursize--;
	}
	void deleteTail()
	{
		deletepos(cursize - 1);
	}
	void show()
	{
		for (int i = 0; i < cursize; i++)
		{
			std::cout << parr[i] << " ";
		}
		std::cout << std::endl;
	}
private:
	bool full()
	{
		return cursize = totalsize;
	}
	T* parr;
	int cursize;
	int totalsize;
};

int main()
{
	Link<int> link;
	for (int i = 0; i < 10; i++)
	{
		link.InsertTail(i + 1);
	}
	link.show();
	link.InsertPos(4, 50);
	link.show();
	link.deletepos(7);
	link.show();
	link.deleteTail();
	link.show();
	return 0;
}