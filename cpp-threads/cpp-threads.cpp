#include <thread>
#include <iostream>

static bool threadDone = false;
void Thread1func() {
    while (!threadDone) {
        static auto threadId = std::this_thread::get_id();
        std::cout << "Thread 1 running! ThreadID = " << threadId << "\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
}

int main()
{
    static auto mainThreadId = std::this_thread::get_id();
    std::cout << "MainThread running! ThreadID = " << mainThreadId << "\n";
    std::thread thread1(Thread1func);
	
    std::cin.get();
    threadDone = true;
	
    thread1.join();
    std::cout << "MainThread exiting! ThreadID = " << mainThreadId << "\n";
    return 0;
}
