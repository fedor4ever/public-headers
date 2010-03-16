// Copyright (c) 2005-2009 Nokia Corporation and/or its subsidiary(-ies).
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

#ifndef __CALCHANGECALLBACK_H__
#define __CALCHANGECALLBACK_H__

#include <calcommon.h>

class TCalChangeEntry;

class MCalChangeCallBack
/** A call back class for observing changes in the model view.

A client will not be notified of a change if it is the source of
the change.

@publishedAll
@deprecated
*/
	{
public:
	/** Instance view change type
	@publishedAll
	@deprecated
	*/
	enum TChangeType
		{
		/**	Entries are added */
		EChangeAdd,
		/** Entries are deleted */
		EChangeDelete,
		/** Entries are modified */
		EChangeModify,
		/** Undefined entries */
		EChangeUndefined,
		/** Entries cause overflow error */
		EChangeOverflowError
		};

	/** Instance view entry type
	@publishedAll
	@deprecated
	*/
	enum TChangeEntryType
		{
		/** Entry type is todo */
		EChangeEntryTodo,
		/** Entry type is event */
		EChangeEntryEvent,
		/** All entry types */
		EChangeEntryAll
		};
	/** A call back function for change notification
	@param aChangeEntryType Filters notifications to only notify about entries of this type (event/todo/all).

	*/
	virtual void CalChangeNotification(TChangeEntryType aChangeEntryType) = 0;
	};

/** A call back class for observing changes in the model view.

The call back returns an array containing information about at least
one change to the database. The information includes the type of change
and the identity of the item being changed.

A client will not be notified of a change if it is the source of
the change.

@publishedAll
@released
*/
class MCalChangeCallBack2
	{
public:
	/** Instance view change type
	@publishedAll
	@released
	*/
	enum TChangeType
		{
		/**	Entries are added */
		EChangeAdd,
		/** Entries are deleted */
		EChangeDelete,
		/** Entries are modified */
		EChangeModify,
		/** Undefined entries */
		EChangeUndefined
		};

	/** Instance view entry type
	@publishedAll
	@released
	*/
	enum TChangeEntryType
		{
		/** Entry type is todo */
		EChangeEntryTodo,
		/** Entry type is event */
		EChangeEntryEvent,
		/** All entry types */
		EChangeEntryAll
		};
	/** A call back function for change notification
	@param aChangeItems  List of changes since the last notification.

	*/
	virtual void CalChangeNotification(RArray<TCalChangeEntry>& aChangeItems) = 0;
	};

/** Struct for storing change notification data.
This contains the calendar local ID, the type of change and the entry type.

The iChangeType will only be set to EChangeEntryTodo or EChangeEntryEvent
values. EChangeEntryAll is provided for callback registration only.

If iChangeType is EChangeUndefined or EChangeOverflowError, iEntryId and
iEntryType are undefined and should not be used by clients.

@publishedAll
@released
*/
struct TCalChangeEntry
	{
	/** Local UID of the entry */
	TCalLocalUid iEntryId;
	/** Type of change to the entry */
	MCalChangeCallBack2::TChangeType iChangeType;
	/** Type of entry */
	MCalChangeCallBack2::TChangeEntryType iEntryType;
	};

/** Class to encapsulate call back registration parameters.

The type of entries, the date range and whether undated todos are included
can be specified.

@publishedAll
@released
*/
class CCalChangeNotificationFilter
	{
public:
	IMPORT_C static CCalChangeNotificationFilter* NewL(MCalChangeCallBack2::TChangeEntryType aChangeEntryType, TBool aIncludeUndatedTodos, const CalCommon::TCalTimeRange& aTimeRange);
	IMPORT_C ~CCalChangeNotificationFilter();

	MCalChangeCallBack2::TChangeEntryType ChangeEntryType() const;
	TCalTime StartTime() const;
	TCalTime EndTime() const;
	TBool IncludeUndatedTodos() const;

private:
	CCalChangeNotificationFilter(MCalChangeCallBack2::TChangeEntryType aChangeEntryType, TBool aIncludeUndatedTodos, const CalCommon::TCalTimeRange& aTimeRange);

	MCalChangeCallBack2::TChangeEntryType iChangeEntryType;
	CalCommon::TCalTimeRange iTimeRange;
	TBool iIncludeUndatedTodos;
	};

#endif // __CALCHANGECALLBACK_H__
