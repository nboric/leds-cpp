//
// Created by Neven Boric on 10/6/24.
//

#ifndef LEDDIGIT_H_
#define LEDDIGIT_H_

#include <array>

class LedDigit
{
 private:
	int digit_;
	std::array<int, 9> segments_;

 public:
	LedDigit() : LedDigit(0) {}
	explicit LedDigit(int digit);
	[[nodiscard]] int getDigit() const;
	[[nodiscard]] const std::array<int, 9>& getSegments() const;

};

#endif //LEDDIGIT_H_
