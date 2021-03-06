/*
* Copyright (c) 2001-2009 Nokia Corporation and/or its subsidiary(-ies).
* All rights reserved.
* This component and the accompanying materials are made available
* under the terms of the License "Eclipse Public License v1.0"
* which accompanies this distribution, and is available
* at the URL "http://www.eclipse.org/legal/epl-v10.html".
*
* Initial Contributors:
* Nokia Corporation - initial contribution.
*
* Contributors:
*
* Description: 
*
*/


/**
 @file
 @publishedAll
 @released    
*/

#ifndef __TCTALLTOKENTYPES_H__
#define __TCTALLTOKENTYPES_H__

#include <ct/mcttokentypefilter.h>


/**
 * A filter that includes all token types.
 *
 * Used by CCTTokenTypeInfo::ListL()
 *
 *  @see MCTTokenTypeFilter. 
 */
class TCTAllTokenTypes : public MCTTokenTypeFilter
	{
 public:
	/** 
	 * Tests whether to accept all token types.
	 *
	 * Note that it always returns ETrue.
	 * 
	 * @param aTokenType	The token type to be tested.
	 * @return				ETrue always. 
	 */
	IMPORT_C virtual TBool Accept(const CCTTokenTypeInfo& aTokenType) const;
	};

#endif // __TCTALLTOKENTYPES_H__
