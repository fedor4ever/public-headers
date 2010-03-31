/*
* Copyright (c) 2007-2009 Nokia Corporation and/or its subsidiary(-ies).
* All rights reserved.
* This component and the accompanying materials are made available
* under the terms of "Eclipse Public License v1.0"
* which accompanies this distribution, and is available
* at the URL "http://www.eclipse.org/legal/epl-v10.html".
*
* Initial Contributors:
* Nokia Corporation - initial contribution.
*
* Contributors:
*
* Description:
* Name          : sipauthorizationheaderbase.h
* Part of       : SIP Codec
* Version       : SIP/6.0 
*
*/



#ifndef CSIPAUTHORIZATIONHEADERBASE_H
#define CSIPAUTHORIZATIONHEADERBASE_H

//  INCLUDES
#include "sipauthheaderbase.h"

// FORWARD DECLARATIONS
class CSIPAuthorizationHeaderParams;

// CLASS DECLARATION
/**
* @publishedAll
* @released
*
* A base class for SIP Authorization- and Proxy-Authorization-headers
* @lib sipcodec.lib
*/
class CSIPAuthorizationHeaderBase : public CSIPAuthHeaderBase
	{
	public: // Constructors and destructor

		/**
		* Destructor.
		*/
		IMPORT_C virtual ~CSIPAuthorizationHeaderBase();

	protected: // Constructors

		CSIPAuthorizationHeaderBase();
		void ConstructL();
		void ConstructL(const CSIPAuthorizationHeaderBase& aHeader);

	protected: // From CSIPAuthHeaderBase

		const CSIPParamContainerBase& Params() const;
		CSIPParamContainerBase& Params();

    protected: // New functions

		void DoInternalizeValueL(RReadStream& aReadStream);

    protected: // Data

		CSIPAuthorizationHeaderParams* iParams;
	};

#endif // CSIPAUTHORIZATIONHEADERBASE_H

// End of File
