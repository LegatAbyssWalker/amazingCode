#include <iostream>
#include <stdio.h>

void nice();

int main(void)
{
    nice();
    return 0;
}

void nice()
{
    std::cout<<"This is amazing!"<<std::endl;
    asm("jmp main");
}