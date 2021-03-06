/* -*- mode: c -*- */
/* $Id: register_contest.c 7364 2013-02-09 20:19:53Z cher $ */

/* Copyright (C) 2002-2013 Alexander Chernov <cher@ejudge.ru> */

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

#include "userlist_clnt/private.h"

int
userlist_clnt_register_contest(
        struct userlist_clnt *clnt,
        int cmd,
        int user_id,
        int contest_id,
        const ej_ip_t *ip,
        int ssl_flag)
{
  struct userlist_pk_register_contest *out;
  struct userlist_packet *in = 0;
  int r;
  size_t out_size, in_size = 0;

  /*
  if (cmd != ULS_REGISTER_CONTEST && cmd != ULS_PRIV_REGISTER_CONTEST)
    return -ULS_ERR_PROTOCOL;
  */

  out_size = sizeof(*out);
  out = alloca(out_size);
  memset(out, 0, out_size);
  if (!out) return -ULS_ERR_OUT_OF_MEM;
  out->request_id = cmd;
  out->user_id = user_id;
  out->contest_id = contest_id;
  if (ip) {
    out->ip = *ip;
  }
  out->ssl_flag = ssl_flag;
  if ((r = userlist_clnt_send_packet(clnt, out_size, out)) < 0) return r;
  if ((r = userlist_clnt_read_and_notify(clnt, &in_size, (void*) &in)) < 0)
    return r;
  if (in_size != sizeof(*in)) {
    xfree(in);
    return -ULS_ERR_PROTOCOL;
  }
  r = in->id;
  xfree(in);
  return r;
}

/*
 * Local variables:
 *  compile-command: "make -C .."
 * End:
 */
