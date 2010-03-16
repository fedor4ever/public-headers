// Copyright (c) 2008-2009 Nokia Corporation and/or its subsidiary(-ies).
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



/**
 @file
 @publishedAll
 @released
*/

#ifndef REMCONGROUPNAVIGATIONTARGET_H
#define REMCONGROUPNAVIGATIONTARGET_H

#include <e32base.h>
#include <s32mem.h>
#include <remconcoreapi.h>
#include <remcon/avrcpspec.h>

#include <remcon/remcongroupnavigation.h>
#include <remcon/remconinterfacebase.h>
#include <remcon/remconinterfaceif.h>

class MRemConGroupNavigationTargetObserver;
class CRemConInterfaceSelector;

/**
Client-instantiable type supporting sending Battery Status responses.
*/
NONSHARABLE_CLASS(CRemConGroupNavigationApiTarget) : public CRemConInterfaceBase, 
								          		public MRemConInterfaceIf
	{
public:
	/**
	Factory function.
	@see CRemConInterfaceSelector
	@param aInterfaceSelector The interface selector. The client must have 
	created one of these first.
	@param aObserver The observer of this interface.
	@return A new CRemConGroupNavigationApiTarget, owned by the interface selector.
	*/
	IMPORT_C static CRemConGroupNavigationApiTarget* NewL(CRemConInterfaceSelector& aInterfaceSelector, 
		MRemConGroupNavigationTargetObserver& aObserver);
	
	/** Destructor */
	IMPORT_C ~CRemConGroupNavigationApiTarget();

public:
	/** Send a 'next group' response.
	Called by the client after receiving a MRemConGroupNavigationTargetObserver::MrcgntoNextGroup().
	@param aStatus Used by RemCon to indicate completion of the send request.
	aStatus may be NULL if no completion indication required.
	@param aError The response error.
	*/
	IMPORT_C void NextGroupResponse(TRequestStatus*& aStatus, TInt aError);

	/** Send a 'previous group' response.
	Called by the client after receiving a MRemConGroupNavigationTargetObserver::MrcgntoPreviousGroup().
	@param aStatus Used by RemCon to indicate completion of the send request.
	aStatus may be NULL if no completion indication required.
	@param aError The response error.
	*/
	IMPORT_C void PreviousGroupResponse(TRequestStatus*& aStatus, TInt aError);

private:
	/** 
	Constructor.
	@param aInterfaceSelector The interface selector.
	@param aObserver The observer of this interface.
	*/
	CRemConGroupNavigationApiTarget(CRemConInterfaceSelector& aInterfaceSelector, 
		MRemConGroupNavigationTargetObserver& aObserver);

	void SendGroupResponse(TGroupNavigationPassthroughOperationIds aId, TRequestStatus*& aStatus, TInt aError);

	void ConstructL();

private: // from CRemConInterfaceBase
	TAny* GetInterfaceIf(TUid aUid);

private: // from MRemConInterfaceIf
	void MrcibNewMessage(TUint aOperationId, const TDesC8& aData);

private: // unowned
	MRemConGroupNavigationTargetObserver& iObserver;

private: // owned
	CBufFlat*		iOutData;
	TPtr8			iPtr;
	RBufWriteStream iStream;
			
	};

#endif // REMCONGROUPNAVIGATIONTARGET_H
