/* -*- mode: c -*- */
/* $Id: out_open.c 7460 2013-10-21 21:35:57Z cher $ */

/* Copyright (C) 2010-2013 Alexander Chernov <cher@ejudge.ru> */

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

#include "checker_internal.h"

#include "l10n_impl.h"

void
checker_out_open(const char *path)
{
  if (f_out && f_out == f_arr[1]) {
    fclose(f_out); f_out = 0; f_arr[1] = 0;
  }
  if (f_out) fclose(f_out);
  f_out = 0;
  if (f_arr[1]) fclose(f_arr[1]);
  f_arr[1] = 0;

  if (!(f_out = fopen(path, "r")))
    fatal_PE(_("%s: cannot open %s for reading"), gettext(f_arr_names[1]), path);
  f_arr[1] = f_out;
}
