#include "message.h"


template <typename T>
T MessageQueue<T>::receive()
{
    // FP.5a : The method receive should use std::unique_lock<std::mutex> and _condition.wait() 
    // to wait for and receive new messages and pull them from the queue using move semantics. 
    // The received object should then be returned by the receive function. 

    // perform queue modification under the lock
    std::unique_lock<std::mutex> uLock(_mutex);  // lock_guard cant be used here since lock needs to be temporarily released during wait

    // !_queue.empty()  gaurds againist spurious wakeups or random wakeups
    _condition.wait(uLock, [this] { return !_queue.empty(); }); // pass unique lock to condition variable

    // remove last vector element from queue
    T msg = std::move(_queue.back());
    _queue.pop_back();
    return msg; // will not be copied due to return value optimization (RVO) in C++
}

template <typename T>
void MessageQueue<T>::send(T &&msg)
{
    // FP.4a : The method send should use the mechanisms std::lock_guard<std::mutex> 
    // as well as _condition.notify_one() to add a new message to the queue and afterwards send a notification.

        // perform vector modification under the lock
        std::lock_guard<std::mutex> uLock(_mutex);  // lock is released once ulock gets out of scope

        // add vector to queue
        // std::cout << "   Message " << msg << " has been sent to the queue" << std::endl;
        _queue.clear();
        _queue.emplace_back(std::move(msg));
        _condition.notify_one(); // notify client 
}
