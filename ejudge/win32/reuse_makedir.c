/* -*- mode:c -*- */
/* $Id: reuse_makedir.c 6165 2011-03-27 10:26:54Z cher $ */

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

#include "reuse_logger.h"
#include "reuse_osdeps.h"

#include <windows.h>

/*
 * NAME:    os_MakeDir
 * PURPOSE: create directory
 * ARGS:    path - path to the directory
 *          mode - directory permissions mode
 * RETURN:  <0 - error, >0 - ok, 1 - directory already exists
 */
int
os_MakeDir(char const *path, int mode)
{
  if (CreateDirectory(path, NULL)) return 1;
  if (GetLastError() == ERROR_ALREADY_EXISTS) return 0;
  return -1;
}

/*
 * Local variables:
 *  compile-command: "make -C ../.."
 * End:
 */
