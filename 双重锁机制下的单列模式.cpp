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
        SingleTon()//˽�й���
        {
        }
        SingleTon(const SingleTon&);//˽�п�������
        static SingleTon* psing;
};
SingleTon* SingleTon::psing = NULL;

