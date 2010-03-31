/*
* Copyright (c) 2004-2009 Nokia Corporation and/or its subsidiary(-ies).
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
* Name        : siprefertoheader.h
* Part of     : SIP Codec
* Interface   : SDK API, SIP Codec API
* Version     : SIP/4.0 
*
*/




#ifndef CSIPREFERTOHEADER_H
#define CSIPREFERTOHEADER_H

//  INCLUDES
#include "sipaddressheaderbase.h"

// FORWARD DECLARATIONS
class CSIPAddress;
class CSIPHeaderGenericParams;

// CLASS DECLARATION
/**
* @publishedAll
* @released
*
* Class provides functions for setting and getting parameters in SIP 
* "Refer-To" header.
*
*  @lib sipcodec.lib
*/
class CSIPReferToHeader : public CSIPAddressHeaderBase
	{
	public:	// Constructors and destructor

		/**
		* Constructs a CSIPReferToHeader from textual representation 
		* of the header's value part.
		* @param aValue a value part of a "Refer-To"-header 
		*        (e.g. "User <user@host>")
		* @return a new instance of CSIPReferToHeader   
		*/
		IMPORT_C static CSIPReferToHeader* DecodeL(const TDesC8& aValue);

		/**
		* Creates a new instance of CSIPReferToHeader
		* @pre aSIPAddress != 0
		* @param aSIPAddress a name-address, the ownership is transferred.
		* @return a new instance of CSIPReferToHeader
		*/
		IMPORT_C static CSIPReferToHeader* NewL(CSIPAddress* aSIPAddress);

		/**
		* Creates a new instance of CSIPReferToHeader and puts it to CleanupStack
		* @pre aSIPAddress != 0
		* @param aSIPAddress a name-address, the ownership is transferred,
		* @return a new instance of CSIPReferToHeader
		*/
		IMPORT_C static CSIPReferToHeader* NewLC(CSIPAddress* aSIPAddress);

		/**
		* Destructor, deletes the resources of CSIPReferToHeader.
		*/
		IMPORT_C virtual ~CSIPReferToHeader();


	public: // New functions

		/**
		* Constructs an instance of a CSIPReferToHeader from a RReadStream
		* @param aReadStream a stream containing the value of the
		*        externalized object (header name not included). 
		* @return an instance of a CSIPReferToHeader
		*/
		IMPORT_C static CSIPHeaderBase* InternalizeValueL(RReadStream& aReadStream);


	public: // From CSIPHeaderBase

		/**
		* From CSIPHeaderBase CloneL
		*/
		IMPORT_C CSIPHeaderBase* CloneL() const;

		/**
		* From CSIPHeaderBase Name
		*/
		IMPORT_C RStringF Name() const;


	public: // From CSIPHeaderBase, for internal use

        /**
        * @internalComponent
        */
		TBool HasCompactName() const;
		
        /**
        * @internalComponent
        */		
		RStringF CompactName() const;
		
        /**
        * @internalComponent
        */		
		TPreferredPlace PreferredPlaceInMessage() const;

	public: // New functions, for internal use

		static RPointerArray<CSIPHeaderBase> BaseDecodeL(const TDesC8& aValue);

	private: // Constructors

		CSIPReferToHeader();

    private: // For testing purposes
#ifdef CPPUNIT_TEST	
		friend class CSIPReferToHeaderTest;
#endif
	};

#endif // end of CSIPREFERTOHEADER_H

// End of File
