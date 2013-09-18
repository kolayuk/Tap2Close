/*
========================================================================
 Name        : Tap2CloseApplication.h
 Author      : Usanov-Kornilov Nikolay (aka Kolay)
 Copyright   : 
Contacts:
	kolayuk@mail.ru
	http://kolaysoft.ru

(c) KolaySoft, 2010

 Description : 
========================================================================
*/
#ifndef TAP2CLOSEAPPLICATION_H
#define TAP2CLOSEAPPLICATION_H

// [[[ begin generated region: do not modify [Generated Includes]
#include <aknapp.h>
// ]]] end generated region [Generated Includes]

// [[[ begin generated region: do not modify [Generated Constants]
const TUid KUidTap2CloseApplication = { 0xE18A2A40 };
// ]]] end generated region [Generated Constants]

/**
 *
 * @class	CTap2CloseApplication Tap2CloseApplication.h
 * @brief	A CAknApplication-derived class is required by the S60 application 
 *          framework. It is subclassed to create the application's document 
 *          object.
 */
class CTap2CloseApplication : public CAknApplication
	{
private:
	TUid AppDllUid() const;
	CApaDocument* CreateDocumentL();
	
	};
			
#endif // TAP2CLOSEAPPLICATION_H		
