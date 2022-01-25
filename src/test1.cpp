#include <iostream>

#include <ProjectConfig.h>
#include "MathFunctions.h"

#ifdef USE_OPTIONAL_LIB
    #include "OptionalHeaders.h"
#endif

int main()
{
    std::cout << "This is the main function ... Ver " 
                << Project1_VERSION_MAJOR << "." 
                << Project1_VERSION_MINOR << std::endl;
    
    MySqrt sqrtFunc;
    std::cout << "Squrare of 5: " << sqrtFunc.mysqrt(5) << std::endl;
    
    #ifdef USE_OPTIONAL_LIB
    std::cout << OptionalPrintout() << std::endl;
    #endif

    return 0;
}