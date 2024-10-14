//
// Created by Neven Boric on 10/6/24.
//

#ifndef GPIOMAPPER_H_
#define GPIOMAPPER_H_

#include <gpiod.hpp>
#include "LedDigit.h"
#include "LedTime.h"

class GpioMapper
{
 private:
	const ::gpiod::line::offsets led_segments_line_offsets = { 25, 23, 17, 6, 5, 24, 27, 26, 22 };
	const ::gpiod::line::offsets digit_select_line_offsets = { 16, 20, 21, 19 };

	::gpiod::line::values led_segment_values;
	::gpiod::line::values digit_select_values;

 public:
	GpioMapper();
	[[nodiscard]] const ::gpiod::line::offsets& getLedSegmentsLineOffsets() const;
	[[nodiscard]] const ::gpiod::line::offsets& getDigitSelectLineOffsets() const;

	const ::gpiod::line::values& getDigitSelectValues(int whichDigit);
	const ::gpiod::line::values& getLedSegmentValues(LedTime& ledTime, int whichDigit);
};

#endif //GPIOMAPPER_H_
