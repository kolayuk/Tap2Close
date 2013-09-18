
#ifndef TAP2CLOSE_PAN_H
#define TAP2CLOSE_PAN_H

/** Tap2Close application panic codes */
enum TTap2ClosePanics
	{
	ETap2CloseUi = 1
	// add further panics here
	};

inline void Panic(TTap2ClosePanics aReason)
	{
	_LIT(applicationName,"Tap2Close");
	User::Panic(applicationName, aReason);
	}

#endif // TAP2CLOSE_PAN_H
