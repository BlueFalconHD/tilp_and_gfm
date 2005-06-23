/* Hey EMACS -*- linux-c -*- */
/* $Id$ */

/*  TiLP - Ti Linking Program
 *  Copyright (C) 1999-2005  Romain Lievin
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>

#include "tilp_core.h"
#include "gstruct.h"

struct label_window label_wnd = { 0 };

#ifdef __WIN32__
#define snprintf _snprintf
#endif

static char* format(char *src, char *dst)
{
	char header[5];		// "C:\" as Win32 or "/" as Linux)
	char *path;			// leading path
	char *p;
	int n;

	char *left = NULL;	// left part
	char *right = NULL;	// right part

	char str[8];

	// remove header to be platform independant
#ifdef __WIN32__
	strncpy(header, src, 3);
	header[3] = '\0';
	path = &src[3];
#else
	strcpy(header, "/");
	path = &src[1];
#endif
  
	// count number of path elements (slashes)
	for(n = 0, p = src; ; n++) 
	{
		p = (char *)strchr(p, G_DIR_SEPARATOR);	
		if(!p)
			break;
		p++;
	}

	if(n <= 2)
		strcpy(dst, src);
	else {
		left = strdup(path);
		right = strdup(path);

		p = (char *)strchr(left, G_DIR_SEPARATOR);		// first slash (head)
		*p = '\0';

		p = (char *)strrchr(right, G_DIR_SEPARATOR);	// last slash (tail)

		strcpy(dst, header);
		strcat(dst, left);
		strcat(dst, G_DIR_SEPARATOR_S);
		strcat(dst, "...");
		strcat(dst, p);
		
		snprintf(str, 8, " (%i)", n);
		strcat(dst, str);

		free(left);
		free(right);
	}

	return dst;
}

/* Refresh the info window */
void labels_refresh(void)
{
	gchar str[256];
	gsize br, bw;
	gchar *utf8;
	gchar path[256];

	if(remote_win.memory.mem_free == -1)
		snprintf(str, sizeof(str), _("Memory used: %u bytes"), remote_win.memory.mem_vars);
	else
		snprintf(str, sizeof(str), _("Memory free/used: %u/%u bytes"),
			remote_win.memory.mem_free, remote_win.memory.mem_vars);

	gtk_label_set_text(GTK_LABEL(label_wnd.label21), str);
	
	utf8 = g_filename_to_utf8(local_win.cwdir, -1, &br, &bw, NULL);
	format(utf8, path);
	snprintf(str, sizeof(str), _("Folder: %s"), path);
	gtk_label_set_text(GTK_LABEL(label_wnd.label22), str);
}
