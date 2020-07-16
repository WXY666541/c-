#include<iostream>
#include<pthread.h>

/*
   单例模式模型
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
   双重锁机制下的单例模式
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
   在线程开启之前生成对象的单例模式
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
