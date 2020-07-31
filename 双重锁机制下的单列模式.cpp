#include<iostream> 
class SingleTon
{
    public:
    static SingleTon* getInstance()
    {
        if(pre == NULL)
        {
            lock();
            if(pre == NULL)
            {
            	pre = new SingleTon();
            }
            unlock();
        }
        return psing;
    }
    private:
        SingleTon()//私有构造
        {
        }
        SingleTon(const SingleTon&);//私有拷贝构造
        static SingleTon* psing;
};
SingleTon* SingleTon::psing = NULL;

