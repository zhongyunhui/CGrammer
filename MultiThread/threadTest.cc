#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include <atomic>
using namespace std;

int main() {
    volatile int i{0};
    mutex mtx;
    mutex mtx2;
    condition_variable cv;
    condition_variable cv2;
    auto lab1 = [&] () {
        while (true) {
            unique_lock<mutex> lck(mtx);
            cv.wait(lck);
            i++;
            cout<<"threadid: "<< this_thread::get_id() <<" i: " << i <<endl;
            this_thread::sleep_for(std::chrono::seconds(1));
            cv2.notify_all();
        }
    };
    auto lab2 = [&] () {
        while (true) {
            unique_lock<mutex> lck(mtx2);
            cv2.wait(lck);
            i++;
            cout<<"threadid: "<< this_thread::get_id() <<" i: " << i <<endl;
            this_thread::sleep_for(std::chrono::seconds(1));
            cv.notify_all();
        }
    };
    
    pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

    thread* t1 = new thread(lab1);
    thread* t2 = new thread(lab2);
    this_thread::sleep_for(std::chrono::seconds(1));
    cv.notify_all();
    cout<<"main thread"<<endl;   
    t1->join();
    t2->join();
    return 0;
}

