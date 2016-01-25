/* Copyright (c) 2013, Linaro Limited
 * All rights reserved.
 *
 * SPDX-License-Identifier:     BSD-3-Clause
 */


/**
 * @file
 *
 * ODP HW system information
 */

#ifndef ODP_INTERNAL_H_
#define ODP_INTERNAL_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <odp/init.h>
#include <odp/thread.h>

extern __thread int __odp_errno;

typedef struct {
	uint64_t cpu_hz;
	uint64_t huge_page_size;
	uint64_t page_size;
	int      cache_line_size;
	int      cpu_count;
	char     model_str[128];
} odp_system_info_t;

struct odp_global_data_s {
	odp_log_func_t log_fn;
	odp_abort_func_t abort_fn;
	odp_system_info_t system_info;
};

enum init_stage {
	NO_INIT = 0,    /* No init stages completed */
	TIME_INIT = 1,
	SYSINFO_INIT = 2,
	SHM_INIT = 3,
	THREAD_INIT = 4,
	POOL_INIT = 5,
	QUEUE_INIT = 6,
	SCHED_INIT = 7,
	PKTIO_INIT = 8,
	TIMER_INIT = 9,
	CRYPTO_INIT = 10,
	CLASSIFICATION_INIT = 11,
	ALL_INIT = 12   /* All init stages completed */
};

extern struct odp_global_data_s odp_global_data;

int _odp_term_global(enum init_stage stage);
int _odp_term_local(enum init_stage stage);

int odp_system_info_init(void);
int odp_system_info_term(void);

int odp_thread_init_global(void);
int odp_thread_init_local(odp_thread_type_t type);
int odp_thread_term_local(void);
int odp_thread_term_global(void);

int odp_shm_init_global(void);
int odp_shm_term_global(void);
int odp_shm_init_local(void);

int odp_pool_init_global(void);
int odp_pool_init_local(void);
int odp_pool_term_global(void);
int odp_pool_term_local(void);

int odp_pktio_init_global(void);
int odp_pktio_term_global(void);
int odp_pktio_init_local(void);

int odp_classification_init_global(void);
int odp_classification_term_global(void);

int odp_queue_init_global(void);
int odp_queue_term_global(void);

int odp_crypto_init_global(void);
int odp_crypto_term_global(void);

int odp_schedule_init_global(void);
int odp_schedule_term_global(void);
int odp_schedule_init_local(void);
int odp_schedule_term_local(void);

int odp_timer_init_global(void);
int odp_timer_term_global(void);
int odp_timer_disarm_all(void);

int odp_time_init_global(void);
int odp_time_term_global(void);

void _odp_flush_caches(void);

#ifdef __cplusplus
}
#endif

#endif
