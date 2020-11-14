#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "iostream"
#include "nod/nod.hpp"
#include <thread>
#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/function.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/signals2.hpp>
#include <boost/thread.hpp>
#include <boost/typeof/typeof.hpp>

class B{
private:
    std::string name = "B";
public:
    void myloginfo(){
        std::cout<<"测试绑定类的成员方法"<< name <<std::endl;
    }
};
void myloginfo2(){
    std::cout<<"测试绑定全局函数"<<std::endl;
}

class A{

public:
    nod::signal<void()> signal;
    static void print(){
        std::cout<<"测试绑定静态函数"<<std::endl;
    }
    A(){
        signal.connect(print);
        auto t = std::thread([=](){
             while(1){
                signal();
                 sleep(1);
             }

         });
        t.detach();
    }
};

int main(){

    A a;
    B b;
    a.signal.connect(std::bind(&B::myloginfo,b));
    std::cout<<"main thread"<<std::endl;
    pause();
    return 0;
}
