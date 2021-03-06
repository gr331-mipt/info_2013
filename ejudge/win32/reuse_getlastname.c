/* -*- mode:c -*- */
/* $Id: reuse_getlastname.c 6227 2011-04-04 19:10:59Z cher $ */

/* Copyright (C) 2004-2011 Alexander Chernov <cher@ejudge.ru> */

/*
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 */

#include "reuse_xalloc.h"
#include "reuse_logger.h"
#include "reuse_osdeps.h"

#include <string.h>

char *
os_GetLastname(char const *path)
{
  int len, i;

  if (!path) return xstrdup("");

  i = len = strlen(path);
  while (i > 0 && path[i - 1] != '/' && path[i - 1] != '\\' && path[i - 1] != ':') {
    --i;
  }
  return xstrdup(path + i);
}

/*
 * Local variables:
 *  compile-command: "make -C .."
 * End:
 */
