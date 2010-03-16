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

#ifndef __XMLFRAMEWORKCONSTANTS_H__
#define __XMLFRAMEWORKCONSTANTS_H__

#include <e32std.h>

namespace Xml
{
/**
Indicates the String Dictionary interface uid that ECom uses to locate the appropriate plugin.
@publishedPartner
@released
*/
const TUid KStringDictionaryInterfaceUid	= {0x101FA94F};

/**
Indicates the Parser interface uid that ECom uses to locate the appropriate plugin.

@publishedPartner
@released
*/
const TUid KParserInterfaceUid				= {0x101FAA0B};

/**
Indicates the Generator interface uid that ECom uses to locate the appropriate plugin.

@publishedPartner
@released
*/
const TUid KGeneratorInterfaceUid			= {0x101FD284};

}

#endif //__XMLFRAMEWORKCONSTANTS_H__
