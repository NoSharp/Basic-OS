#ifndef PORTS_H
#define PORTS_H

#include "types.h"

uint8 inPortB(uint16 port)
{
	uint8 rv;
	__asm__ __volatile__("inb %1, %0" : "=a" (rv) : "dN" (port));
	return rv;
}

void outportb (uint16 _port, uint8 _data){

    __asm__ __volatile__("outw %w0, %w1" : : "a" (_data), "Nd" (_port));

}

#endif