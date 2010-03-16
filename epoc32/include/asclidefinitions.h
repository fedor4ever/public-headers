// Copyright (c) 1999-2009 Nokia Corporation and/or its subsidiary(-ies).
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

#ifndef __ASCLIDEFINITIONS_H__
#define __ASCLIDEFINITIONS_H__

// System includes
#include <e32base.h>

// User includes

// Type definitions

// Constants

// Enumerations


///////////////////////////////////////////////////////////////////////////////////////
// ----> ASCliDefinitions (header)
///////////////////////////////////////////////////////////////////////////////////////
class ASCliDefinitions
/** This is a utility class that retrieves the name and version number of the alarm 
server. 
@publishedAll
@released
*/
	{
///////////////////////////////////////////////////////////////////////////////////////
public:										// STATIC ACCESS METHODS
///////////////////////////////////////////////////////////////////////////////////////

	IMPORT_C static const TDesC&			ServerAndThreadName();

	static const TDesC&						ServerImageName();

	static TUidType							ServerUidType();

	static TVersion							Version();

	};

#endif
