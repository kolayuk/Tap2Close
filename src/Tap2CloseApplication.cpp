/*
========================================================================
 Name        : Tap2CloseApplication.cpp
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
// ]]] end generated region [Generated System Includes]

// [[[ begin generated region: do not modify [Generated Includes]
#include "Tap2CloseApplication.h"
#include "Tap2CloseDocument.h"
#ifdef EKA2
#include <eikstart.h>
#endif
// ]]] end generated region [Generated Includes]

/**
 * @brief Returns the application's UID (override from CApaApplication::AppDllUid())
 * @return UID for this application (KUidTap2CloseApplication)
 */
TUid CTap2CloseApplication::AppDllUid() const
	{
	return KUidTap2CloseApplication;
	}

/**
 * @brief Creates the application's document (override from CApaApplication::CreateDocumentL())
 * @return Pointer to the created document object (CTap2CloseDocument)
 */
CApaDocument* CTap2CloseApplication::CreateDocumentL()
	{
	return CTap2CloseDocument::NewL( *this );
	}

#ifdef EKA2

/**
 *	@brief Called by the application framework to construct the application object
 *  @return The application (CTap2CloseApplication)
 */	
LOCAL_C CApaApplication* NewApplication()
	{
	return new CTap2CloseApplication;
	}

/**
* @brief This standard export is the entry point for all Series 60 applications
* @return error code
 */	
GLDEF_C TInt E32Main()
	{
	return EikStart::RunApplication( NewApplication );
	}
	
#else 	// Series 60 2.x main DLL program code

/**
* @brief This standard export constructs the application object.
* @return The application (CTap2CloseApplication)
*/
EXPORT_C CApaApplication* NewApplication()
	{
	return new CTap2CloseApplication;
	}

/**
* @brief This standard export is the entry point for all Series 60 applications
* @return error code
*/
GLDEF_C TInt E32Dll(TDllReason /*reason*/)
	{
	return KErrNone;
	}

#endif // EKA2
