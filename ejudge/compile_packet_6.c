/* -*- c -*- */
/* $Id: compile_packet_6.c 6172 2011-03-27 12:40:30Z cher $ */

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

#include "compile_packet.h"
#include "compile_packet_priv.h"
#include "pathutl.h"
#include "prepare.h"
#include "runlog.h"

#include "reuse_xalloc.h"
#include "reuse_logger.h"
#include "reuse_integral.h"

#include <stdlib.h>
#include <string.h>

struct compile_reply_packet *
compile_reply_packet_free(struct compile_reply_packet *in_data)
{
  if (!in_data) return 0;
  if (in_data->run_block_len) {
    xfree(in_data->run_block);
  }
  memset(in_data, 0, sizeof(*in_data));
  xfree(in_data);
  return 0;
}

/**
 * Local variables:
 *  compile-command: "make"
 *  c-font-lock-extra-types: ("\\sw+_t" "FILE")
 * End:
 */
