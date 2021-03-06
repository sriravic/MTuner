//--------------------------------------------------------------------------//
/// Copyright (c) 2017 by Milos Tosic. All Rights Reserved.                ///
/// License: http://www.opensource.org/licenses/BSD-2-Clause               ///
//--------------------------------------------------------------------------//

#ifndef __RTM_MTUNER_HEAPSWIDGET_H__
#define __RTM_MTUNER_HEAPSWIDGET_H__

#include <mtuner/.qt/qt_ui/heapswidget_ui.h>

struct CaptureContext;

class HeapsWidget : public QWidget
{
	Q_OBJECT

private:
	QTreeWidget*	m_treeWidget;
	CaptureContext*	m_context;

public:
	HeapsWidget(QWidget* _parent = 0, Qt::WindowFlags _flags = 0);

	void changeEvent(QEvent* _event);
	void setContext(CaptureContext* _capture);
	void setCurrentHeap(uint64_t _handle);

public Q_SLOTS:
	void ItemChanged(QTreeWidgetItem*, QTreeWidgetItem*);

Q_SIGNALS:
	void heapSelected(uint64_t);

private:
	Ui::HeapsWidget ui;
};

#endif // __RTM_MTUNER_HEAPSWIDGET_H__
