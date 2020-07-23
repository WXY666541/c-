#include<iostream>
#include<vector>

//…˝–Ú≈≈–Ú
template<typename T>
class Greater
{
public:
	bool operator()(const T& first, const T& second)
	{
		return first > second;
	}
};

//Ωµ–Ú≈≈–Ú
template<typename T>
class Lesser
{
public:
	bool operator()(const T& first, const T& second)
	{
		return first < second;
	}
};
template<typename Iterator,
	typename Fn2>
void Sort(Iterator _First, Iterator _Last, Fn2 fn)
{
	Iterator i = _First;
	Iterator j = _First;
	int k = 0;
	for (i; i < _Last - 1; i++,k++)
	{
		for (j = _First; j < _Last - k - 1; j++)
		{
			if (fn(*j ,*(j + 1)))
			{
				typename Iterator::value_type tmp = *j;
				*j = *(j + 1);
				*(j + 1) = tmp;
			}
		}
	}
}
template<typename Container>
void show(Container& con)
{
	typename Container::iterator it = con.begin();
	while (it != con.end())
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
}
int main()
{
	int arr[] = { 12,23,34,22,444,222 };
	int len = sizeof(arr) / sizeof(arr[0]);
	std::vector<int> vec(arr, arr + len);
	show(vec);
	Sort(vec.begin(), vec.end(), Greater<int>());
	show(vec);
	Sort(vec.begin(), vec.end(), Lesser<int>());
	show(vec);
	return 0;
}
