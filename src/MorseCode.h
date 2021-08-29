/*
 * MorseCode.h
 *
 *  Created on: Jul 21, 2021
 *      Author: kelly
 */

#ifndef SRC_MORSECODE_H_
#define SRC_MORSECODE_H_

class MorseCode {
public:
	MorseCode(const char* userMessage);
	virtual ~MorseCode();

	static const char* toMorseLetters(char c);

	void begin();
	bool doFlashWork(unsigned long invokeTime);
private:
	const char* userMessage;
	int letterIdx = 0;
	int letterTimingIdx = 0;
	const char* morseLetterTiming = nullptr;

	unsigned long nextWakeTime = 0;
	int timingMultiplier = 500;

	int toTiming(char c);
};

#endif /* SRC_MORSECODE_H_ */
