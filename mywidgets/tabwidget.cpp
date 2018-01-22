#include "tabwidget.h"

TabWidget::TabWidget(QWidget *parent, QTabWidget::TabPosition pos) :
    QWidget(parent),
    tabBar_(new TabBar(this)),
    stackWidgets_(new QStackedWidget(this)),
    position_(pos)
{
    tabBar_->setLayoutOrientation(layoutOrientation(position()));
    connect(tabBar_, &TabBar::currentChanged, this, &TabWidget::setCurrentIndex);
//    stackWidgets_->setLineWidth(0);
}

TabWidget::~TabWidget()
{
    delete tabBar_;
    delete stackWidgets_;
}

void TabWidget::addTab(QWidget *widget, const QPixmap &pixmap, int index)
{
    tabBar_->addTab(pixmap, index);
    stackWidgets_->setGeometry(mainRect());
    stackWidgets_->addWidget(widget);
}

void TabWidget::setCurrentIndex(int index)
{
    currentIndex_ = index;
    stackWidgets_->setCurrentIndex(currentIndex_);
    stackWidgets_->update();
    emit currentChanged(index);
}

Qt::Orientation TabWidget::layoutOrientation(QTabWidget::TabPosition pos)
{
    if(pos == QTabWidget::North || pos == QTabWidget::South) {
        return Qt::Horizontal;
    } else {
        return Qt::Vertical;
    }
}

void TabWidget::showEvent(QShowEvent *event)
{
    Q_UNUSED(event);
    stackWidgets_->setCurrentIndex(currentIndex_);
    tabBar_->move(tabBarPosition());
    tabBar_->show();
    stackWidgets_->show();
}

QPoint TabWidget::tabBarPosition()
{
    int x = 0, y = 0;
    switch (position()) {
    case QTabWidget::North:
        x = 0;
        y = 0;
        break;
    case QTabWidget::South:
        x = 0;
        y = height() - tabBar_->height();
        break;
    case QTabWidget::East:
        x = width() - tabBar_->width();
        y = 0;
        break;
    case QTabWidget::West:
        x = 0;
        y = 0;
        break;
    default:
        break;
    }
    return QPoint(x, y);
}

QRect TabWidget::mainRect()
{
    int x = 0, y = 0;
    int w = 0, h = 0;
    switch (position()) {
    case QTabWidget::North:
        x = 0;
        y = tabBar_->height();
        w = width();
        h = height() - tabBar_->height();
        break;
    case QTabWidget::South:
        x = 0;
        y = 0;
        w = width();
        h = height() - tabBar_->height();
        break;
    case QTabWidget::East:
        x = 0;
        y = 0;
        w = width() - tabBar_->width();
        h = height();
        break;
    case QTabWidget::West:
        x = width();
        y = 0;
        w = width() - tabBar_->width();
        h = height();
        break;
    default:
        break;
    }
    return QRect(x, y, w, h);
}
