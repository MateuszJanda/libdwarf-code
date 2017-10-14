/*
  Copyright (C) 2008-2010 SN Systems.  All Rights Reserved.
  Portions Copyright (C) 2008-2017 David Anderson.  All Rights Reserved.
  Portions Copyright (C) 2011-2012 SN Systems Ltd.  .  All Rights Reserved.

  This program is free software; you can redistribute it and/or modify it
  under the terms of version 2 of the GNU General Public License as
  published by the Free Software Foundation.

  This program is distributed in the hope that it would be useful, but
  WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

  Further, this software is distributed without any warranty that it is
  free of the rightful claim of any third person regarding infringement
  or the like.  Any license provided herein, whether implied or
  otherwise, applies only to this software file.  Patent licenses, if
  any, provided herein do not apply to combinations of this program with
  other software, or any other product whatsoever.

  You should have received a copy of the GNU General Public License along
  with this program; if not, write the Free Software Foundation, Inc., 51
  Franklin Street - Fifth Floor, Boston MA 02110-1301, USA.
*/

/* These do little except on Windows */

#include "common.h"
#include "config.h"
#include "globals.h"
#include "warningcontrol.h"
#include <stdio.h>
/* Windows specific header files */
#ifdef HAVE_STDAFX_H
#include "stdafx.h"
#endif /* HAVE_STDAFX_H */

#define DW_VERSION_DATE_STR " 2017-10-13 19:09:46-07:00  "
#define RELEASE_DATE      "20160307"

/* The Linux/Unix version does not want a version string to print
   unless -V is on the command line. */
void
print_version_details(UNUSEDARG const char * name,int alwaysprint)
{
#ifdef _WIN32
#ifdef _DEBUG
    char *acType = "Debug";
#else
    char *acType = "Release";
#endif /* _DEBUG */
#ifdef _WIN64
  char *bits = "64";
#else
  char *bits = "32";
#endif /* _WIN64 */
    static char acVersion[64];
    snprintf(acVersion,sizeof(acVersion),
        "[%s %s %s Win%s (%s)]",__DATE__,__TIME__,acType,bits,RELEASE_DATE);
    printf("%s %s\n",sanitized(name),acVersion);
#else  /* !_WIN32 */
    if (alwaysprint) {
        printf("%s\n",DW_VERSION_DATE_STR);
    }
#endif /* _WIN32 */
}


void
print_args(UNUSEDARG int argc, UNUSEDARG char *argv[])
{
#ifdef _WIN32
    int index = 1;
    printf("Arguments: ");
    for (index = 1; index < argc; ++index) {
        printf("%s ",sanitized(argv[index]));
    }
    printf("\n");
#endif /* _WIN32 */
}

void
print_usage_message(const char *program_name_in, const char **text)
{
    unsigned i = 0;
#ifndef _WIN32
    fprintf(stderr,"Usage:  %s  <options> <object file>\n", program_name_in);
#endif /* _WIN32 */
    for (i = 0; *text[i]; ++i) {
        fprintf(stderr,"%s\n", text[i]);
    }
}
