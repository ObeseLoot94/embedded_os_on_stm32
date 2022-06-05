/*
 * OS.h
 *
 *  Created on: Jun 4, 2022
 *      Author: szuperpeti
 */

#ifndef INC_OS_H_
#define INC_OS_H_

			/*Macros*/
#define STACK_SIZE	(150u)
#define MAX_THREADS (5u)


			/*Function definitions*/
void Create_Thread(void (*thread)(), uint32_t *stackp, uint32_t stack_size);
void Halt_us(volatile uint32_t time);
void Halt_ms(volatile uint32_t time);


			/*Global Variables*/
extern uint8_t thread_count;
extern volatile uint32_t sps[MAX_THREADS][STACK_SIZE];
extern volatile uint32_t *stack_pointers[MAX_THREADS];














#define NOP __asm(  			\
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
);

#endif /* INC_OS_H_ */
