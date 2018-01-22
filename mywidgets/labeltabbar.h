#ifndef LABELTABBAR_H
#define LABELTABBAR_H

#include <QWidget>
#include <QList>
#include <QLabel>
#include <QTabWidget>
#include <QSize>
#include <QMouseEvent>

class TabLabel : public QLabel
{
    Q_OBJECT
public:

    TabLabel(int index = 0, QWidget *parent = Q_NULLPTR) :
        QLabel(parent), index_(index){}

    signals:
    void clicked(int index);
protected:
    virtual void mousePressEvent(QMouseEvent *event) {
        if(event->button() == Qt::LeftButton) {
            emit clicked(index_);
        }
    }

private:
    int index_;

};

class LabelTabBar : public QWidget
{
    Q_OBJECT
public:
    explicit LabelTabBar(QWidget *parent = 0);
    explicit LabelTabBar(QSize &size, QWidget *parent = 0);
    ~LabelTabBar();

    int addTab(const QPixmap &pixmap, int index = 0);
    int addTab(const QString &text, int index = 0);

    int removeTab(int index);

    // properties
    void setLayoutOrientation(Qt::Orientation type) {
        layoutOrientation_ = type;
    }
    int currentIndex() {return currentIndex();}
    QWidget * getTab(int index) {return tabList_.at(index);}

    QSize tabSize(int index) {return tabList_[index]->size();}
    void setTabSize(QSize &size, int index) {tabList_[index]->resize(size);}

    void setTabPixmap(const QPixmap &pixmap, int index) {tabList_[index]->setPixmap(pixmap); }

signals:
    void currentChanged(int index);

public slots:
    void setCurrentIndex(int index);

private:
    void layoutTabs(void);


private:
    int currentIndex_;

    Qt::Orientation layoutOrientation_;

    QVector <TabLabel *> tabList_;
};

#endif // LABELTABBAR_H
