class FooBar
{
private:
    int n;
    mutex cv_m;
    condition_variable cv;
    bool flag;

public:
    FooBar(int n)
    {
        this->n = n;
        flag = true;
    }

    void foo(function<void()> printFoo)
    {

        for (int i = 0; i < n; i++)
        {
            unique_lock<mutex> lk(cv_m);
            cv.wait(lk, [=] { return flag; });
            // printFoo() outputs "foo". Do not change or remove this line.
            printFoo();
            flag = false;
            cv.notify_one();
        }
    }

    void
    bar(function<void()> printBar)
    {

        for (int i = 0; i < n; i++)
        {
            unique_lock<mutex> lk(cv_m);
            cv.wait(lk, [=] { return !flag; });
            // printBar() outputs "bar". Do not change or remove this line.
            printBar();
            flag = true;
            cv.notify_one();
        }
    }
};