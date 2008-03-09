/**
 *  This file is a part of Promoe, an XMMS2 Client
 *
 *  Copyright (C) 2005-2008 XMMS2 Team
 *
 *  This program is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU General Public License
 *  as published by the Free Software Foundation; either version 2
 *  of the License, or (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 */

#ifndef __BASEWINDOW_H__
#define __BASEWINDOW_H__

#include <QMainWindow>
#include <QPoint>
#include <QMap>
class QMouseEvent;
class QPoint;

class MainWindow;

class BaseWindow;
typedef QMap<BaseWindow *, QPoint> AttachedWindowMap;

class BaseWindow : public QMainWindow {
	Q_OBJECT

	public:
		BaseWindow (QWidget *parent);
	
		bool touches (QWidget *);
		MainWindow * mw ();

	protected:
		void mousePressEvent (QMouseEvent *event);
		void mouseReleaseEvent (QMouseEvent *event);
		void mouseMoveEvent (QMouseEvent *event);

		QPoint snapWindow (QPoint pos, AttachedWindowMap attached = AttachedWindowMap());
		QPoint m_diff;
};

#endif
