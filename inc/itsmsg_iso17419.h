/* ISO17419 data frame and element defintions
 * Copyright (C) Unex Technology Corporation - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 */

#ifndef __ITSMSG_ISO17419_H__
#define __ITSMSG_ISO17419_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <limits.h>
#include "asn1defs_if.h"
#include "itsmsg_common.h"


typedef enum {
    Ext2_content,
    Ext2_extension,
} Ext2_choice;

typedef struct Ext2 {
    Ext2_choice choice;
    union {
        int32_t content;
        int32_t extension; /* Ext3 (2113664..270549119) */
    } u;
} Ext2;

typedef enum {
    Ext1_content,
    Ext1_extension,
} Ext1_choice;

typedef struct Ext1 {
    Ext1_choice choice;
    union {
        int32_t content;
        Ext2 extension;
    } u;
} Ext1;

typedef enum {
    VarLengthNumber_content,
    VarLengthNumber_extension,
} VarLengthNumber_choice;

typedef struct VarLengthNumber {
    VarLengthNumber_choice choice;
    union {
        int32_t content; /* (0..127) */
        Ext1 extension;
    } u;
} VarLengthNumber;


#ifdef __cplusplus
}
#endif

#endif /* __ITSMSG_ISO17419_H__ */
