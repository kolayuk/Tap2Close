/*
========================================================================
 Name        : Tap2CloseDocument.h
 Author      : Usanov-Kornilov Nikolay (aka Kolay)
 Copyright   : 
Contacts:
	kolayuk@mail.ru
	http://kolaysoft.ru

(c) KolaySoft, 2010

 Description : 
========================================================================
*/
#ifndef TAP2CLOSEDOCUMENT_H
#define TAP2CLOSEDOCUMENT_H

#include <akndoc.h>
		
class CEikAppUi;

/**
* @class	CTap2CloseDocument Tap2CloseDocument.h
* @brief	A CAknDocument-derived class is required by the S60 application 
*           framework. It is responsible for creating the AppUi object. 
*/
class CTap2CloseDocument : public CAknDocument
	{
public: 
	// constructor
	static CTap2CloseDocument* NewL( CEikApplication& aApp );

private: 
	// constructors
	CTap2CloseDocument( CEikApplication& aApp );
	void ConstructL();
public: 
	// from base class CEikDocument
	CEikAppUi* CreateAppUiL();
	void UpdateTaskNameL( CApaWindowGroupName* aWgName );
	};
#endif // TAP2CLOSEDOCUMENT_H
