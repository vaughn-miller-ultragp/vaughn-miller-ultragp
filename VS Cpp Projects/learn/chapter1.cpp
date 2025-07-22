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

/*
 * A comment pair is here.
 *
 * This is Section 1.3 of C++ Primer (5th Edition)
 * 
 * Exercise 1.8:
 *      
 */

 void section1_3()
{
    std::cout << "/*";
    std::cout << "*/";
    std::cout << "/* */ */";
    std::cout << /* */ "/* /* */" << std::endl;
}

int flip_endianness(int num, int size)
{
    int out = 0;

    for(int i = 0; i < size; i++){
        out += (0xFF & num) << 8 * (size - 1 - i);
        
        num = num >> 8;
    }

    return out;
}

void flip_string(char* input){
    char tmp;
    int size = 0;
    while(input[size + 1] != '\0')
    {
        ++size;
    }
    
    for(int i = 0; i <= size / 2; i++){
        tmp = input[i];
        input[i] = input[size - i];
        input[size - i] = tmp; 
    }
    
}




int main()
{
    //section1_1();
    //section1_2();
    //section1_3();

    /* int num = 0;

    std::cin >> num;

    num = flip_endianness(num, sizeof(num));

    std::cout << "Endian-flipped number is: " << num; */

    char word[] = "three";

    flip_string(word);
    
    std::cout << "reversed string is: " << word; 

    return 0;
}