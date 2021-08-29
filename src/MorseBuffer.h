/*
 * MorseBuffer.h
 *
 *  Created on: Jul 27, 2021
 *      Author: kelly
 */

#ifndef SRC_MORSEBUFFER_H_
#define SRC_MORSEBUFFER_H_

class MorseBuffer {
public:
	MorseBuffer(int capacity);
	virtual ~MorseBuffer();

	void push(char letter);
	char peek();
	char pop();
private:
	char* buffer;
	int readIdx = 0, writeIdx = 0;
	int capacity;
};

#endif /* SRC_MORSEBUFFER_H_ */
