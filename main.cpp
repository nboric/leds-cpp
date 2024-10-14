#include "LedTime.h"
#include "GpioMapper.h"

#include <gpiod.hpp>

#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds

const ::gpiod::line::offsets led_segments_line_offsets = { 25, 23, 17, 6, 5, 24, 27, 26, 22 };
const ::gpiod::line::offsets digit_select_line_offsets = { 16, 20, 21, 19 };

int main()
{
	gpiod::chip chip("/dev/gpiochip0");

	GpioMapper gpioMapper;

	auto led_segments_request = chip.prepare_request()
		.set_consumer("led-segments")
		.add_line_settings(
			gpioMapper.getLedSegmentsLineOffsets(),
			::gpiod::line_settings().set_direction(
				::gpiod::line::direction::OUTPUT)
		)
		.do_request();

	auto digit_select_request = chip.prepare_request()
		.set_consumer("led-segments")
		.add_line_settings(
			gpioMapper.getDigitSelectLineOffsets(),
			::gpiod::line_settings().set_direction(
				::gpiod::line::direction::OUTPUT)
		)
		.do_request();

	while (true)
	{
		LedTime ledTime;
		for (int i = 0; i < 4; i++)
		{
			auto digit_select_values = gpioMapper.getDigitSelectValues(i);
			digit_select_request.set_values(digit_select_line_offsets, digit_select_values);

			auto led_segment_values = gpioMapper.getLedSegmentValues(ledTime, i);
			led_segments_request.set_values(led_segments_line_offsets, led_segment_values);
			std::this_thread::sleep_for(std::chrono::milliseconds(1));
		}
	}
	return 0;
}
