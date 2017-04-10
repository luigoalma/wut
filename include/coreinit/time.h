#pragma once
#include <wut.h>

/**
 * \defgroup coreinit_time Time
 * \ingroup coreinit
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

typedef struct OSCalendarTime OSCalendarTime;

typedef int32_t OSTick;
typedef int64_t OSTime;

//! Same as std c struct tm but with msec and usec added.
struct OSCalendarTime
{
   int32_t tm_sec;
   int32_t tm_min;
   int32_t tm_hour;
   int32_t tm_mday;
   int32_t tm_mon;
   int32_t tm_year;
   int32_t tm_wday;
   int32_t tm_yday;
   int32_t tm_msec;
   int32_t tm_usec;
};
CHECK_OFFSET(OSCalendarTime, 0x00, tm_sec);
CHECK_OFFSET(OSCalendarTime, 0x04, tm_min);
CHECK_OFFSET(OSCalendarTime, 0x08, tm_hour);
CHECK_OFFSET(OSCalendarTime, 0x0C, tm_mday);
CHECK_OFFSET(OSCalendarTime, 0x10, tm_mon);
CHECK_OFFSET(OSCalendarTime, 0x14, tm_year);
CHECK_OFFSET(OSCalendarTime, 0x18, tm_wday);
CHECK_OFFSET(OSCalendarTime, 0x1C, tm_yday);
CHECK_OFFSET(OSCalendarTime, 0x20, tm_msec);
CHECK_OFFSET(OSCalendarTime, 0x24, tm_usec);
CHECK_SIZE(OSCalendarTime, 0x28);

#define OSOneSecond ((OSGetSystemInfo()->clockSpeed) / 4)
#define OSMilliseconds(val) ((((uint64_t)(val)) * (uint64_t)(OSOneSecond)) / 1000ull)
#define OSMicroseconds(val) ((((uint64_t)(val)) * (uint64_t)(OSOneSecond)) / 1000000ull)
#define OSNanoseconds(val) ((((uint64_t)(val)) * (uint64_t)(OSOneSecond)) / 1000000000ull)

OSTime
OSGetTime();

OSTime
OSGetSystemTime();

OSTick
OSGetTick();

OSTick
OSGetSystemTick();

OSTime
OSCalendarTimeToTicks(OSCalendarTime *calendarTime);

void
OSTicksToCalendarTime(OSTime time,
                      OSCalendarTime *calendarTime);

#ifdef __cplusplus
}
#endif

/** @} */
