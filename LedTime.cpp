//
// Created by Neven Boric on 10/6/24.
//

#include "LedTime.h"
#include <chrono>
#include <ctime>
#include <cmath>

LedTime::LedTime()
{
	std::time_t now = std::time(nullptr);
	auto tm = std::localtime(&now);
	digits_[0] = LedDigit(tm->tm_hour / 10);
	digits_[1] = LedDigit(tm->tm_hour % 10);
	digits_[2] = LedDigit(tm->tm_min / 10);
	digits_[3] = LedDigit(tm->tm_min % 10);
	auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()
		.time_since_epoch()).count();
	sepDots_ = (milliseconds / 500) % 2 == 0;
}

const std::array<LedDigit, 4>& LedTime::getDigits() const
{
	return digits_;
}

const bool LedTime::getSepDots() const
{
	return sepDots_;
}