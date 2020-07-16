#include<iostream>

class Queue
{
public:
	//���캯��
	Queue(int size = 20)
	{
		_pQue = new int[size];
		_front = _rear = 0;
		_size = size;
	}

	//�������캯��
	Queue(const Queue& src)
	{
		_size = src._size;
		_front = src._front;
		_rear = src._rear;
		_pQue = new int[_size];
		for (int i = _front; i != _rear; i = (i + 1) % _size)
		{
			_pQue[i] = src._pQue[i];
		}

	}

	//��ֵ��������غ���
	Queue& operator=(const Queue& src)
	{
		if (this == &src)
			return *this;
		delete[]_pQue;

		_size = src._size;
		_front = src._front;
		_rear = src._rear;
		_pQue = new int[_size];
		for (int i = _front; i != _rear; i = (i + 1) % _size)
		{
			_pQue[i] = src._pQue[i];
		}
		return *this;
	}

	//��������
	~Queue()
	{
		delete[] _pQue;
		_pQue = nullptr;
	}

	//��Ӳ���
	void push(int val)
	{
		if (full())
			resize();
		_pQue[_rear] = val;
		_rear = (_rear + 1) % _size;
	}

	//���Ӳ���
	void pop()
	{
		if (empty())
			return;
		_front = (_front + 1) % _size;
	}

	//ȡ��ͷԪ�ز���
	int front()
	{
		return _pQue[_front];
	}

	//��������
	bool full() { return (_rear + 1) % _size == _front; }
	//�пղ���
	bool empty() { return _front == _rear; }

private:
	int* _pQue;//������е�����ռ䣬�����ָ�������
	int _front;//ָʾ��ͷ��λ��
	int _rear;//ָʾ��β��λ��
	int _size;//�������ݵ��ܴ�С

	//�������ݲ���
	void resize()
	{
		int* ptmp = new int[2 * _size];
		int index = 0;
		for (int i = _front; i != _rear; i = (i + 1) % _size)
		{
			ptmp[index++] = _pQue[i];
		}
		delete[]_pQue;
		_pQue = ptmp;
		_front = 0;
		_rear = index;
		_size *= 2;
	}
};

int main()
{
	Queue queue;
	for (int i = 0; i < 20; ++i)
	{
		queue.push(rand() % 100);
	}
	while (!queue.empty())
	{
		std::cout << queue.front() << " ";
		queue.pop();
	}
	std::cout << std::endl;
	return 0;
}