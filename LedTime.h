//
// Created by Neven Boric on 10/6/24.
//

#ifndef LEDTIME_H_
#define LEDTIME_H_

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
	[[nodiscard]] bool getSepDots() const;
};

#endif //LEDTIME_H_
