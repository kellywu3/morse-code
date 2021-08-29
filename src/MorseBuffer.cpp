/*
 * MorseBuffer.cpp
 *
 *  Created on: Jul 27, 2021
 *      Author: kelly
 */

#include <iostream>
#include <cstdlib>
#include <string.h>
#include "MorseBuffer.h"

MorseBuffer::MorseBuffer(int capacity) :
capacity { capacity + 1 }
{
	buffer = (char*) malloc(capacity*sizeof(char));
}

MorseBuffer::~MorseBuffer() {
	if(buffer) {
		free(buffer);
	}
}

void MorseBuffer::push(char letter) {
	int nextWriteIdx = (writeIdx + 1) % capacity;
	if(nextWriteIdx == readIdx) {
		printf("no can do\n");
		return;
	}

	buffer[writeIdx] = letter;
	writeIdx = nextWriteIdx;
 }

char MorseBuffer::peek() {
	return buffer[readIdx];
}

char MorseBuffer::pop() {
	if(readIdx == writeIdx) {
		return 0;
	}
	char c = buffer[readIdx];
	readIdx++;
	if(readIdx >= capacity) {
		readIdx = 0;
	}
	return c;
}
