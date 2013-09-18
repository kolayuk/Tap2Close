/*
========================================================================
 Name        : Tap2CloseDocument.cpp
 Author      : Usanov-Kornilov Nikolay (aka Kolay)
 Copyright   : 
Contacts:
	kolayuk@mail.ru
	http://kolaysoft.ru

(c) KolaySoft, 2010

 Description : 
========================================================================
*/
// [[[ begin generated region: do not modify [Generated User Includes]
#include "Tap2CloseDocument.h"
#include "Tap2CloseAppUi.h"
// ]]] end generated region [Generated User Includes]

/**
 * @brief Constructs the document class for the application.
 * @param anApplication the application instance
 */
CTap2CloseDocument::CTap2CloseDocument( CEikApplication& anApplication )
	: CAknDocument( anApplication )
	{
	}

/**
 * @brief Completes the second phase of Symbian object construction. 
 * Put initialization code that could leave here.  
 */ 
void CTap2CloseDocument::ConstructL()
	{
	}
	
/**
 * Symbian OS two-phase constructor.
 *
 * Creates an instance of CTap2CloseDocument, constructs it, and
 * returns it.
 *
 * @param aApp the application instance
 * @return the new CTap2CloseDocument
 */
CTap2CloseDocument* CTap2CloseDocument::NewL( CEikApplication& aApp )
	{
	CTap2CloseDocument* self = new ( ELeave ) CTap2CloseDocument( aApp );
	CleanupStack::PushL( self );
	self->ConstructL();
	CleanupStack::Pop( self );
	return self;
	}

/**
 * @brief Creates the application UI object for this document.
 * @return the new instance
 */	
CEikAppUi* CTap2CloseDocument::CreateAppUiL()
	{
	return new ( ELeave ) CTap2CloseAppUi;
	}
void CTap2CloseDocument::UpdateTaskNameL( CApaWindowGroupName* aWgName )
  {
  aWgName->SetHidden( ETrue);
  }
				
