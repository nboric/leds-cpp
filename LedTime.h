//
// Created by Neven Boric on 10/6/24.
//

#ifndef _LEDTIME_H_
#define _LEDTIME_H_

#include "LedDigit.h"
#include <array>

class LedTime
{
 private:
	std::array<LedDigit, 4> digits_;
	bool sepDots_;

 public:
	LedTime();
	[[nodiscard]] const std::array<LedDigit, 4>& getDigits() const;
	const bool getSepDots() const;
};

#endif //_LEDTIME_H_
