/*
* Copyright (c) 2005-2009 Nokia Corporation and/or its subsidiary(-ies). 
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
* @file
* This contains TestBlockController.inl
* This contains CTestBlockController inline methods
*
*/


/**
 @prototype
 @test
*/
#ifndef __TEST_BLOCK_CONTROLLER_INL_
#define __TEST_BLOCK_CONTROLLER_INL_

/**
 * Increment the number of active async operations
 */
inline void	CTestBlockController::IncAsyncCount() { ++iAsyncCount; }

/**
 * Decrement the number of active async operations
 */
inline void	CTestBlockController::DecAsyncCount() { --iAsyncCount; }

#endif // __TEST_BLOCK_CONTROLLER_INL_
