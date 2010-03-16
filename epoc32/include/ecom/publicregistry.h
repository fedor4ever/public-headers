// Copyright (c) 1997-2009 Nokia Corporation and/or its subsidiary(-ies).
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
// The interface definition for the MPublicRegistry class
// 
//



#ifndef __PUBLICREGISTRY_H__
#define __PUBLICREGISTRY_H__

#include <ecom/implementationinformation.h>

/**
Provides access to the public functions of CRegistryData for CResolver 
implementations.

@publishedAll
@released
*/

class MPublicRegistry
	{
public:
	/**
	Intended Usage	: Provides a list of the implementations which satisfy the 
					interface uid specified.
	@leave  		Depends on implementation.
	@since			7.0
	@return			None.
	@pre 			This object is fully constructed.
 	*/
	
	virtual RImplInfoArray& ListImplementationsL(TUid aInterfaceUid) const = 0 ;

	};

#endif // __PUBLICREGISTRY_H__
