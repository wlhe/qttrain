#include "toolbar.h"

#include <QBoxLayout>
#include <QMouseEvent>

ToolBar::ToolBar(int number, QWidget *parent, Qt::Orientation orientation)
    : QWidget(parent), orientation_(orientation), index_(0)
{
    if (number <= 0) {
        number = 1;
    }
    for (int i = 0; i < number; ++i) {
        labels_.push_back(new QLabel(this));
    }

    setupUi();
}

ToolBar::~ToolBar()
{

}

void ToolBar::mousePressEvent(QMouseEvent *event)
{
    qDebug("[%d, %d]", event->x(), event->y());
    if(event->button() == Qt::LeftButton) {
        int index_ = getIndex(event->pos());
        qDebug("index %d", index_);
        emit clicked(index_);
    } else {
        return QWidget::mousePressEvent(event);
    }
}
void ToolBar::mouseMoveEvent(QMouseEvent *event)
{
    qDebug("[%d, %d]", event->x(), event->y());
}

void ToolBar::setupUi()
{
    for (auto &l : labels_) {
        l->setAlignment(Qt::AlignCenter);
    }

    layoutLabels();
}

int ToolBar::getIndex(const QPoint &pos)
{
    int index = 0;
    if(orientation_ == Qt::Horizontal){
        index = pos.x() / labels_[0]->width();
    } else {
        index = pos.y() / labels_[0]->height();
    }
    return index;
}

void ToolBar::layoutLabels()
{
    if(layout()) {
        delete layout();
    }

    QBoxLayout *bl = nullptr;
    if(orientation_ == Qt::Horizontal){
        bl = new QHBoxLayout();
    } else {
        bl = new QVBoxLayout();
    }
    bl->setSpacing(0);
    bl->setMargin(0);
    bl->setContentsMargins(0,0,0,0);
    for (auto &l : labels_) {
        bl->addWidget(l);
    }

    setLayout(bl);
}
