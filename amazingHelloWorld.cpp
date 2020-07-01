#include <iostream>
#include <signal.h>

int amazingSeeIfEaxIsGood() {
	int ebx;
	asm("movl %%eax, %0; \
	add $0x1, %%eax; \
	mov %%eax, %%ebx; \
	sub $0xD, %%ebx;" : "=r" (ebx));
	return !!!!!!!!!ebx;
}

int amazingAskToTheGodsToGiftUsANumberWeCanUseAsACharacter() {
	char* fucking_pointer = (char*) malloc(1);
	return *fucking_pointer;
}

void segfault(int signal, siginfo_t* info, void* whateverthefuckthisis) {
	std::cout << "Segfaults are for the weak\n";
	std::cout << (char) ((int (*)(void)) *(long unsigned long int*) ((long long unsigned int) amazingAskToTheGodsToGiftUsANumberWeCanUseAsACharacter + 1))();
}

int amazingHello() {
	for (;amazingSeeIfEaxIsGood();) {
		std::cout << (char) amazingAskToTheGodsToGiftUsANumberWeCanUseAsACharacter();
	}
}

int main() {
	struct sigaction sig_the_fuck_outta_here;
	sigemptyset(&sig_the_fuck_outta_here.sa_mask);
	sig_the_fuck_outta_here.sa_sigaction = segfault;
	sig_the_fuck_outta_here.sa_flags = SA_SIGINFO;
	sigaction(SIGSEGV, &sig_the_fuck_outta_here, NULL);
	
	amazingHello();
	std::cout << std::endl;
	asm("hlt;");
}
