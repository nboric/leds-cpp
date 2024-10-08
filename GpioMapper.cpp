//
// Created by Neven Boric on 10/6/24.
//

#include "GpioMapper.h"

GpioMapper::GpioMapper()
	: led_segment_values(9), digit_select_values(4)
{
}

const ::gpiod::line::offsets& GpioMapper::getLedSegmentsLineOffsets() const
{
	return led_segments_line_offsets;
}

const ::gpiod::line::offsets& GpioMapper::getDigitSelectLineOffsets() const
{
	return digit_select_line_offsets;
}

const ::gpiod::line::values& GpioMapper::getDigitSelectValues(int whichDigit)
{
	for (int i = 0; i < 4; i++)
	{
		digit_select_values[i] = ::gpiod::line::value::ACTIVE;
	}
	digit_select_values[whichDigit] = ::gpiod::line::value::INACTIVE;
	return digit_select_values;
}

const ::gpiod::line::values& GpioMapper::getLedSegmentValues(LedTime& ledTime, int whichDigit)
{
	auto digits = ledTime.getDigits();
	auto segments = digits[whichDigit].getSegments();
	for (int i = 0; i < 8; i++)
	{
		led_segment_values[i] = segments[i] ? ::gpiod::line::value::ACTIVE : ::gpiod::line::value::INACTIVE;
	}
	led_segment_values[8] = ledTime.getSepDots() ? ::gpiod::line::value::ACTIVE
												 : ::gpiod::line::value::INACTIVE;
	return led_segment_values;
}
