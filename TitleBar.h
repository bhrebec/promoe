#ifndef __TITLEBAR_H__
#define __TITLEBAR_H__

class TitleBar;

#include "PixWidget.h"
#include "Button.h"

using namespace std;

class TitleBar : public PixWidget
{
	Q_OBJECT
	public:
		TitleBar (QWidget *parent, bool shaded);
		~TitleBar ();
		void setActive (bool active);

	public slots:
		void setPixmaps (Skin *skin);

	protected:
		void mouseDoubleClickEvent (QMouseEvent *event);

	private:
		QPixmap m_pixmap_active;
		QPixmap m_pixmap_inactive;

		Button *m_shadebtn;
		Button *m_menubtn;
		Button *m_closebtn;
		Button *m_minimize;

		bool m_shaded;
};

#endif
