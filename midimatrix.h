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


#ifndef __MIDIMATRIX_H
#define __MIDIMATRIX_H


#include "clxclient.h"
#include "messages.h"


class Midimatrix : public X_window
{
public:

    Midimatrix (X_window *parent, X_callback *callb, int xp, int yp);
    ~Midimatrix (void);
 
    virtual void handle_event (XEvent *xe);

    void init (M_ifc_init *M);
    int  xsize (void) const { return _xs; }
    int  ysize (void) const { return _ys; }
    uint16_t *get_chconf (void) { return _chconf; }
    void      set_chconf (uint16_t *);

private:

    enum { XL = 180, XR = 5, YT = 5, YB = 22, DX = 22, DY = 22 };

    void expose (XExposeEvent *E);
    void redraw (void);
    void plot_grid (void);
    void plot_conn (int x, int y);
    void plot_allconn (void);
    void bpress (XButtonEvent *E);

    X_callback     *_callb;
    bool            _mapped;
    int             _xs;
    int             _ys;
    int             _nkeybd;
    int             _ndivis;
    const char     *_label [15];
    uint16_t        _flags [6];
    uint16_t        _chconf [16];
    int             _chan;
};


#endif
