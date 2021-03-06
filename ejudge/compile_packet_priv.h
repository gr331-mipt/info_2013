/* -*- c -*- */
/* $Id: compile_packet_priv.h 6219 2011-04-03 20:50:09Z cher $ */
#ifndef __COMPILE_PACKET_PRIV_H__
#define __COMPILE_PACKET_PRIV_H__

/* Copyright (C) 2005-2011 Alexander Chernov <cher@ejudge.ru> */

/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include "reuse_integral.h"

#define EJ_COMPILE_PACKET_VERSION 4

/* various private data structures and constants for compile packets */

/* serve->compile binary packet structure */
/* little-endian byte ordering is assumed */
struct compile_request_bin_packet
{
  rint32_t packet_len;          /* the overall packet length */
  rint32_t version;             /* the packet version (2) */
  rint32_t judge_id;            /* judgement serial number, 16 bits used */
  rint32_t contest_id;          /* the contest id [1..999999] */
  rint32_t run_id;              /* the run id [0..999999] */
  rint32_t lang_id;             /* the language [1..max_lang] */
  rint32_t locale_id;           /* the locale identifier */
  rint32_t output_only;         /* the problem is output only */
  ruint64_t max_vm_size;        /* the process VM limit */
  ruint64_t max_stack_size;     /* the process stack size */
  ruint64_t max_file_size;      /* the maximum file size */
  rint32_t style_check_only;    /* only perform style check */
  rint32_t ts1;                 /* the time, when comp. request was queued */
  rint32_t ts1_us;              /* the microsecond component */
  rint32_t style_checker_len;   /* the length of the style checker command */
  rint32_t src_sfx_len;         /* the length of the source file suffix */
  rint32_t run_block_len;       /* the length of the run block */
  rint32_t env_num;             /* the number of env. variables */
  rint32_t sc_env_num;          /* the number of style checker env. vars */
  unsigned char pad[8];         /* padding to 16-byte boundary */
  /* style checker command (aligned to 16 byte boundary) */
  /* run_block (aligned to 16 byte boundary) */
  /* env variable length array (aligned to 16-byte address boundary) */
  /* env variable strings (aligned to 16-byte boundary) */
  /* style checker environment length array */
  /* style checker environment strings */
};

/* compile->serve binary packet structure */
/* little-endian byte ordering is assumed */
struct compile_reply_bin_packet
{
  rint32_t packet_len;
  rint32_t version;
  rint32_t judge_id;
  rint32_t contest_id;
  rint32_t run_id;
  rint32_t status;
  /* time when the compile request was queued by serve */
  rint32_t ts1;
  rint32_t ts1_us;
  /* time when the compile request was received by compile */
  rint32_t ts2;
  rint32_t ts2_us;
  /* time when the compile request was completed by compile */
  rint32_t ts3;
  rint32_t ts3_us;
  rint32_t run_block_len;       /* the length of the run block */
  unsigned char pad[12];        /* padding to 64-byte boundary */
  /* run block (aligned to 16 byte boundary) */
};

#endif /* __COMPILE_PACKET_PRIV_H__ */
