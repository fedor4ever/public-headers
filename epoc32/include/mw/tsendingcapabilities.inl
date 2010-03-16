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
* Description:   Sending capabilities for sending services. Used by SendUi to
*                filter sending services from "Send" pop-up list query.
*
*/



// ============================ MEMBER FUNCTIONS ===============================

inline TSendingCapabilities TSendingCapabilities::CapabilitiesForAllServices()
    {
    TSendingCapabilities capabilities = 
        TSendingCapabilities( 0, 0, EAllServices );

    return capabilities;
    }
            
// End of File
