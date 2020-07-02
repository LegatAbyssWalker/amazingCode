// Code by Obiwac

/* full disclamer: DO NOT USE THIS CODE, IT ACTUALLY WORKS */
/* this is ONLY meant as a way to introduce potential bugs in amazingCode(TM) where you want to do an infinite loop */
/* if you wanna check out an actual AMAZING implemtation of this, check out bink's version here: https://github.com/LegatAbyssWalker/amazingCode/pull/15 */

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
