/*
* Copyright (c) 2006-2009 Nokia Corporation and/or its subsidiary(-ies).
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
* Name        : pls.h
* Part of     : Client API for ewsd library
* Contains the client API for using the emulator WSD library
* Redistribution and use in source and binary forms, with or without 
* modification, are permitted provided that the following conditions are met:
* Redistributions of source code must retain the above copyright notice, this 
* list of conditions and the following disclaimer. 
* Redistributions in binary form must reproduce the above copyright notice, 
* this list of conditions and the following disclaimer in the documentation 
* and/or other materials provided with the distribution. 
* Neither the name of the <ORGANIZATION> nor the names of its contributors 
* may be used to endorse or promote products derived from this software 
* without specific prior written permission. 
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE 
* DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE
* FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL 
* DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR 
* SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER 
* CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
* OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
* OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
*/


 
#ifndef __PLS_H__
#define __PLS_H__

#ifdef __WINSCW__
 
#include <ewsd.h>

// Panic strings
_LIT(KVirtualAllocFailure, "WSD VirtualAlloc() failed");
_LIT(KPLSInitFailed, "WSD PLS init failed");
_LIT(KWsdArrayFull, "WSD process or lib array full");	

/**  
A templated function that is used by a library (DLL) that requires to use
WSD on the emulator.
The function returns the PLS (Process Local Storage) object of the specified library, 
for the current process. If the PLS object doesn't yet exist then it is allocated, 
initialised, stored and returned.
The template type T is the type of the PLS object, and is supplied by the caller.

Takes as a parameter the TUid of the library DLL whose PLS is to be returned for the 
current process. It also takes as a parameter a pointer to a (non-leaving, non-panicing) 
initialisation function defined by the caller which takes a pointer to T (i.e. the 
PLS object) as a parameter and returns one of the system wide error codes as a TInt.
This parameter is optional but it should be used when necessary to ensure that if Pls() 
requires to create a PLS object then the object is completely initialised on its return. 
The initialisation function is called after the PLS object has been allocated and its 
constructor called if it is an instance of a class - neither the constructor nor the 
initialisation function should call Pls().

Returns a pointer to the PLS object					
*/
template <typename T>
T* Pls(const TUid& aLibraryUid, TInt (*aInitFunc)(T*) = 0)
	{
	// Fetch the PLS, if it has been set
	T* p = (T*) CheckPls(aLibraryUid);
	if (p)
		{
		return p;
		}
	
	// Obtain ownership of the mutex
	TAny* mutexHandle = ObtainPlsMutex(); 
			
	// Check we haven't obtained the mutex from 
	// another thread that has just set the same PLS!
	p = (T*) CheckPls(aLibraryUid);
	if (p) 
		{
		ReleasePlsMutex(mutexHandle);				
		return p;
		}
	
	// Allocate the memory for the PLS object
	p = (T*) AllocatePls(sizeof(T));
	if (!p)
		{
		ReleasePlsMutex(mutexHandle);
		User::Panic(KVirtualAllocFailure, KErrNoMemory);
		}
			
	// Do a placement new to construct the PLS object in the allocated memory
	p = new (p) T;
	
	// Call the initialisation function (if one is provided)
	// to complete initialisation of the PLS object
	if (aInitFunc)
		{
		 if (((*aInitFunc)(p)) != KErrNone) 
		 	{
		 	 FreePls(p);			
			 ReleasePlsMutex(mutexHandle);
			 User::Panic(KPLSInitFailed, KErrGeneral);
		 	}
		}
		
	// Finally, call SetPls() to store the PLS object.
	// NOTE: This step is last to ensure that a PLS object returned by 
	// CheckPls() is completely constructed/initialised. This is important 
	// to handle the scenario in which the thread that is creating the PLS 
	// object is interrupted by another call to Pls() by another thread
	if (SetPls(p, aLibraryUid) != KErrNone)
		{
		// SetPls() failed due to a size limit being reached in the wsdArray
		FreePls(p);
		ReleasePlsMutex(mutexHandle);
		User::Panic(KWsdArrayFull, KErrNoMemory);				
		}

	ReleasePlsMutex(mutexHandle);		
	return p;
	}

#endif // __WINSCW__

#endif // __PLS_H__

