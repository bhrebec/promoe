#ifndef __MEDIALIBVIEW_H__
#define __MEDIALIBVIEW_H__

#include <QTreeView>
#include <QAbstractItemModel>

class MedialibView : public QTreeView
{
	Q_OBJECT
	public:
		MedialibView (QWidget *parent);
};


#endif
