// Copyright (c) 2000-2009 Nokia Corporation and/or its subsidiary(-ies).
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
// Contains local type declarations for ezlib library
// 
//



/**
 @file
 @publishedAll
 @released
*/

#ifndef _LOCAL_TYPES_H_
#define _LOCAL_TYPES_H_

#include <e32std.h>
#include <e32base.h>

#ifndef NULL
#define NULL 0
#endif

typedef TUint8	TByte;
typedef TUint8 	TUtf8;
typedef TUint32	TOffset;

typedef TText16	TUnicode;

const TInt kNoError = 0;
const TInt kError	= -1;

#endif /* !_LOCAL_TYPES_H_*/
