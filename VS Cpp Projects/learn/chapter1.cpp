#include <iostream>

void section1_1()
{
    std::cout << "Enter two numbers:" << std::endl;
    int v1 = 0;
    int v2 = 0;
    std::cin >> v1 >> v2;
    std::cout << "The sum of " << v1 << " and " << v2
            << " is " << v1 + v2 << std::endl;
    
}

void section1_2()
{
    // prompt user to enter two numbers
    std::cout << "Enter two numbers:" << std::endl;
    int v1 = 0; // variables to hold number inputs
    int v2 = 0;
    std::cin >> v1 >> v2; // read input to variables
    std::cout << "The product of ";
    std::cout << v1;
    std::cout << " and ";
    std::cout << v2;
    std::cout << " is ";
    std::cout << v1 * v2;
    std::cout << std::endl;
}


int main()
{
    //section1_1();
    section1_2();

    return 0;
}