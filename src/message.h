#include <mutex>
#include <deque>
#include <condition_variable>

template <class T>
class MessageQueue
{
public:
    T receive();
    void send(T &&msg);
private:
    std::mutex _mutex;
    std::condition_variable _condition;
    std::deque<T> _queue;
};