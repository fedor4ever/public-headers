// Copyright (c) 2004-2009 Nokia Corporation and/or its subsidiary(-ies).
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
// MetaBuffer.h
// 
//



/**
 @file MetaBuffer.h
 @internalTechnology
*/

#if (!defined METABUFFER_H)
#define METABUFFER_H

#include <comms-infras/metatypevariablelen.h>

namespace Meta
{

class TMetaBuf8 : public TMetaVarLen8<RBuf8>
/**

Implementation of MMetaType for dynamicaly allocated RBuf8

@internalComponent
@released since v9.0
*/
	{
public:
	inline static MMetaType* NewL(const TAny* aMem, const TAny* aData);

	IMPORT_C virtual TInt Load(TPtrC8& aBuffer);
	IMPORT_C virtual TInt Store(TDes8& aBuffer) const;
	IMPORT_C virtual void Copy(const TAny* aData);
	IMPORT_C virtual TInt Length() const;

protected:
	TMetaBuf8(const TAny* aData) :
		TMetaVarLen8<RBuf8>( aData )
		{
		}
	};

class TMetaBuf16 : public TMetaVarLen16<RBuf16>
/**

Implementation of MMetaType for dynamicaly allocated RBuf16

@internalComponent
@released since v9.0
*/
	{
public:
	inline static MMetaType* NewL(const TAny* aMem, const TAny* aData);

	IMPORT_C virtual TInt Load(TPtrC8& aBuffer);
	IMPORT_C virtual TInt Store(TDes8& aBuffer) const;
	IMPORT_C virtual void Copy(const TAny* aData);
	IMPORT_C virtual TInt Length() const;

protected:
	TMetaBuf16(const TAny* aData) :
		TMetaVarLen16<RBuf16>( aData )
		{
		}

	};

MMetaType* TMetaBuf8::NewL(const TAny* aMem, const TAny* aData)
/**
 * Instantiates a meta type for RBuf8.
 * Used for attribure registration (in the data v-table).
 */
    {
    return ::new ((TUint8*)aMem) TMetaBuf8(aData);
    }

MMetaType* TMetaBuf16::NewL(const TAny* aMem, const TAny* aData)
/**
 * Instantiates a meta type for RBuf8.
 * Used for attribure registration (in the data v-table).
 */
    {
    return ::new ((TUint8*)aMem) TMetaBuf16(aData);
    }


#if defined(_UNICODE)
typedef TMetaBuf16 TMetaBuf;
#else
typedef TMetaBuf8 TMetaBuf;
#endif
} //namespace Meta


#endif //METABUFFER_H
