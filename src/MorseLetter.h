/*
 * MorseLetter.h
 *
 *  Created on: Jul 22, 2021
 *      Author: kelly
 */
#ifndef SRC_MORSELETTER_H_
#define SRC_MORSELETTER_H_

class MorseLetter {
public:
	MorseLetter(char letter, const char* code);
	virtual ~MorseLetter();

	char getLetter() { return _letter; }
	const char* getCode() { return _code; }

	/**
	 * Returns the length of the Morse code timing table
	 * Return int length of Morse code timing table
	 */
	int timingLength();

	/**
	 * Returns the timing for the given times index of the Morse code
	 * Return int unit of time; positive indicates on state, negative
	 * indicates off state, zero indicates that the timing index is invalid
	 * Callers should multiply the time value by the desired scale
	 */
	int timingAt(int index);

	static const char* toCode(char c);
	static MorseLetter* of(char c);
private:
	static int _cnt;
	char _letter;
	const char* _code;
	int _timingLength;
};

#endif /* SRC_MORSELETTER_H_ */
