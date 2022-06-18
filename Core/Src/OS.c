
#include <stdint.h>
#include "OS.h"
#include "main.h"


uint8_t thread_ctr = 0;
TCB *current_stack_pt;
TCB tcb[MAX_THREADS] = {0};
//uint8_t task_scanner1 = 0;
//uint8_t task_scanner2 = 0;

void Halt_us(uint32_t time)
{
	for (uint32_t i = 0; i < time; ++i) {
		NOP_US;
	}

}

void Halt_ms(uint32_t time)
{
	for(uint32_t i = 0; i < time; ++i) {
		for (uint32_t ii = 0; ii < 64; ++ii) {
			NOP_MS;
		}
	}
}


void Create_Thread(void (*thread_handler)(void))
{
	if(thread_ctr < MAX_THREADS)
	{

		tcb[thread_ctr].stack_pointer = &tcb[thread_ctr].stack[STACK_SIZE];

		--tcb[thread_ctr].stack_pointer; *(tcb[thread_ctr].stack_pointer) |= 1<<24;						/*xPSR*/
		*(--tcb[thread_ctr].stack_pointer) = (uint32_t) thread_handler;									/*PC*/
		*(--tcb[thread_ctr].stack_pointer) = 0xDEADBEEF; 												/* LR*/
		*(--tcb[thread_ctr].stack_pointer) = 0xDEADBEEF;												/*R12*/
		*(--tcb[thread_ctr].stack_pointer) = 0xDEADBEEF;												/*R3*/
		*(--tcb[thread_ctr].stack_pointer) = 0xDEADBEEF;												/*R2*/
		*(--tcb[thread_ctr].stack_pointer) = 0xDEADBEEF;												/*R1*/
		*(--tcb[thread_ctr].stack_pointer) = 0xDEADBEEF;   												/*R0*/
		*(--tcb[thread_ctr].stack_pointer) = 0xDEADBEEF;												/*R11*/
		*(--tcb[thread_ctr].stack_pointer) = 0xDEADBEEF;												/*R10*/
		*(--tcb[thread_ctr].stack_pointer) = 0xDEADBEEF;												/*R9*/
		*(--tcb[thread_ctr].stack_pointer) = 0xDEADBEEF;												/*R8*/
		*(--tcb[thread_ctr].stack_pointer) = 0xDEADBEEF;   												/*R7*/
		*(--tcb[thread_ctr].stack_pointer) = 0xDEADBEEF;												/*R6*/
		*(--tcb[thread_ctr].stack_pointer) = 0xDEADBEEF;												/*R5*/
		*(--tcb[thread_ctr].stack_pointer) = 0xDEADBEEF;												/*R4*/

		++thread_ctr;
	}

}

void os_init(void)
{
	//__disable_irq();
	SysTick_Config(SystemCoreClock/1000);

	tcb[0].next = &tcb[1];
	tcb[1].next = &tcb[0];

	current_stack_pt = &tcb[0];

	__asm("LDR	R0,=current_stack_pt");			/*r0=&current_stack_pt*/
	__asm("LDR	R1, [R0]");			// r1 = *R0; --> r1 = current_stack_pt; --> r1 = current_stack_pt->stack_pointer;
	__asm("LDR	SP, [R1]");
	__asm("pop	{r11}");
	__asm("pop	{r10}");
	__asm("pop	{r9}");
	__asm("pop	{r8}");
	__asm("pop	{r7}");
	__asm("pop	{r6}");
	__asm("pop	{r5}");
	__asm("pop	{r4}");
	__asm("pop	{r12}");
	__asm("pop	{r3}");
	__asm("pop	{r2}");
	__asm("pop	{r1}");
	__asm("pop	{r0}");
	__asm("add	sp,sp,#4");
	__asm("POP	{LR}");
	__asm("add	sp,sp,#4");
	__enable_irq();
	__asm("bx 	lr");

	/*__asm("LDR	R0,=current_stack_pt");
	__asm("LDR	R1, [R0]");
	__asm("LDR	SP, [R1]");
	__asm("pop	{r0-r12}");
	__asm("add	sp,sp,#4");
	__asm("POP	{LR}");
	__asm("add	sp,sp,#4");
	__asm("CPSIE	I");
	__asm("bx 	lr");*/

}

			/*THREADS*/
void Blink1(void)
{
	//uint8_t task_scanner1 = 0;

	while(1){
		GPIOC->ODR ^= 1<<2;
		Halt_ms(200);
		//++task_scanner1;
	}
}

void Blink2(void)
{
	//uint8_t task_scanner2 = 0;
	while(1){

		GPIOC->ODR ^= 1<<3;
		Halt_ms(50);
		//++task_scanner2;

	}
}



