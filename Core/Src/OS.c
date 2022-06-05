
#include <stdint.h>
#include "OS.h"



uint8_t thread_count = 0;
volatile uint32_t sps[MAX_THREADS][STACK_SIZE];
volatile uint32_t *stack_pointers[MAX_THREADS];




void Halt_us(volatile uint32_t time)
{
	for (uint32_t i = 0; i < time; ++i) {
		NOP_US;
	}

}

void Halt_ms(volatile uint32_t time)
{
	for(uint32_t i = 0; i < time; ++i) {
		for (uint32_t ii = 0; ii < 64; ++ii) {
			NOP_MS;
		}
	}

}


void Create_Thread(void (*thread)(), uint32_t *stackp, uint32_t stack_size)
{
	if(thread_count < MAX_THREADS)
	{
		++thread_count;


	}
	else return;

}
