// Copyright (c) 2007-2009 Nokia Corporation and/or its subsidiary(-ies).
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
// This is the public client API for the Image Transform Library
// 
//
/**
 @file
 @publishedAll
 @released
*/

#ifndef __IMAGETRANSFORM_H__
#define __IMAGETRANSFORM_H__

#include <e32base.h>
#include <fbs.h>

// fwd refs
class CImageTransformFramework;	//fwd ref
class CImageTransformPluginExtension;

/**
The public API for clients to call the Image Transform (scaling) library.
This class provides functions to scale images held in files or descriptors.

@publishedAll
@released
*/
class CImageTransform : public CBase
	{
public:
	/**
	Flags to control how the image is transformed.
	The EThumbnail and EIgnoreExifMetadataProcessing are mutually exclusive,
	and SHOULD NOT be used together. If they are, then EThumbnail is used.
	*/
	enum TOptions
		{
		/** No flag set. This is the default option*/
		EOptionNone = 0x00,
		/** If set, the destination image will always have a thumbnail.
		If the source already has a thumbnail, then this is the one that will appear
		in the destination, otherwise one will be generated. */
		EThumbnail	= 0x01,
		/** If set, then the Exif data is not parsed and ExifMetaData() will always return NULL. If the source image is EXIF, 
		then the EXIF information is copied without modification (i.e. without parsing) to the destination. In cases where 
		the source is JFIF, the destination image is also JFIF.
		*/
		EIgnoreExifMetadataProcessing = 0x02,
		/**
		TOptions should not be set greater than or equal to this value.
		*/
		EEnumBoundary = 0x04
		};

public:
	IMPORT_C static CImageTransform* NewL(RFs& aFs);
	IMPORT_C ~CImageTransform();
	IMPORT_C void SetPluginUidL(TUid aPluginUid);
	IMPORT_C void SetSourceFilenameL(const TDesC& aFilename);
	IMPORT_C void SetSourceDataL(const TDesC8& aData);
	IMPORT_C void SetSourceMimeTypeL(const TDesC8& aMIMEType);
	IMPORT_C void SetSourceImageTypeL(TUid aImageType, TUid aImageSubType = KNullUid);
	IMPORT_C void SetSourceRect(const TRect& aRect);
	IMPORT_C void ClearSourceRect();

	IMPORT_C void SetDestFilenameL(const TDesC& aFilename);
	IMPORT_C void SetDestDataL(HBufC8*& aData);
	IMPORT_C void SetDestSizeInPixelsL(const TSize& aDestinationSize, TBool aMaintainAspectRatio = ETrue);

	IMPORT_C void SetOptionsL(TUint aOptions);
	IMPORT_C void SetPreserveImageData(TBool aPreserveImageData);

	IMPORT_C void SetupL();
	IMPORT_C void Transform(TRequestStatus& aStatus);
	IMPORT_C void CancelTransform();
	IMPORT_C void Reset();
	IMPORT_C CImageTransformPluginExtension* Extension() const;

private:
	CImageTransform();
	void ConstructL(RFs& aFs);

private:
	CImageTransformFramework* iBody;
	};

#endif // __IMAGETRANSFORM_H__
