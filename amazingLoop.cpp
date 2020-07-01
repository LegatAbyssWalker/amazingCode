/* thank you bink */
/* full disclamer: DO NOT USE THIS CODE, IT ACTUALLY WORKS */
/* this is ONLY meant as a way to introduce potential bugs in amazingCode(TM) where you want to do an infinite loop */

#include <iostream>

void nice();

int main() {
	asm("pop %rbp");
	nice();
}

void nice() {
	std::cout << "Loop\n";
	asm("pop %rbp;jmp main");
}
