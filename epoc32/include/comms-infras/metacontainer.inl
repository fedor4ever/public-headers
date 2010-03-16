/**
* Copyright (c) 2004-2009 Nokia Corporation and/or its subsidiary(-ies).
* All rights reserved.
* This component and the accompanying materials are made available
* under the terms of the License "Symbian Foundation License v1.0" to Symbian Foundation members and "Symbian Foundation End User License Agreement v1.0" to non-members
* which accompanies this distribution, and is available
* at the URL "http://www.symbianfoundation.org/legal/licencesv10.html".
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
 @file MetaContainer.inl
 @internalTechnology
*/

#ifndef __METACONTAINER_INL__
#define __METACONTAINER_INL__

namespace Meta
{

template<class ELEMENT>
RMetaDataContainer<ELEMENT>* RMetaDataContainer<ELEMENT>::LoadL(TPtrC8& aDes)
/**
 * This function instantiates a container of meta objects and loads its content
 * from a descriptor.
 */
    {
    RMetaDataContainer<ELEMENT>* cont = new (ELeave) RMetaDataContainer<ELEMENT>;
	User::LeaveIfError(cont->Load(aDes));
	return cont;
    }

template<class ELEMENT>
inline RMetaDataContainer<ELEMENT>::RMetaDataContainer()
/**
 * Constructor
 */
	{
	}

template<class ELEMENT>
SMetaData* RMetaDataContainer<ELEMENT>::LoadElementL(TPtrC8& aDes)
/**
 * This helper function instantiates a single meta object (element) and loads
 * its content from a descriptor.
 */
	{
	return ELEMENT::LoadL(aDes);
	}

}	// namespace Meta
#endif	// __METACONTAINER_INL__
