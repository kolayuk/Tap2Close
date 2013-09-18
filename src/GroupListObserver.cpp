/*
 ============================================================================
 Name		: GroupListObserver.cpp
 Author	  : Kolay
 Version	 : 1.0
 Copyright   : 
 Description : CGroupListObserver implementation
 ============================================================================
 */

#include "GroupListObserver.h"
#include <eikenv.h>
#include <APGWGNAM.H>
#include <W32STD.H>

CGroupListObserver::CGroupListObserver() :
	CActive(EPriorityStandard)// Standard priority
	{
	}

CGroupListObserver* CGroupListObserver::NewLC(MGroupListCallBack* aCallBack)
	{
	CGroupListObserver* self = new (ELeave) CGroupListObserver();
	CleanupStack::PushL(self);
	self->ConstructL(aCallBack);
	return self;
	}

CGroupListObserver* CGroupListObserver::NewL(MGroupListCallBack* aCallBack)
	{
	CGroupListObserver* self = CGroupListObserver::NewLC(aCallBack);
	CleanupStack::Pop(); // self;
	return self;
	}

void CGroupListObserver::ConstructL(MGroupListCallBack* aCallBack)
	{
	CActiveScheduler::Add(this);
	
	iCallBack=aCallBack;
	iWsSession =  new (ELeave)RWsSession();
	iWsSession->Connect();
	iWinGroup=new (ELeave) RWindowGroup(*iWsSession);
	iWinGroup->Construct((TUint32)&iWinGroup, EFalse);
	iWinGroup->SetOrdinalPosition(-1);
	iWinGroup->EnableReceiptOfFocus(ETrue);
	
	CApaWindowGroupName* wn=CApaWindowGroupName::NewL(*iWsSession);
	wn->SetHidden(ETrue);
	wn->SetSystem(ETrue);
	wn->SetWindowGroupName(*iWinGroup);
	delete wn;
	iWinGroup->EnableScreenChangeEvents();
	iWinGroup->EnableFocusChangeEvents();
	Listen();
	}

CGroupListObserver::~CGroupListObserver()
	{
	Cancel(); 
	iWin.Close();
	iWinGroup->Close();
	iWsSession->Close();
	}

void CGroupListObserver::DoCancel()
	{
	iWsSession->EventReadyCancel();
	}

void CGroupListObserver::RunL()
	{
	if (iStatus==KErrNone)
		{
		TWsEvent e;
		iWsSession->GetEvent(e);
		if (e.Type()==EEventScreenDeviceChanged){iCallBack->ScreenChanged();}
		if (e.Type()==EEventFocusGroupChanged){iCallBack->FocusChanged();}
		}
	
	Listen();
	}

TInt CGroupListObserver::RunError(TInt aError)
	{
	return aError;
	}
void CGroupListObserver::Listen()
{
	iWsSession->EventReady(&iStatus);
	SetActive();
}
