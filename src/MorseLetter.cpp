/*
 * MorseLetter.cpp
 *
 *  Created on: Jul 22, 2021
 *      Author: kelly
 */

#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <unordered_map>
#include "MorseLetter.h"

int MorseLetter::_cnt = 0;

static MorseLetter letters[] = {
		MorseLetter{ 'a', ".-" }
		, MorseLetter{ 'b', ".-"}
		, MorseLetter{ 'c', "_._."}
		, MorseLetter{ 'd', "-.."}
		, MorseLetter{ 'e', "."}
		, MorseLetter{ 'f', "..-."}
		, MorseLetter{ 'g', "--."}
		, MorseLetter{ 'h', "...."}
		, MorseLetter{ 'i', ".."}
		, MorseLetter{ 'j', ".---"}
		, MorseLetter{ 'k', "-.-"}
		, MorseLetter{ 'l', ".-.."}
		, MorseLetter{ 'm', "--"}
		, MorseLetter{ 'n', "-."}
		, MorseLetter{ 'o', "---"}
		, MorseLetter{ 'p', ".--."}
		, MorseLetter{ 'q', "--.-"}
		, MorseLetter{ 'r', ".-."}
		, MorseLetter{ 's', "..."}
		, MorseLetter{ 't', "-"}
		, MorseLetter{ 'u', "..-"}
		, MorseLetter{ 'v', "...-"}
		, MorseLetter{ 'w', ".--"}
		, MorseLetter{ 'x', "-..-"}
		, MorseLetter{ 'y', "-.--"}
		, MorseLetter{ 'z', "--.."}
		, MorseLetter{ ' ', " "}
};

static int lettersCnt = sizeof(letters) / sizeof(letters[0]);

static std::unordered_map<char, MorseLetter*> _morseLetters;

static int initMorseCodes() {
	for (int i=0; i<lettersCnt; i++) {
		MorseLetter* p = letters + i;
		_morseLetters[p->getLetter()] = p;
	}

	printf("initMorseCodes - %d letters\n", lettersCnt);

	return lettersCnt;
}

static int morseCodeSize = initMorseCodes();


MorseLetter::MorseLetter(char letter, const char* code) :
_letter { letter }, _code { code }
{
	_cnt++;
	_timingLength = strlen(code) * 2;
	printf("MorseLetter #%03d - ('%c', \"%s\") created\n", _cnt, letter, code);
}

MorseLetter::~MorseLetter() {
	// TODO Auto-generated destructor stub
}

const char* MorseLetter::toCode(char c) {
	return of(c)->getCode();
}

MorseLetter* MorseLetter::of(char c) {
	c = tolower(c);
	return _morseLetters[c];
}

int MorseLetter::timingLength() {
	return _timingLength;
}

int MorseLetter::timingAt(int index) {
	if(index >= _timingLength) {
		return 0;
	} else if(index == _timingLength -1) {
		return -3;
	} else if(index % 2) {
		return -1;
	}

	int pos = index / 2;
	char c = _code[pos];

	switch(c) {
	case '.':
		return 1;
	case '-':
		return 3;
	// space- special case, indicates space between words
	case ' ':
		return -1;
	default:
		return 0;
	}
}
