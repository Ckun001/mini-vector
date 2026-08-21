#include <iostream>
#include"util/log.h"//引入日志模块

int main() {
    std::cout << "Mini Vector DB started successfully!" << std::endl;
    std::cout << "Build time: " << __DATE__ << " " << __TIME__ << std::endl;
    LOG_INFO("Mini Vector DB started successfully!");
    LOG_INFO("Build time: %s %s", __DATE__,__TIME__);


    
    return 0;
}
