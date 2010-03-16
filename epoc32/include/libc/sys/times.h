/*
* Copyright (c) 1997-2009 Nokia Corporation and/or its subsidiary(-ies).
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





#ifndef	_SYS_TIMES_H
#define	_SYS_TIMES_H
#ifdef __cplusplus
extern "C" {
#endif

#include <_ansi.h>
#include <machine/types.h>
/**
@publishedAll
@released
*/
#ifndef __clock_t_defined
typedef _CLOCK_T_ clock_t;
#define __clock_t_defined
#endif
/**
@publishedAll
@released
*/
struct tms {
	clock_t	tms_utime;		/* user time */
	clock_t	tms_stime;		/* system time */
	clock_t	tms_cutime;		/* user time, children */
	clock_t	tms_cstime;		/* system time, children */
};
/**
@publishedAll
@released
*/
extern clock_t times(struct tms *);

#ifdef __cplusplus
}
#endif
#endif	/* !_SYS_TIMES_H */
