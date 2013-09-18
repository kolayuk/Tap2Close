/*
========================================================================
 Name        : Tap2CloseAppUi.cpp
 Author      : Usanov-Kornilov Nikolay (aka Kolay)
 Copyright   : 
Contacts:
	kolayuk@mail.ru
	http://kolaysoft.ru

(c) KolaySoft, 2010

 Description : 
========================================================================
*/
// [[[ begin generated region: do not modify [Generated System Includes]
#include <eikmenub.h>
#include <akncontext.h>
#include <akntitle.h>
#include <Tap2Close.rsg>
// ]]] end generated region [Generated System Includes]

// [[[ begin generated region: do not modify [Generated User Includes]
#include "Tap2CloseAppUi.h"
#include "Tap2Close.hrh"
#include "MainView.h"
// ]]] end generated region [Generated User Includes]

// [[[ begin generated region: do not modify [Generated Constants]
// ]]] end generated region [Generated Constants]

#include <GroupListObserver.h>
#include <APGWGNAM.H>
#include <Tap2Close.mbg>

const TSize KSize=TSize(15,15);
const TInt KLongTapDelay=500;
const TUid KStandbyUid={0x102750f0};
const TUid KSpbShellUid={0x20028b16};
/**
 * Construct the CTap2CloseAppUi instance
 */ 
CTap2CloseAppUi::CTap2CloseAppUi(): MCoeControlObserver(), MGroupListCallBack()
	{
	// [[[ begin generated region: do not modify [Generated Contents]
	// ]]] end generated region [Generated Contents]
	
	}

/** 
 * The appui's destructor removes the container from the control
 * stack and destroys it.
 */
CTap2CloseAppUi::~CTap2CloseAppUi()
	{
	// [[[ begin generated region: do not modify [Generated Contents]
	// ]]] end generated region [Generated Contents]
	
	}

// [[[ begin generated function: do not modify
void CTap2CloseAppUi::InitializeContainersL()
	{
	iMainView = CMainView::NewL();
	AddViewL( iMainView );
	SetDefaultViewL( *iMainView );
	}
// ]]] end generated function

/**
 * Handle a command for this appui (override)
 * @param aCommand command id to be handled
 */
void CTap2CloseAppUi::HandleCommandL( TInt aCommand )
	{
	// [[[ begin generated region: do not modify [Generated Code]
	TBool commandHandled = EFalse;
	switch ( aCommand )
		{ // code to dispatch to the AppUi's menu and CBA commands is generated here
		default:
			break;
		}
	
		
	if ( !commandHandled ) 
		{
		if ( aCommand == EAknSoftkeyExit || aCommand == EEikCmdExit )
			{
			Exit();
			}
		}
	// ]]] end generated region [Generated Code]
	
	}

/** 
 * Override of the HandleResourceChangeL virtual function
 */
void CTap2CloseAppUi::HandleResourceChangeL( TInt aType )
	{
	CAknViewAppUi::HandleResourceChangeL( aType );
	// [[[ begin generated region: do not modify [Generated Code]
	// ]]] end generated region [Generated Code]
	
	}
				
/** 
 * Override of the HandleKeyEventL virtual function
 * @return EKeyWasConsumed if event was handled, EKeyWasNotConsumed if not
 * @param aKeyEvent 
 * @param aType 
 */
TKeyResponse CTap2CloseAppUi::HandleKeyEventL(
		const TKeyEvent& aKeyEvent,
		TEventCode aType )
	{
	// The inherited HandleKeyEventL is private and cannot be called
	// [[[ begin generated region: do not modify [Generated Contents]
	// ]]] end generated region [Generated Contents]
	
	return EKeyWasNotConsumed;
	}

/** 
 * Override of the HandleViewDeactivation virtual function
 *
 * @param aViewIdToBeDeactivated 
 * @param aNewlyActivatedViewId 
 */
void CTap2CloseAppUi::HandleViewDeactivation( 
		const TVwsViewId& aViewIdToBeDeactivated, 
		const TVwsViewId& aNewlyActivatedViewId )
	{
	CAknViewAppUi::HandleViewDeactivation( 
			aViewIdToBeDeactivated, 
			aNewlyActivatedViewId );
	// [[[ begin generated region: do not modify [Generated Contents]
	// ]]] end generated region [Generated Contents]
	
	}

/**
 * @brief Completes the second phase of Symbian object construction. 
 * Put initialization code that could leave here. 
 */ 
void CTap2CloseAppUi::ConstructL()
	{
	// [[[ begin generated region: do not modify [Generated Contents]
	
	BaseConstructL( EAknEnableSkin  | 
					 EAknEnableMSK ); 
	InitializeContainersL();
	// ]]] end generated region [Generated Contents]
	//CCoeControl
	
	iWinGroup=new (ELeave) RWindowGroup(CEikonEnv::Static()->WsSession());
	iWinGroup->Construct((TUint32)&iWinGroup, EFalse);
	iWinGroup->EnableReceiptOfFocus(EFalse); // Don't capture any key events.
	iWinGroup->SetOrdinalPosition(0, ECoeWinPriorityAlwaysAtFront);
	
	CApaWindowGroupName* wn=CApaWindowGroupName::NewL(CEikonEnv::Static()->WsSession());
	wn->SetHidden(ETrue);
	wn->SetSystem(ETrue);
	wn->SetWindowGroupName(*iWinGroup);
	delete wn;
	iButton = CAknButton::NewL();
	iButton->ConstructFromResourceL(R_CLOSE_BUTTON);
	iButton->CreateWindowL(iWinGroup);

	TInt scrX=CEikonEnv::Static()->ScreenDevice()->SizeInPixels().iWidth;
	
	TRgb backgroundColour = KRgbWhite; // for example
	if(KErrNone == iButton->Window().SetTransparencyAlphaChannel())
		{backgroundColour.SetAlpha(0);}
	iButton->Window().SetBackgroundColor(backgroundColour);
	
	iButton->SetIconSize(KSize);
	TRect r;
	AknLayoutUtils::LayoutMetricsRect(AknLayoutUtils::EBatteryPane,r);
	iButton->SetRect(TRect ( TPoint(scrX-KSize.iWidth-r.Width()-5,0),KSize));
	iButton->SetObserver(this);
	iButton->MakeVisible(ETrue);
	iButton->ActivateL();
	
	CEikonEnv::Static()->RootWin().SetOrdinalPosition(-4);
	HideApplicationFromFSW(ETrue);
	
	iObserver=CGroupListObserver::NewL(this);
	}

void CTap2CloseAppUi::HandleControlEventL(CCoeControl* aControl,TCoeEvent aEventType)
	{	
	TApaTaskList list(CEikonEnv::Static()->WsSession());
	 switch ( aEventType )
		 {
	        case CAknButton::ELongPressEvent:
	        	{
	        	CEikonEnv::Static()->InfoMsg(_L("long"));
	        	TApaTask task=list.FindByPos(0);
	        	CApaWindowGroupName* wn=CApaWindowGroupName::NewL(CEikonEnv::Static()->WsSession(),CEikonEnv::Static()->WsSession().GetFocusWindowGroup());
	        	if (wn->AppUid().iUid!=KSpbShellUid.iUid&&wn->AppUid().iUid!=KStandbyUid.iUid)
	        		{
	        		if (task.Exists()){task.KillTask();}
	        		}
	        	delete wn;
	        	}
	        	break;
	        case CAknButton::ELongPressEndedEvent:
	        	{
	        	
	        	CEikonEnv::Static()->InfoMsg(_L("long ended"));
	        	}
	        	break;
			case EEventStateChanged:
				{
				CEikonEnv::Static()->InfoMsg(_L("short"));
				TApaTask task=list.FindApp(KSpbShellUid);
				if (task.Exists())
					{task.BringToForeground();}
				else
					{
					TApaTask task=list.FindApp(KStandbyUid);
					if (task.Exists()){task.BringToForeground();}
					}
				}
	        default:
	        	break;
	    }
	 
	}
void CTap2CloseAppUi::ScreenChanged()
	{
		TInt scrX=CEikonEnv::Static()->ScreenDevice()->SizeInPixels().iWidth;
		//iButton->SetIconSize(KSize);
		iButton->SetRect(TRect ( TPoint(scrX-KSize.iWidth,0),KSize));
		iButton->SetPosition( TPoint(scrX-KSize.iWidth,0));
	}
void CTap2CloseAppUi::FocusChanged()
	{
#ifdef _DEBUG
	RDebug::Print(_L("Focus"));
#endif
//	iButton->DrawNow();
	}
