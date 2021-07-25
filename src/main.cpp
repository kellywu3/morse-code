#include <stdio.h>
#include <chrono>
#include <cmath>
#include "MorseCode.h"
#include "MorseLetter.h"

#define TIME_UNIT 500

unsigned long millis() {
	using namespace std::chrono;
	auto duration = system_clock::now().time_since_epoch();
	auto millis = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
	return millis;
}

const char* message = "Morse Code";

bool doWork(unsigned long invokeTime) {
	static unsigned long nextWorkTime = 0;
	static int i = 0, j = 0;

	if(invokeTime < nextWorkTime) {
		return true;
	}

	char c;
	if((c = message[i]) != 0) {
		MorseLetter* l = MorseLetter::of(c);

		int timing = l->timingAt(j);
		if (j < l->timingLength()) {
			printf("%c - %d - %d %s\n", c, j, timing, timing > 0 ? "on" : "off");
			j++;
		} else {
			j = 0;
			i++;
		}


		nextWorkTime = invokeTime + abs(timing) * TIME_UNIT;

		return true;
	} else {
		return false;
	}
}



int main() {
	unsigned long now;
	bool hasMore = true;
	while (hasMore) {
		now = millis();
		hasMore = doWork(now);
	}

//	for (char i='a'; i<'h'; i++) {
//		MorseLetter* ml = MorseLetter::of(i);
//		printf(
//			"letter [%c] -> %10s :: %10s\n"
//			, i
//			, MorseLetter::toCode(i)
//			, ml->getCode()
//		);
//
//		for (unsigned long j=0; j<ml->length(); j++) {
//			printf("    %2ld - %8d\n", j, ml->timingAt(j));
//		}
//	}

//	while(true) {
//		loop();
//	}

	return 0;
}

