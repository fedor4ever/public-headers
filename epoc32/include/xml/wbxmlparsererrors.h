// Copyright (c) 2003-2009 Nokia Corporation and/or its subsidiary(-ies).
// All rights reserved.
// This component and the accompanying materials are made available
// under the terms of the License "Symbian Foundation License v1.0" to Symbian Foundation members and "Symbian Foundation End User License Agreement v1.0" to non-members
// which accompanies this distribution, and is available
// at the URL "http://www.symbianfoundation.org/legal/licencesv10.html".
//
// Initial Contributors:
// Nokia Corporation - initial contribution.
//
// Contributors:
//
// Description:
//

#ifndef __WBXMLPARSERERRORS_H__
#define __WBXMLPARSERERRORS_H__

/**
@file

This file contains WBXML Parser panic errors and the Panic function

@internalTechnology
*/

#include <e32base.h>

enum TWbxmlParserError
	{
	/**
	Indicates that a leave code other than that expected was received.
	*/
	EWbxmlParserErrorUnexpectedLeaveCode		= 7000,

	/**
	Indicates that a state other than that expected was reached.
	*/
	EWbxmlParserErrorUnexpectedState			= 7001,

	/**
	Indicates that logic other than that expected was reached.
	*/
	EWbxmlParserErrorUnexpectedLogic			= 7002,

	};


void Panic(TWbxmlParserError aError);


#endif // __WBXMLPARSERERRORS_H__
