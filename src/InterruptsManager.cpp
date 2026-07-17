// include the header
#include "../include/InterruptsManager.h"

/**
 * Default class constructor
 */
InterruptsManager::InterruptsManager(): frameReady(false), frameCounter(0) {
		// initalize frameReady to false
		frameReady = false;
		// attach the interrupt to the vector
		attach_isr(INT_PPU_VBLANK_START, &InterruptsManager::handleOnVBlank);
		// enable the vblank interrupt
		enable_isr(INT_PPU_VBLANK_START);
}

/**
 * handler for when vblank occurs
 */
void InterruptsManager::handleOnVBlank() {
	getInstance().onVBlank();
}

/**
 * actual logic for the vblank
 */
void InterruptsManager::onVBlank() {
	// increment the frame counter
	frameCounter++;
	// set the VBlank flag
	frameReady = true;
	// ACK the VBlank interrupt
	*P_IRQ_STATUS = 0x00000001u;
}

/**
 * returns if the VBlank flag was set
 *
 * @return true if a VBlank has occured since the last check, otherwise false
 *
 */
bool InterruptsManager::isFrameReady() {
	return frameReady;
}

/**
 * clears the VBlank flag
 */
void InterruptsManager::clearFrameReady() {
	frameReady = false;
}

/**
 * returns the number of frames processed by the vblank handler
 *
 * @return the current number of frames processed by VBlank
 *
 */
 unsigned long InterruptsManager::getFrameCounter() {
 	return frameCounter;
}

/**
 * returns the current instance of the class
 *
 * @return InterruptsManager instance
 *
 */
InterruptsManager& InterruptsManager::getInstance() {
	static InterruptsManager instance;
    return instance;
}
