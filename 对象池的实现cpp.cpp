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
	void push(const T& val)//入队操作
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
		if (_front->_next == nullptr)//只有一个结点的时候
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
	struct QueueTtem//产生一个QueueTtem的对象池(10000个QueueTtem节点)
	{
		QueueTtem(T data = T()):_data(data),_next(nullptr){ }
		//对QueueTtem提供自定义的内存管理,这两个函数都是静态的方法因为使用的时候都还没有对象
		void* operator new(size_t size)
		{
			if (_itemPool == nullptr)
			{
				_itemPool = (QueueTtem*)new char[POOL_ITEM_SIZE * sizeof(QueueTtem)];//按字节开辟
				QueueTtem* p = _itemPool;
				for (; p < _itemPool + POOL_ITEM_SIZE-1; ++p)
				{
					p->_next = p + 1;
				}
				p->_next = nullptr;//最后一个结点的地址域
			}
			//表示池里面是有结点的，则找到入口结点即可
			QueueTtem* p = _itemPool;
			_itemPool = _itemPool->_next;
		}
		void* operator delete(size_t size)
		{
			QueueTtem* p = (QueueTtem*)ptr;
			//归还过程就是把它加到第一个结点后面即可
			p->_next = _itemPool;
		}
		T _data;
		QueueTtem* _next;
		static QueueTtem* _itemPool;
		static const int POOL_ITEM_SIZE = 1000000;

	};

	QueueTtem* _front;//指向头结点
	QueueTtem* _rear;//指向队尾

};
//但是编译会出错，以为到这一步的时候，还没有初始化，不知道是一个什么，*到底是处理成指针还是乘法还不清楚
//解决方法：加一个typename作用域，告诉编译器后面嵌套类的名字是个类型
template<typename T>
typename Queue<T>::QueueTtem* Queue<T>::QueueTtem::_itemPool = nullptr;
int main()
{
	Queue<int> que;
	//短时间内大量调用malloc和free，对程序性能有所影响
	for (int i = 0; i < 1000000; ++i)
	{
		que.push(i);// QueueTtem(i)
		que.pop();//QueueTtem
	}
	cout << que.empty() << endl;
	return 0;
}