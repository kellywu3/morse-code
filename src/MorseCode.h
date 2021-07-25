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
	MorseCode(const char* str);
	virtual ~MorseCode();
	const char* str;
	int timingMultiplier = 1;

	int timingSize();
	int timingAt(int idx);

	static const char* toMorseLetters(char c);
	void doFlashWork();
	int toTiming(char c);
private:
//	int _timingSize;
//	int* _timingVals;
};

#endif /* SRC_MORSECODE_H_ */
