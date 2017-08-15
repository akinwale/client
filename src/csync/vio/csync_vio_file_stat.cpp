/*
 * libcsync -- a library to sync a directory with another
 *
 * Copyright (c) 2008-2013 by Andreas Schneider <asn@cryptomilk.org>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#include "c_lib.h"
#include "csync.h"
#include "csync_log.h"

void csync_vio_set_file_id( char* dst, const char *src ) {
    if( src && dst ) {
        if( strlen(src) > FILE_ID_BUF_SIZE ) {
            CSYNC_LOG(CSYNC_LOG_PRIORITY_ERROR, "Ignoring file_id because it is too long: %s", src);
            strcpy(dst, "");
        } else {
            strcpy(dst, src);
        }
    }
}
