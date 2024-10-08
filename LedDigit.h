//
// Created by Neven Boric on 10/6/24.
//

#ifndef _LEDDIGIT_H_
#define _LEDDIGIT_H_

#include <array>

class LedDigit
{
 private:
	int digit_;
	std::array<int, 9> segments_;

 public:
	LedDigit() : LedDigit(0) {}
	explicit LedDigit(int digit);
	[[nodiscard]] const int getDigit() const;
	[[nodiscard]] const std::array<int, 9>& getSegments() const;

};

#endif //_LEDDIGIT_H_
