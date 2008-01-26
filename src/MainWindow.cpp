/**
 *  This file is a part of Prome, an XMMS2 Client.
 *
 *  Copyright (C) 2005-2007 XMMS2 Team
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; version 2 of the License.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 */

#include "MainWindow.h"

#ifdef HAVE_SERVERBROWSER
#include "ServerBrowser.h"
#endif

#include "playlist.h"
#include "MainDisplay.h"
#include "ShadedDisplay.h"
#include "equalizer.h"

#include <QSettings>
#include <QIcon>
#include <QPluginLoader>
#include <qplugin.h>

MainWindow::MainWindow (QWidget *parent) : QMainWindow (parent)
{
	QSettings settings;

	setWindowFlags(Qt::FramelessWindowHint);
	setGeometry(100, 100, 275, 116);
#ifndef _WIN32
	setWindowIcon (QIcon (":icon.png"));
#endif

	if (!settings.contains ("mainwindow/shaded"))
		setShaded (true);
	else
		setShaded (!isShaded ());

	/* 
	 * The MainDisplay is the mainwindow non-shaded mode
	 */
	m_display = new MainDisplay (this);
	setCentralWidget (m_display);
	m_display->show ();

	/*
	 * MainDisplay's shaded mode
	 */
	m_shaded = new ShadedDisplay (this);
	m_shaded->hide ();

	switchDisplay ();

	m_playlistwin = NULL;

	if (!settings.contains ("mainwindow/pos"))
		settings.setValue ("mainwindow/pos", QPoint (100, 100));

	move (settings.value("mainwindow/pos").toPoint ());
}

MainWindow::~MainWindow ()
{
	delete Skin::getInstance ();
}

void
MainWindow::switchDisplay ()
{
	QSettings s;

	if (isShaded ()) {
		m_shaded->hide ();
		m_display->show ();
		resize (275, 116);
		setShaded (false);
	} else {
		m_display->hide ();
		m_shaded->show ();
		resize (275, 14);
		setShaded (true);
	}

	update ();

}

void
MainWindow::raisePL (void)
{ 
	m_playlistwin->raise (); 
}

void
MainWindow::moveEvent (QMoveEvent *event)
{
	QSettings s;
	s.setValue ("mainwindow/pos", pos ());
}

void 
MainWindow::togglePL (bool UpdateButton) 
{ 
	QSettings s;

	if(UpdateButton)
	{
		getMD()->GetPls()->toggleOn();
	}

	if (s.value ("playlist/hidden").toBool ()) {
		m_playlistwin->move (s.value("playlist/pos").toPoint ());
		m_playlistwin->show (); 
		s.setValue ("playlist/hidden", false);
	} else {
		m_playlistwin->hide (); 
		s.setValue ("playlist/hidden", true);
	} 
}


void 
MainWindow::toggleEQ (bool UpdateButton) 
{ 
	QSettings s;

	if(UpdateButton)
	{
		getMD()->GetEq()->toggleOn();
	}

	if (s.value ("equalizer/hidden").toBool ()) {
		m_equalizer->move (s.value("equalizer/pos").toPoint ());
		m_equalizer->show (); 
		s.setValue ("equalizer/hidden", false);
	} else {
		m_equalizer->hide (); 
		s.setValue ("equalizer/hidden", true);
	} 
}
