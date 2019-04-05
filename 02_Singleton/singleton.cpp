// single thread but no thread-safty
// method 01:
class singleton
{
protected:
    singleton(){}
private:
    static singleton* p;
public:
    static singleton* instance();
};
singleton* singleton::p = nullptr;
singleton* singleton::instance()
{
    if (p == nullptr)
        p = new singleton();
    return p;
}

// added mutex
//// method 02
class singleton
{
protected:
    singleton()
    {
        pthread_mutex_init(&mutex);
    }
private:
    static singleton* p;
public:
    static pthread_mutex_t mutex;
    static singleton* initance();
};

pthread_mutex_t singleton::mutex;
singleton* singleton::p = nullptr;
singleton* singleton::initance()
{
    if (p == nullptr)
    {
        pthread_mutex_lock(&mutex);
        if (p == nullptr)
            p = new singleton();
        pthread_mutex_unlock(&mutex);
    }
    return p;
}

// but above implementation is not better way.
// the below is one of recommanded ways:
// leverage static 
class singleton
{
protected:
    singleton()
    {
        pthread_mutex_init(&mutex);
    }
public:
    static pthread_mutex_t mutex;
    static singleton* initance();
    int a;
};

pthread_mutex_t singleton::mutex;
singleton* singleton::initance()
{
    pthread_mutex_lock(&mutex);
    static singleton obj;
    pthread_mutex_unlock(&mutex);
    return &obj;
}

// below is also recommanded way which is 
// thread-safty and  no mutex

class singleton
{
protected:
    singleton()
    {}
private:
    static singleton* p;
public:
    static singleton* initance();
};
singleton* singleton::p = new singleton;
singleton* singleton::initance()
{
    return p;
}
