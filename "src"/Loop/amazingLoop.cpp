// Code by Binkiklou

#include <iostream>
#include <stdio.h>

void loop();

int main(void)
{
    loop();
    return 0;
}

void loop()
{
    std::cout<<"This is amazing!"<<std::endl;
    asm("jmp main");
}