/*
 ============================================================================
 Name		: GroupListObserver.h
 Author	  : Kolay
 Version	 : 1.0
 Copyright   : 
 Description : CGroupListObserver declaration
 ============================================================================
 */

#ifndef GROUPLISTOBSERVER_H
#define GROUPLISTOBSERVER_H

#include <e32base.h>	// For CActive, link against: euser.lib
#include <e32std.h>		// For RTimer, link against: euser.lib

#include <w32std.h>
#include <APGWGNAM.H>

class MGroupListCallBack
	{
public:
	virtual void ScreenChanged()=0;
	virtual void FocusChanged()=0;
	};

class CGroupListObserver : public CActive
	{
public:
	~CGroupListObserver();
	static CGroupListObserver* NewL(MGroupListCallBack* aCallBack);
	static CGroupListObserver* NewLC(MGroupListCallBack* aCallBack);

private:
	CGroupListObserver();
	void ConstructL(MGroupListCallBack* aCallBack);
	MGroupListCallBack* iCallBack;
	RWsSession* iWsSession;
	RWindowGroup* iWinGroup;
	RWindow iWin;
private:
	void RunL();
	void DoCancel();
	TInt RunError(TInt aError);
	void Listen();
private:
	TInt iState; // State of the active object
	};

#endif // GROUPLISTOBSERVER_H
