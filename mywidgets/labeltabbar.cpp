#include "labeltabbar.h"

#include <QBoxLayout>

LabelTabBar::LabelTabBar(QWidget *parent) :
    QWidget(parent),
    currentIndex_(0),
    layoutOrientation_(Qt::Horizontal)
{
}

LabelTabBar::LabelTabBar(QSize &size, QWidget *parent) :
    QWidget(parent),
    currentIndex_(0),
    layoutOrientation_(Qt::Horizontal)
{
    resize(size);
}

LabelTabBar::~LabelTabBar()
{
    for (auto &tab : tabList_) {
        delete tab;
    }
}

int LabelTabBar::addTab(const QPixmap &pixmap, int index)
{
    TabLabel *tb = nullptr;
    if(index == 0) {
        // insert back
        index = tabList_.size();
        tb = new TabLabel(index, this);
        tb->setPixmap(pixmap);
        tb->resize(pixmap.size());
    } else {
        // TODO: insert tab anywhere
    }
    connect(tb, &TabLabel::clicked, this, &LabelTabBar::setCurrentIndex);
    tabList_.push_back(tb);
    layoutTabs();
    return tabList_.size();
}

int LabelTabBar::addTab(const QString &text, int index)
{
    TabLabel *tb = nullptr;
    if(index == 0) {
        // insert back
        index = tabList_.size();
        tb = new TabLabel(index, this);
        tb->setText(text);
    } else {
        // TODO:
    }
    tabList_.push_back(tb);
    layoutTabs();
    return tabList_.size();
}

int LabelTabBar::removeTab(int index)
{
    tabList_.removeAt(index);
    if(currentIndex_ >= tabList_.size()) {
        currentIndex_ = tabList_.size() - 1;
    }
    return tabList_.size();
}

void LabelTabBar::setCurrentIndex(int index)
{
    if(index < tabList_.size()){
        currentIndex_ = index;
    }
    emit currentChanged(index);
}

void LabelTabBar::layoutTabs(void)
{
    if(layout()) {
        delete layout();
    }

    QBoxLayout *bl = nullptr;
    if(layoutOrientation_ == Qt::Horizontal){
        bl = new QHBoxLayout();
    } else {
        bl = new QVBoxLayout();
    }
    bl->setSpacing(0);
    bl->setMargin(0);
    bl->setContentsMargins(0,0,0,0);
    for (auto &t : tabList_) {
        bl->addWidget(t);
    }

    setLayout(bl);
}
