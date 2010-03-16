/*
* Copyright (c) 2002-2006 Nokia Corporation and/or its subsidiary(-ies).
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


#if !defined(__AKNDLGSHUT_H__)
#define __AKNDLGSHUT_H__

#include <e32std.h>


// FORWARD DECLARATIONS
class CEikonEnv;

/**
* Utility class for shutting dialogs
*/
class AknDialogShutter
	{
public:
    /**
    * Shut all open dialogs.
    * This stops either when all open dialogs and menus are closed
    * or when another dialog, such as a confirmation dialog is launched.
    * @param aEikEnv the CEikonEnv instance for this app.
    */
	IMPORT_C static void ShutDialogsL(CEikonEnv& aEikEnv);

private:
	static TInt StartLevel();
	};

#endif
