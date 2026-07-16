#ifndef INTERRUPTSMANAGER_H
#define INTERRUPTSMANAGER_H

// include required libraries
#include <cstddef>
#include "irq/interrupts.h"

/**
 * Handles system interrupts
 */
class InterruptsManager {
	public:
		//! returns if vblank has occurred
		bool isFrameReady();
		//! clears the vblank flag;
		void clearFrameReady();
		//! returns the current frameCounter;
		unsigned long getFrameCounter();
		//! returns instance of class
		static InterruptsManager& getInstance();
	private:
		//! default class constructor
		InterruptsManager();
		//! flag for if a VBlank occured
		volatile bool frameReady;
		//! counter for ow many frames of VBlanks occured
		volatile unsigned long frameCounter;
		//! disable copy construction
		InterruptsManager(const InterruptsManager&);
		//! disable assignment
		InterruptsManager& operator=(const InterruptsManager&);
		//! handle for when a VBlank occurs
		static void handleOnVBlank();
		//! actual logic for when a VBlank occurs
		void onVBlank();
};
#endif
