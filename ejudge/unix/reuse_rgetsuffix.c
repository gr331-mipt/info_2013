/* -*- mode:c -*- */
/* $Id: reuse_rgetsuffix.c 6166 2011-03-27 10:27:54Z cher $ */

/* Copyright (C) 2002-2011 Alexander Chernov <cher@ejudge.ru> */

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

#include "reuse_osdeps.h"

#include <string.h>

/**
 * NAME:    os_rGetSuffix
 * PURPOSE: get the suffix of the file (reentrant version)
 * ARGS:    path - path of the file
 *          buf  - buffer to store suffix
 *          size - size of the buffer
 * RETURN:  length of the suffix string
 */
  int
os_rGetSuffix(char const *path, char *buf, int size)
{
  char *dp;
  char *sp;

  buf[0] = 0;
  if (!path) return 0;

  sp = strrchr(path, '/');
  dp = strrchr(path, '.');

  if (!dp) return 0;
  if (sp != NULL && sp + 1 >= dp) return 0;
  strncpy(buf, dp, size);
  buf[size-1] = 0;
  return strlen(buf);
}

/*
 * Local variables:
 *  compile-command: "make -C .."
 * End:
 */
