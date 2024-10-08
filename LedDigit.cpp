//
// Created by Neven Boric on 10/6/24.
//

#include "LedDigit.h"
LedDigit::LedDigit(int digit)
	: digit_(digit)
{
	switch (digit)
	{
	case 0:
		segments_ = { 1, 1, 1, 1, 1, 1, 0, 0, 0 };
		break;
	case 1:
		segments_ = { 0, 1, 1, 0, 0, 0, 0, 0, 0 };
		break;
	case 2:
		segments_ = { 1, 1, 0, 1, 1, 0, 1, 0, 0 };
		break;
	case 3:
		segments_ = { 1, 1, 1, 1, 0, 0, 1, 0, 0 };
		break;
	case 4:
		segments_ = { 0, 1, 1, 0, 0, 1, 1, 0, 0 };
		break;
	case 5:
		segments_ = { 1, 0, 1, 1, 0, 1, 1, 0, 0 };
		break;
	case 6:
		segments_ = { 1, 0, 1, 1, 1, 1, 1, 0, 0 };
		break;
	case 7:
		segments_ = { 1, 1, 1, 0, 0, 0, 0, 0, 0 };
		break;
	case 8:
		segments_ = { 1, 1, 1, 1, 1, 1, 1, 0, 0 };
		break;
	case 9:
		segments_ = { 1, 1, 1, 1, 0, 1, 1, 0, 0 };
		break;
	default:
		segments_ = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
		break;
	}
}

const std::array<int, 9>& LedDigit::getSegments() const
{
	return segments_;
}

const int LedDigit::getDigit() const
{
	return digit_;
}
