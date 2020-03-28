#include<iostream>
using namespace std;

template<typename T>
class Queue
{
public:
	Queue()
	{
		_front = _rear = new QueueTtem();
	}
	~Queue()
	{
		QueueTtem* cur = _front;
		while (cur != nullptr)
		{
			_front = _front->_next;
			delete cur;
			cur = _front;
		}
	}
	void push(const T& val)//��Ӳ���
	{
		QueueTtem *item = new QueueTtem(val);
		_rear->_next = item;
		_rear = item;
	}
	void pop()
	{
		if (empty())
			return;
		QueueTtem* first = _front->_next;
		_front->_next = first->_next;
		if (_front->_next == nullptr)//ֻ��һ������ʱ��
		{
			_rear = _front;
		}
		delete first;
	}
	T front() const
	{
		return  _front->_next->data;
	}
	bool empty()const { return _front == _rear; }
private:
	struct QueueTtem//����һ��QueueTtem�Ķ����(10000��QueueTtem�ڵ�)
	{
		QueueTtem(T data = T()):_data(data),_next(nullptr){ }
		//��QueueTtem�ṩ�Զ�����ڴ����,�������������Ǿ�̬�ķ�����Ϊʹ�õ�ʱ�򶼻�û�ж���
		void* operator new(size_t size)
		{
			if (_itemPool == nullptr)
			{
				_itemPool = (QueueTtem*)new char[POOL_ITEM_SIZE * sizeof(QueueTtem)];//���ֽڿ���
				QueueTtem* p = _itemPool;
				for (; p < _itemPool + POOL_ITEM_SIZE-1; ++p)
				{
					p->_next = p + 1;
				}
				p->_next = nullptr;//���һ�����ĵ�ַ��
			}
			//��ʾ���������н��ģ����ҵ���ڽ�㼴��
			QueueTtem* p = _itemPool;
			_itemPool = _itemPool->_next;
		}
		void* operator delete(size_t size)
		{
			QueueTtem* p = (QueueTtem*)ptr;
			//�黹���̾��ǰ����ӵ���һ�������漴��
			p->_next = _itemPool;
		}
		T _data;
		QueueTtem* _next;
		static QueueTtem* _itemPool;
		static const int POOL_ITEM_SIZE = 1000000;

	};

	QueueTtem* _front;//ָ��ͷ���
	QueueTtem* _rear;//ָ���β

};
//���Ǳ���������Ϊ����һ����ʱ�򣬻�û�г�ʼ������֪����һ��ʲô��*�����Ǵ����ָ�뻹�ǳ˷��������
//�����������һ��typename�����򣬸��߱���������Ƕ����������Ǹ�����
template<typename T>
typename Queue<T>::QueueTtem* Queue<T>::QueueTtem::_itemPool = nullptr;
int main()
{
	Queue<int> que;
	//��ʱ���ڴ�������malloc��free���Գ�����������Ӱ��
	for (int i = 0; i < 1000000; ++i)
	{
		que.push(i);// QueueTtem(i)
		que.pop();//QueueTtem
	}
	cout << que.empty() << endl;
	return 0;
}