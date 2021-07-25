/*
 * MorseCode.cpp
 *
 *  Created on: Jul 21, 2021
 *      Author: kelly
 */

#include <stdio.h>
#include <ctype.h>
#include "MorseCode.h"

MorseCode::MorseCode(const char* str) :
str { str }
{
	// TODO Auto-generated constructor stub

}

MorseCode::~MorseCode() {
	// TODO Auto-generated destructor stub
}

int MorseCode::timingSize() {
	return 0;
}

int MorseCode::timingAt(int idx) {
	return 0;
}

void MorseCode::doFlashWork() {
	int i = 0;
	while(str[i] != '\0') {
		const char* timing = toMorseLetters(str[i]);
		int j = 0;
		while(timing[j] != '\0') {
			int lightTime = toTiming(timing[j]);
			printf("%s, %d\n", lightTime > 0 ? "on: " : "off: ", (lightTime * timingMultiplier));
			j++;
		}
		i++;
	}
}

int MorseCode::toTiming(char c) {
	switch(c) {
	case '.':
		return 1;
	case '-':
		return 3;
	case ',':
		return -1;
	case '_':
		return -3;
	case '/':
		return 4;
	default:
		return 0;
	}
}

const char* MorseCode::toMorseLetters(char c) {
	c = tolower(c);
	switch(c) {
	case 'a':
		return ".,-_";
	case 'b':
		return "-,.,.,._";
	case 'c':
		return "-,.,-,._";
	case 'e':
		return "._";
	case 'f':
		return ".,.,-,._";
	case 'g':
		return "-,-,._";
	case 'h':
		return ".,.,.,._";
	case 'i':
		return ".,._";
	case 'j':
		return ".,-,-,-_";
	case 'k':
		return "-,.,-_";
	case 'l':
		return ".,-,.,._";
	case 'm':
		return "-,-_";
	case 'n':
		return "-,._";
	case 'o':
		return "-,-,-_";
	case 'p':
		return ".-,-,._";
	case 'q':
		return "-,-,.,-_";
	case 'r':
		return ".,-,._";
	case 's':
		return ".,.,._";
	case 't':
		return "-_";
	case 'u':
		return ".,.,-_";
	case 'v':
		return ".,.,.,-_";
	case 'w':
		return ".,-,-_";
	case 'x':
		return "-,.,.,-_";
	case 'y':
		return "-,.,-,-_";
	case 'z':
		return "-,-,.,._";
	case ' ':
		return "/";
	case '.':
		return ".,-,.,-,.,-_";
	default:
		return nullptr;
	}

}

