/*
========================================================================
 Name        : Tap2CloseAppUi.h
 Author      : Usanov-Kornilov Nikolay (aka Kolay)
 Copyright   : 
Contacts:
	kolayuk@mail.ru
	http://kolaysoft.ru

(c) KolaySoft, 2010

 Description : 
========================================================================
*/
#ifndef TAP2CLOSEAPPUI_H
#define TAP2CLOSEAPPUI_H

//#define TAP2CLOSE

// [[[ begin generated region: do not modify [Generated Includes]
#include <aknviewappui.h>
// ]]] end generated region [Generated Includes]

// [[[ begin generated region: do not modify [Generated Forward Declarations]
class CMainView;
// ]]] end generated region [Generated Forward Declarations]
#include <aknbutton.h>
#include <w32std.h>
#include <GroupListObserver.h>
/**
 * @class	CTap2CloseAppUi Tap2CloseAppUi.h
 * @brief The AppUi class handles application-wide aspects of the user interface, including
 *        view management and the default menu, control pane, and status pane.
 */
class CTap2CloseAppUi : public CAknViewAppUi, public MCoeControlObserver, public MGroupListCallBack
	{
public:
	// constructor and destructor
	CTap2CloseAppUi();
	virtual ~CTap2CloseAppUi();
	void ConstructL();
	CAknButton* iButton;
	RWindowGroup* iWinGroup;
	CGroupListObserver* iObserver;
	void ScreenChanged();
	void FocusChanged();
	//From MCoeControlObserver
	virtual void HandleControlEventL(CCoeControl* aControl,TCoeEvent aEventType);
public:
	// from CCoeAppUi
	TKeyResponse HandleKeyEventL(
				const TKeyEvent& aKeyEvent,
				TEventCode aType );

	// from CEikAppUi
	void HandleCommandL( TInt aCommand );
	void HandleResourceChangeL( TInt aType );

	// from CAknAppUi
	void HandleViewDeactivation( 
			const TVwsViewId& aViewIdToBeDeactivated, 
			const TVwsViewId& aNewlyActivatedViewId );

private:
	void InitializeContainersL();
	// [[[ begin generated region: do not modify [Generated Methods]
public: 
	// ]]] end generated region [Generated Methods]
	
	// [[[ begin generated region: do not modify [Generated Instance Variables]
private: 
	CMainView* iMainView;
	// ]]] end generated region [Generated Instance Variables]
	
	
	// [[[ begin [User Handlers]
protected: 
	// ]]] end [User Handlers]
	
	};

#endif // TAP2CLOSEAPPUI_H			
