/****************************************************************************
   
    OS/A65 Version 1.3.12
    Multitasking Operating System for 6502 Computers

    Copyright (C) 1989-1997 Andre Fachat

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

****************************************************************************/


#include "../../include/fdefs.i65"	/* needed for FS_LASTCODE */
/*
 * additional FS commands to be sent between fstcp client & server
 * transparent to normal FS_* codes
 */
#define   FS_READ        FS_LASTCODE    /* pull data (FSTCP internal)        */
#define   FS_WRITE       FS_LASTCODE+1  /* push data (FSTCP internal)        */
#define   FS_REPLY       FS_LASTCODE+2  /* return value (FSTCP internal)     */
#define   FS_EOF         FS_LASTCODE+3  /* as FS_WRITE, but signal EOF after */
                                   	/* last byte sent                    */


#define MAXFILES        4

/* data struct exchanged with server */
#define FSP_CMD         0
#define FSP_LEN         1
#define FSP_FD          2
#define FSP_DATA        3

/* status values */
#define F_FREE          0	/* must be 0 */
#define F_CMD_SENT      1
#define F_CMD_REQUEUE   2	/* CMD must be requeued */

#define F_RD            3	/* no buffer to put to stream */
#define F_RD_SENT       4	/* FS_READ request sent */
#define F_RD_RXD        5	/* FS_WRITE reply received */
#define F_RD_EOF        6	/* FS_EOF reply received */
#define F_RD_CLOSE      7	/* FS_EOF reply processed */

#define F_WR            8
#define F_WR_WAIT       9	/* buffer ready but not (yet) sent */
#define F_WR_WEOF       10	/* last buffer ready but not (yet) sent */

