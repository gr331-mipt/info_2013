/* -*- mode: c -*- */
/* $Id: t7.c 4999 2008-08-15 08:36:19Z cher $ */

/* Copyright (C) 2008 Alexander Chernov <cher@ejudge.ru> */

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

#include <stdio.h>
#include <sys/ptrace.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <sys/utsname.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <limits.h>

#include "get_version.c"

static char progname[PATH_MAX];

static void do_son(void) __attribute__((noreturn));
void do_son(void)
{
  int ptcmd = 0;

  if (linux_version >= 2006000) {
    ptcmd = 0x4281;
  } else {
    fprintf(stderr, "failed: unsupported Linux kernel\n");
    _exit(111);
  }

  if (ptrace(ptcmd, 0, 0, 0) < 0) {
    fprintf(stderr, "failed: ptrace() error: %s\n", strerror(errno));
    _exit(111);
  }

  errno = 0;
  execl(progname, progname, NULL);
  fprintf(stderr, "failed: execl failed: %s\n", strerror(errno));
  _exit(111);
}

int main(int argc, char **argv)
{
  int p, s, d = 0;

  snprintf(progname, sizeof(progname), "%s_helper", argv[0]);

  fprintf(stderr, "t7: checking security violations\n");

  if ((linux_version = get_linux_version()) < 0)
    return 1;
  if (!linux_version) {
    fprintf(stderr, "failed: not Linux or unknown linux version\n");
    return 1;
  }
  fprintf(stderr, "t7: linux version %d\n", linux_version);

  if ((p = fork()) < 0) {
    fprintf(stderr, "failed: unexpected fork() error: %s\n", strerror(errno));
    return 1;
  }
  if (!p) do_son();
  wait(&s);
  if ((s & 0x20000)) {
    fprintf(stderr, "info: 0x20000 detected\n");
    s &= 0xffff;
    d = 1;
  }
  if (WIFEXITED(s) && WEXITSTATUS(s) == 111) {
    fprintf(stderr, "failed: child failed to setup limitations\n");
    return 1;
  }

  if (WIFEXITED(s)) {
    fprintf(stderr, "info: child exited: %d\n", WEXITSTATUS(s));
  } else if (WIFSIGNALED(s)) {
    fprintf(stderr, "info: child signaled: %d\n", WTERMSIG(s));
  }

  if (!d) {
    fprintf(stderr, "failed: security error is not detected\n");
    return 1;
  }
  fprintf(stderr, "ok\n");
  return 0;
}
