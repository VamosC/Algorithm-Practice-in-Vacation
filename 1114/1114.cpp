class Foo
{
public:
    Foo()
    {
        mutex_2.lock();
        mutex_3.lock();
    }

    void first(function<void()> printFirst)
    {

        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        mutex_2.unlock();
    }

    void second(function<void()> printSecond)
    {
        lock_guard<mutex> lock(mutex_2);
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        mutex_3.unlock();
    }

    void third(function<void()> printThird)
    {
        lock_guard<mutex> lock(mutex_3);
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }

private:
    mutex mutex_2, mutex_3;
};