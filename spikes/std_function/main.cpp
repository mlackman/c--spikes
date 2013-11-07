#include <iostream>
#include <functional>

void callCallback(std::function<void()> fn) {
    fn();
}

class Test {
    
public:

    void callback() {
        std::cout << "object callback" << std::endl;
    }

};
 
int main(int argc, char** argv) {
    callCallback([]{ std::cout << "lambda callback" << std::endl; });
    
    Test t;
    callCallback([&t]{ t.callback(); });

    std::function<void(Test&)> callback = &Test::callback;
    auto callToCallback = std::bind(callback, t);
    callCallback(callToCallback);
}