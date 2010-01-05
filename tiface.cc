/*
    Copyright (C) 2003-2008 Fons Adriaensen <fons@kokkinizita.net>
    
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
*/



#include <stdlib.h>
#include <stdio.h>
#define USE_VARARGS
#define PREFER_STDARG
#include <readline/readline.h>
#include <readline/history.h>
#include "tiface.h"



extern "C" Iface *create_iface (int ac, char *av [])
{
    return new Tiface (ac, av);
}



Tiface::Tiface (int ac, char *av [])
{
}


Tiface::~Tiface (void)
{
}


void Tiface::stop (void)
{
    _stop = true;
}


void Tiface::thr_main (void)
{
    _stop = false;
    set_time (0);
    inc_time (125000);

    while (! _stop)
    {
	switch (get_event_timed ())
	{
        case EV_TIME:
	    handle_time ();
            inc_time (125000);
 	    break;

        case FM_MODEL:
            handle_mesg (get_message ()); 
	    break;

        case EV_EXIT:
            return;
	}
    }
    send_event (EV_EXIT, 1);
}


void Tiface::handle_time (void)
{
}


void Tiface::handle_mesg (ITC_mesg *M)
{
    switch (M->type ())
    {
    default:
	M->recover ();
    }
}


