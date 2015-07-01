/**
* @file llviewerassetupload.h
* @author optional
* @brief brief description of the file
*
* $LicenseInfo:firstyear=2011&license=viewerlgpl$
* Second Life Viewer Source Code
* Copyright (C) 2011, Linden Research, Inc.
*
* This library is free software; you can redistribute it and/or
* modify it under the terms of the GNU Lesser General Public
* License as published by the Free Software Foundation;
* version 2.1 of the License only.
*
* This library is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
* Lesser General Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public
* License along with this library; if not, write to the Free Software
* Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*
* Linden Research, Inc., 945 Battery Street, San Francisco, CA  94111  USA
* $/LicenseInfo$
*/

#ifndef LL_VIEWER_ASSET_UPLOAD_H
#define LL_VIEWER_ASSET_UPLOAD_H

#include "llfoldertype.h"
#include "llassettype.h"
#include "llinventorytype.h"
#include "lleventcoro.h"
#include "llcoros.h"
#include "llcorehttputil.h"

#include "llviewermenufile.h"

class LLViewerAssetUpload
{
public:

    static void AssetInventoryUploadCoproc(LLCoros::self &self, LLCoreHttpUtil::HttpCoroutineAdapter::ptr_t &httpAdapter, const LLUUID &id,
        std::string url, NewResourceUploadInfo::ptr_t uploadInfo);


};

#endif // !VIEWER_ASSET_UPLOAD_H
