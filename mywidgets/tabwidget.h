#ifndef TABWIDGET_H
#define TABWIDGET_H

#include <QWidget>
#include <QStackedWidget>

#include "labeltabbar.h"

class TabWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TabWidget(QWidget *parent = 0, QTabWidget::TabPosition pos = QTabWidget::East);

    ~TabWidget();

    typedef LabelTabBar TabBar;

//    int addTab(TabBar &tabbar, int index);
    QTabWidget::TabPosition position() const {return position_;}
    void setPosition(QTabWidget::TabPosition pos) {position_ = pos;}

    void addTab(QWidget *widget, const QPixmap &pixmap, int index = 0);

    QWidget *currentWidget() {return stackWidgets_->currentWidget();}


    void setTabPixmap(const QPixmap &pixmap, int index) {tabBar_->setTabPixmap(pixmap, index);}

signals:
    void currentChanged(int index);

public slots:
    void setCurrentIndex(int index);

protected:
    virtual void showEvent(QShowEvent *event) override;

private:
    Qt::Orientation layoutOrientation(QTabWidget::TabPosition pos);
    QPoint tabBarPosition();
    QRect mainRect();


private:
    TabBar *tabBar_;
    QStackedWidget *stackWidgets_;
    QTabWidget::TabPosition position_;
    int currentIndex_;
};

#endif // TABWIDGET_H
