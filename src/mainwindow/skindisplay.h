/**
 *  This file is a part of Promoe, an XMMS2 Client.
 *
 *  Copyright (C) 2005-2008 XMMS2 Team
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

#ifndef __SKINDISPLAY_H__
#define __SKINDISPLAY_H__

#include <QWidget>
class QEvent;
class QPaintEvent;

class Skin;

class SkinDisplay : public QWidget
{
	Q_OBJECT
	public:
		SkinDisplay (QWidget *parent);
		QWidget *getMW () const { return m_mw; }

	public slots:
		virtual void setPixmaps(Skin *skin);
		void fileOpen (void);

	protected:
		void paintEvent (QPaintEvent *event);
		void enterEvent (QEvent *event);
		void leaveEvent (QEvent *event);

		QWidget *m_mw;
		QWidget *m_tbar;
		
};

#endif