/**
 * @brief 
 * Shiming: created this based on PARSEC hook
 */
/* Copyright (c) 2006-2008 by Princeton University
 * All rights reserved.
 * Author: Christian Bienia
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of Princeton University nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY CHRISTIAN BIENIA ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL CHRISTIAN BIENIA BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef _HOOKS_H
/** Guard macro to prevent multiple inclusions. */
#define _HOOKS_H 1

#ifdef __cplusplus
extern "C" {
#endif

/*** Type declarations ***/

/** \brief Identifiers for the benchmark programs
 *
 * Each workload has exactly one unique identifier in this enumeration. The
 * benchmark passes it to __parsec_bench_begin() at the beginning of its
 * execution.
 */
enum __benchmark {
  __crono_apsp,
  __crono_bc,
  __crono_bc_non_partition,
  __crono_bfs,
  __crono_bfs_atomic,
  __crono_community_atomic,
  __crono_community_lock,
  __crono_connected_components_atomic,
  __crono_connected_components_lock,
  __crono_dfs,
  __crono_pagerank,
  __crono_pagerank_lock,
  __crono_sssp,
  __crono_sssp_outer,
  __crono_sssp_outer_atomic,
  __crono_sorted_neighbors_tri_lock,
  __crono_triangle_counting_atomic,
  __crono_triangle_counting_lock,
};



/*** Function declarations ***/

/** \brief Beginning of program execution.
 *
 * \param[in] __bench Unique workload identifier.
 *
 * This function is executed exactly once, as soon as the program starts.
 *
 * Its logical counterpart is __parsec_bench_end.
 */
void __bench_begin(enum __benchmark __bench);

/** \brief End of program execution.
 *
 * This function is executed exactly once, just before the program ends.
 *
 * Its logical counterpart is __parsec_bench_begin.
 */
void __bench_end();

/** \brief Beginning of Region-of-Interest.
 *
 * This function is executed exactly once, just before the Region-of-Interest
 * (ROI) is entered. The ROI is the part of the code that should be used for
 * benchmarking and analysis. It contains the entire parallel phase of the
 * program.
 *
 * The logical counterpart of this function is __parsec_roi_end.
 */
void __roi_begin();

/** \brief End of Region-of-Interest.
 *
 * This function is executed exactly once, immediately after the
 * Region-of-Interest (ROI) is left. The ROI is the part of the code that
 * should be used for benchmarking and analysis. It contains the entire parallel
 * phase of the program.
 *
 * The logical counterpart of this function is __parsec_roi_begin.
 */
void __roi_end();

#include "stdint.h"
extern void m5_work_begin(uint64_t workid, uint64_t threadid);
extern void m5_work_end(uint64_t workid, uint64_t threadid);
extern void m5_dump_stats(uint64_t ns_delay, uint64_t ns_period);
extern void m5_dump_reset_stats(uint64_t ns_delay, uint64_t ns_period);

#ifdef __cplusplus
} // extern "C"
#endif

#endif //_HOOKS_H

