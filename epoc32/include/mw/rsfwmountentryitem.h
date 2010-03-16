/*
* Copyright (c) 2002-2004 Nokia Corporation and/or its subsidiary(-ies).
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
* Description:  Mount entry item definitions
*
*/


#ifndef RSFWMOUNTENTRYITEM_H
#define RSFWMOUNTENTRYITEM_H

// DATA TYPES
enum TMountEntryItemIndex
    {
    EMountEntryItemIndex, // used for positioning the entry
    EMountEntryItemName,
    EMountEntryItemDrive,
    EMountEntryItemUri,
    EMountEntryItemUserName,
    EMountEntryItemPassword,
    EMountEntryItemIap,
    EMountEntryItemInactivityTimeout,
    EMountEntryItemReserved,
    EMountEntryItemCount
    };

#endif // RSFWMOUNTENTRYITEM_H

// End of File
