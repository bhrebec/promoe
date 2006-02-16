#include "NumberDisplay.h"
#include "MainWindow.h"

NumberDisplay::NumberDisplay (QWidget *parent, uint w, uint startpx) : PixWidget (parent)
{
	m_w = w;
	m_startpx = startpx;

	m_pixmap = QPixmap (m_w, 13);
	
	setMinimumSize (m_w, 13);
	setMaximumSize (m_w, 13);

	setNumber (0,0);
}

void
NumberDisplay::setNumber (uint n1, uint n2)
{
	MainWindow *mw = (MainWindow *)((SkinDisplay *)parent ())->getMW();

	m_n1 = n1;
	m_n2 = n2;

	QBrush b (Qt::TexturePattern);
	b.setTexture (mw->getSkin ()->getNumber (10));

	QPainter paint;
	paint.begin (&m_pixmap);
	paint.fillRect (m_pixmap.rect (), b);
	paint.drawPixmap (m_startpx, 0, mw->getSkin ()->getNumber (n1));
	paint.drawPixmap (m_startpx+12, 0, mw->getSkin ()->getNumber (n2));
	paint.end();

	update ();
}

NumberDisplay::~NumberDisplay ()
{
}

