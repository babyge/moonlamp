#ifndef TOUCH_H_
#define TOUCH_H_

#include <avr/io.h>
#include <avr/interrupt.h>

#define TOUCH_DEF_THRESHOLD		100
#define TOUCH_HYSTERESIS		20

struct {
	uint16_t CaptureValue;
	// device is currently being touched
	uint8_t touching :1;
	// device has been touched for a short period of time (<0.5s)
	uint8_t tapped :1;
	// device is being touched for a longer time (>0.5s)
	uint8_t holding :1;

	uint16_t threshold;
	uint16_t count;
} touch;

/**
 * \brief Initializes touch functionality
 */
void touch_Init(void);

/**
 * \brief Checks whether the touch pin has been tapped (touched for a short time)
 *
 * \return 1 if it has been tapped, 0 otherwise
 */
uint8_t touch_Tapped(void);

/**
 * \brief Checks whether the touch pin is currently being hold
 * (touched for a longer time)
 *
 * \return 1 if it is being held, 0 otherwise
 */
uint8_t touch_Holding(void);

#endif