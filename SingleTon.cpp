#include<iostream>
#include<pthread.h>

/*
   ����ģʽģ��
*/
class SingleTon
{
public:
    static SingleTon* getInstance()
    {
        if (psing == NULL)
        {
            psing = new SingleTon();
        }
        return psing;
    }
private:
    SingleTon()
    {
    }
    SingleTon(const SingleTon&);
    static SingleTon* psing;
};
SingleTon* SingleTon::psing = NULL;
int main()
{
    SingleTon* pr1 = SingleTon::getInstance();
    SingleTon* pr2 = SingleTon::getInstance();
    SingleTon* pr3 = SingleTon::getInstance();
    return 0;
}

/*
   ˫���������µĵ���ģʽ
*/
pthread_mutex_t mutex;
class SingleTon
{
public:
    static SingleTon* getInstance()
    {
        if (pre == NULL)
        {
            pthread_mutex_lock(&mutex);
            pre = new SingleTon();
            pthread_mutex_unlock(&mutex);
        }
        return psing;
    }
private:
    SingleTon()
    {
    }
    SingleTon(const SingleTon&);
    static SingleTon* psing;
};
SingleTon* SingleTon::psing = NULL;


/*
   ���߳̿���֮ǰ���ɶ���ĵ���ģʽ
*/
class SingleTon
{
public:
    static SingleTon* getInstance()
    {
        return psing;
    }
private:
    SingleTon()
    {
    }
    SingleTon(const SingleTon&);
    static SingleTon* psing;
};
SingleTon* SingleTon::psing = new SingleTon();
