#include<iostream>
using namespace std;
//ʵ��String��
#if 0
class String
{
public:
	String(const char* str = nullptr)//��ͨ�Ĺ��캯��
	{
		if (str != nullptr)
		{
			m_data = new char[strlen(str) + 1];//����Ӧ�����ȿ���һ���ռ䣬+1����Ϊstrlenû��\0
			strcpy(this->m_data, str);//���ⲿд����ַ���������m_data�����ǲ���֪�����ָ���Ƿ�ָ��һ���Ϸ��Ŀռ�
		}
		else//�����������ָ��Ϊ�յĻ���Ӧ�ð�m_data��Ϊ�գ������Ļ������ʹ���������з���ҲҪ�ж�Ϊ�յ���������������´���
		{
			m_data = new char[1];//��дnew char��ԭ�������������ؽ���
			*m_data = '\0';
		}
	
	}
	String(const String& other)//�������캯��
	{
		//m_data = other.m_data;Ĭ�ϵķ�ʽ�������������ָ��ָ��ͬһ�鹹��ʱ����Ķ��ڴ棬����������ʱ��ʹ���������
		m_data = new char[strlen(other.m_data) + 1];
		strcpy(m_data, other.m_data);//������Ĵ�С�����Լ���ָ������ָ������һ���ڴ棬Ȼ��������ݵĿ���
	}
	~String(void)//��������
	{
		delete[] m_data;
		m_data = nullptr;//��ֹҰָ��ĳ���
	}
	//���������൱�ڷ��ص�ַΪ��֧��������ֵ���������ֵ�Ļ��������ʱ����
	String& operator = (const String& other)//��ֵ���غ���(�������Ѿ����ڵ��ַ�������ֵ��
	{
		if (this == &other)//��ֹ�Ը�ֵ
		{
			return *this;
		}
		delete[]m_data;//�ѵ�ǰ������ռ���ⲿ��Դ�ͷŵ�
		//�ٵ��ÿ�������,�����¸��ݴ���Ķ�����ַ����Ĵ�С���ٿռ俽���ַ���
		m_data = new char[strlen(other.m_data) + 1];
		strcpy(m_data, other.m_data);
		return *this;
	}
private:
	char* m_data;//���ڱ����ַ���

};
int main()
{
	//���ô�const char*�����Ĺ��캯��
	String str1;//Ĭ�ϵĹ���
	String str2("hello");
	String str3="world";

	//�����ÿ������죬�ǳ�ʼ�����Ǹ�ֵ����ߵĶ����Ѿ����ڣ���������ߵĶ��󲻴��ڣ����ڿ���������
	String str4 = str3;
	String str5(str3);

	//���ø�ֵ���غ���
	/*
	��ֵ���غ����ķ���ֵ������void����Ϊ��ʵ��������ֵ��ʱ�����磺str3 = str1 = str2;�൱��
	str1 = str2
	str1.operator =(str2)==>void
	str3 = void //�����
	*/
	str1 = str2;
	return 0;
}
#endif

/*
����Ŀ�����Ҫʹ��memcpy realloc��Ϊ���������ڴ��ֱ�ӿ��������Ƕ�������漰���ⲿ���ڴ�
*/
//ʵ��ѭ������  
class Queue
{
public:
	Queue(int size = 20)
	{
		_pQue = new int[size];
		_front = _rear = 0;
		_size = size;
	}
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
	
	~Queue()
	{
		delete[] _pQue;
		_pQue = nullptr;
	}
	void push(int val)
	{
		if (full())
			resize();
		_pQue[_rear] = val;
		_rear = (_rear + 1) % _size;
	}
	void pop()
	{
		if (empty())
			return;
		_front = (_front + 1) % _size;
	}
	int front()
	{
		return _pQue[_front];
	}
	bool full() { return (_rear + 1) % _size == _front; }
	bool empty() { return _front == _rear; }
private:
	int* _pQue;//������е�����ռ䣬�����ָ�������
	int _front;//ָʾ��ͷ��λ��
	int _rear;//ָʾ��β��λ��
	int _size;//�������ݵ��ܴ�С

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
	for (int i=0; i < 20; ++i)
	{
		queue.push(rand() % 100);
	}
	while (!queue.empty())
	{
		cout << queue.front() << " ";
		queue.pop();
	}
	cout << endl;

	//Queue queue1 = queue;ǳ���������⣬�������ڴ�
	return 0;
}