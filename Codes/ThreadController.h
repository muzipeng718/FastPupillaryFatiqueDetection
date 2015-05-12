#include "stdafx.h"
#pragma once

#ifndef _THREAD_CONTROLLER_
#define _THREAD_CONTROLLER_

// The controller controls a thread
class ThreadController
{
public:
	ThreadController(unsigned int id);
	~ThreadController(void);

	// Start method, used to call detach method
	void start();

	// If the thread has any job, modify this to control actions
	bool hasJob;
	// Terminated semaphore
	bool isTerminated;

	// id
	unsigned int id;
	// The copy-and-write image
	IplImage* img;

protected:
	// Run loop method, use this method to register actions after thread detached
	void runLoopControl();

	// THE thread
	std::thread m_thread;

private:
	ThreadController();

	// Some params to monitor thread to protect thread safety
	// This bool is used to show if the thread::detach has returned
	bool isReallyTerminated;
};

#endif