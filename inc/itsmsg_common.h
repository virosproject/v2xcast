/* Common data frame and element defintions
 * Copyright (C) Unex Technology Corporation - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 */

#ifndef __ITSMSG_COMMON_H__
#define __ITSMSG_COMMON_H__

#ifdef __cplusplus
extern "C" {
#endif

typedef enum DayOfWeek {
    DayOfWeek_unknown,
    DayOfWeek_monday,
    DayOfWeek_tuesday,
    DayOfWeek_wednesday,
    DayOfWeek_thursday,
    DayOfWeek_friday,
    DayOfWeek_saturday,
    DayOfWeek_sunday,
    DayOfWeek_MAX = UINT_MAX
} DayOfWeek;

#ifdef __cplusplus
}
#endif

#endif /* __ITSMSG_COMMON_H__ */
