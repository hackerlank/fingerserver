#ifndef __LYNX_COMMON_LIB_DAILYTASK_TABLE_H__
#define __LYNX_COMMON_LIB_DAILYTASK_TABLE_H__

#include "Data.h"
#include "PlatformLib.h"

namespace Lynx
{
	struct DailyTaskTemplate 
	{
		UInt64 mId;
		UInt32 mNeedLv;
		UInt64 mEvent;
		UInt32 mArg;
		String mAward;
		UInt32 mActive;
		List<AllItemEle> mItemList;

		LYNX_S11N_7(DailyTaskTemplate, UInt64, mId, UInt64, mEvent,UInt32, mArg,
			String, mAward,List<AllItemEle>, mItemList,UInt32, mNeedLv, UInt32, mActive
			);

	};

	typedef Map<UInt64, DailyTaskTemplate> DailyTaskTempMap;



	struct DailyTaskTable
	{
		DailyTaskTempMap mMap;
		

		LYNX_S11N_1(DailyTaskTable, DailyTaskTempMap, mMap);

		DailyTaskTemplate* get(UInt64 id)
		{
			DailyTaskTempMap::Iter* iter = mMap.find(id);
			if (iter == mMap.end())
			{
				return NULL;
			}
			return &iter->mValue;
		}

		DailyTaskTempMap  * getDailyTaskMap()
		{
			return &mMap;
		}

	
		void clear()
		{
			mMap.clear();
		
		}

		bool loadFromDbc(const String& fileName);
		bool reloadFromDbc(const String& fileName);
		bool saveToDbc(const String& filePath);
		bool loadFromCsv(const String& filePath);

	};


	struct SevenDayTrainningTable
	{
		DailyTaskTempMap mMap;


		LYNX_S11N_1(SevenDayTrainningTable, DailyTaskTempMap, mMap);

		DailyTaskTemplate* get(UInt64 id)
		{
			DailyTaskTempMap::Iter* iter = mMap.find(id);
			if (iter == mMap.end())
			{
				return NULL;
			}
			return &iter->mValue;
		}

		DailyTaskTempMap  * getDailyTaskMap()
		{
			return &mMap;
		}


		void clear()
		{
			mMap.clear();

		}

		bool loadFromDbc(const String& fileName);
		bool reloadFromDbc(const String& fileName);
		bool saveToDbc(const String& filePath);
		bool loadFromCsv(const String& filePath);

	};
} // namespace Lynx

#endif // __LYNX_COMMON_LIB_DAILYTASK_TABLE_H__