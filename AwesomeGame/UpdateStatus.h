#ifndef UPDATESTATUS_H
#define UPDATESTATUS_H

#include <Windows.h>

#define LOG(txt) OutputDebugString(txt) //Define what's LOG?

#define EXIT_FAILURE 1  //Same than 0 with 1 and failure
#define EXIT_SUCCESS 0 //0 is success, so we don't have all 0 over there

enum update_status {

	UPDATE_CONTINUE = 1,
	UPDATE_STOP,
	UPDATE_ERROR
};
//Update has 3 states, continue (if all ok), stop (it has to stop) and error

#endif
