/*
Copyright 2013-present Barefoot Networks, Inc. 

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

//:: # Template file
//:: # @FIXME top matter needed
/**
 * @file
 * @brief Enumerations and definitions requiring no other includes
 *
 * @fixme top matter
 *
 * DO NOT EDIT:  This file is automatically generated.
 *
 */

#ifndef _RMT_ENUMS_H
#define _RMT_ENUMS_H

#define RMT_PIPELINE_INGRESS 0
#define RMT_PIPELINE_EGRESS 1

/**
 * @addtogroup Headers
 * @{
 */

/**
 * @brief Header instance enumeration
 *
 * Enumeration of header instance names.  Used for indexing into tables
 * that contain header instance related data.
 */

typedef enum rmt_header_instance_e {
    RMT_HEADER_INSTANCE_NONE,
    /* virtual must go first */
//:: for header_inst_name in ordered_header_instances_all:
    RMT_HEADER_INSTANCE_${header_inst_name},
//:: #endfor
    RMT_HEADER_INSTANCE_COUNT
} rmt_header_instance_t;

//:: for base_name, depth_max in tag_stacks_depth.items():
#define ${base_name}_DEPTH_MAX ${depth_max}
//:: #endfor

/**
 * @brief Macro mapping to name string
 */

extern const char *rmt_header_instance_string[RMT_HEADER_INSTANCE_COUNT + 1];
#define RMT_HEADER_INSTANCE_STRING(header_instance)             \
    (RMT_HEADER_INSTANCE_VALID(header_instance) ?               \
     rmt_header_instance_string[header_instance] : "INVALID")

/**
 * @brief Macro to determine if a header type name is valid
 * @param header_type The name of the header type
 * @param instance An index for the header type instance
 * @returns True if reference is valid
 */

#define RMT_HEADER_INSTANCE_VALID(header_instance)          \
    (((header_instance) > RMT_HEADER_INSTANCE_NONE) &&      \
     ((header_instance) < RMT_HEADER_INSTANCE_COUNT))

/**
 * @brief Iterate thru the header instances
 */
#define RMT_HEADER_INSTANCE_FOREACH(header_instance)                    \
    for ((header_instance) = RMT_HEADER_INSTANCE_NONE + 1;              \
         (header_instance) < RMT_HEADER_INSTANCE_COUNT; (header_instance)++)

/**
 * @brief Iterate thru the header instances which go on the wire
 *
 * @TODO Need a way to signal metadata and/or convention about putting
 * metadata up front.
 */
#define RMT_HEADER_INSTANCE_WIRE_FOREACH(header_instance)               \
    for ((header_instance) = RMT_HEADER_INSTANCE_ETHERNET_0;            \
         (header_instance) < RMT_HEADER_INSTANCE_COUNT; (header_instance)++)

/** @} */

/****************************************************************/

/**
 * @addtogroup Fields
 * @{
 */

/**
 * @brief Enumeration of field instance names
 *
 * For bitmaps, field names x instances also get a name
 */
typedef enum rmt_field_instance_e {
    RMT_FIELD_INSTANCE_NONE,
    /* virtual must go first */
//:: for field_name in ordered_field_instances_all:
    RMT_FIELD_INSTANCE_${field_name},
//:: #endfor
    RMT_FIELD_INSTANCE_COUNT
} rmt_field_instance_t;

/* TODO: Indicate the set of mutable/immutable fields */

#define FIELD_IS_MUTABLE(fld) 1

/**
 * @brief Macro mapping to name string
 */

extern const char *rmt_field_instance_string[RMT_FIELD_INSTANCE_COUNT + 1];
#define RMT_FIELD_INSTANCE_STRING(field_instance)             \
    (RMT_FIELD_INSTANCE_VALID(field_instance) ?               \
     rmt_field_instance_string[field_instance] : "INVALID")

#define RMT_FIELD_INSTANCE_VALID(field_instance)       \
    (((field_instance) > (int)RMT_FIELD_INSTANCE_NONE) &&   \
     ((field_instance) < (int)RMT_FIELD_INSTANCE_COUNT))

/**
 * @brief Iterate thru the field instances
 */
#define RMT_FIELD_INSTANCE_FOREACH(field_instance)                     \
    for ((field_instance) = RMT_FIELD_INSTANCE_NONE + 1;               \
         (field_instance) < (int)RMT_FIELD_INSTANCE_COUNT; (field_instance)++)


/** @} */

/****************************************************************/

/**
 * @todo Put data types in their own doxygen module
 */

/**
 * @brief Enumeration of recognized data types
 *
 * The recognized data types for RMT fields
 */
typedef enum rmt_field_data_type_e {
//:: for dtype_t in field_data_types:
//::     dtype = dtype_t[:-2] # Strip _t from type
    RMT_FIELD_DATA_TYPE_${dtype.upper()},
//:: #endfor
    RMT_FIELD_DATA_TYPE_COUNT
} rmt_field_data_type_t;

/** @} */


/****************************************************************/

/**
 * @addtogroup Tables
 * @{
 */

/**
 * @brief Enumeration of table names
 */
typedef enum rmt_table_e {
    RMT_TABLE_NONE,
//:: for table_name, t_info in table_info.items():
    RMT_TABLE_${table_name},
//:: #endfor
    RMT_TABLE_COUNT
} rmt_table_t;

/**
 * @brief Macro mapping to name string
 */

extern const char *rmt_table_string[RMT_TABLE_COUNT + 1];
#define RMT_TABLE_STRING(table)		    \
  (RMT_TABLE_VALID(table) ?		    \
   rmt_table_string[table] : "INVALID")

#define RMT_TABLE_VALID(table)		  \
  (((table) > (int)RMT_TABLE_NONE) &&	  \
   ((table) < (int)RMT_TABLE_COUNT))

/**
 * @brief Iterate thru the tables
 */
#define RMT_TABLE_FOREACH(table)                     \
  for ((table) = RMT_TABLE_NONE + 1;		     \
       (table) < (int)RMT_TABLE_COUNT; (table)++)


/** @} */

/****************************************************************/

/**
 * @brief Enumeration of recognized table types
 *
 * The recognized table types
 */
typedef enum rmt_table_type_e {
//:: for ttype in table_types:
    RMT_TABLE_TYPE_${ttype.upper()},
//:: #endfor
    RMT_TABLE_TYPE_COUNT
} rmt_table_type_t;

/** @} */

typedef enum pkt_instance_type_e {
  PKT_INSTANCE_TYPE_NORMAL,
  PKT_INSTANCE_TYPE_INGRESS_CLONE,
  PKT_INSTANCE_TYPE_EGRESS_CLONE,
  PKT_INSTANCE_TYPE_COALESCED,
  PKT_INSTANCE_TYPE_INGRESS_RECIRC,
  PKT_INSTANCE_TYPE_REPLICATION,
  PKT_INSTANCE_TYPE_RESUBMIT,
} pkt_instance_type_t;


/**
 * @brief Enumeration of field lists
 */
typedef enum rmt_field_list_e {
    RMT_FIELD_LIST_NONE,
//:: for field_list in field_lists:
    RMT_FIELD_LIST_${field_list},
//:: #endfor
    RMT_FIELD_LIST_COUNT
} rmt_field_list_t;

#define RMT_FIELD_LIST_VALID(field_list)	  \
  (((int)(field_list) > (int)RMT_TABLE_NONE) &&	  \
   ((int)(field_list) < (int)RMT_TABLE_COUNT))


/**
 * @brief Enumeration of action profiles
 */
typedef enum rmt_act_prof_e {
    RMT_ACT_PROF_NONE,
//:: for act_prof, ap_info in action_profiles.items():
    RMT_ACT_PROF_${act_prof},
//:: #endfor
    RMT_ACT_PROF_COUNT
} rmt_act_prof_t;

/**
 * @brief Iterate thru the action profiles
 */
#define RMT_ACT_PROF_FOREACH(act_prof)                     \
  for ((act_prof) = RMT_ACT_PROF_NONE + 1;		     \
       (act_prof) < (int)RMT_ACT_PROF_COUNT; (act_prof)++)

#endif
