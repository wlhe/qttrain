#include "menuitem.h"

#include "icons.h"

#include <QResizeEvent>

MenuItem::MenuItem(QWidget *parent) :
    QWidget(parent),
    titleLabel_(new QLabel(this)),
    valueLabel_(new QLabel(this)),
    iconLabel_(new QLabel(this)),
    layoutOrientation_(Qt::Vertical)
{
    setupUi();
}

MenuItem::MenuItem(const QString &title, const QString &value, QWidget *parent, Qt::Orientation type) :
    QWidget(parent),
    titleLabel_(new QLabel(title, this)),
    valueLabel_(new QLabel(value, this)),
    iconLabel_(new QLabel(this)),
    layoutOrientation_(type)
{
    setupUi();
}

MenuItem::~MenuItem()
{
    delete titleLabel_;
    delete valueLabel_;
    delete iconLabel_;
}

void MenuItem::setLayoutOrientation(Qt::Orientation type)
{
    layoutOrientation_ = type;
    layoutItems();
}

void MenuItem::setBackground(const QColor &color)
{
    QPalette palete = palette();
    palete.setColor(QPalette::Background, color);
    setPalette(palete);
    setAutoFillBackground(true);
}

void MenuItem::setupUi()
{
    titleLabel_->setAlignment(Qt::AlignCenter);
    valueLabel_->setAlignment(Qt::AlignCenter);
    iconLabel_->setAlignment(Qt::AlignCenter);

    //  this->setStyleSheet(QString("border:1px solid rgb(80, 80, 80);"));
    //  this->setStyleSheet(QString("border-width:1px; border-style:solid solid none none;border-color:rgb(80, 80,
    //  80);"));
    titleLabel_->setStyleSheet(QString("border:none"));
    valueLabel_->setStyleSheet(QString("border:none"));
    iconLabel_->setStyleSheet(QString("border:none"));

    setBackground(QColor(40, 40, 40, 40));
    layoutItems();
}

void MenuItem::layoutItems()
{
    if (layout()) {
        delete layout();
    }

    QBoxLayout *bl = nullptr;
    if (layoutOrientation_ == Qt::Horizontal) {
        bl = new QHBoxLayout();
    } else {
        bl = new QVBoxLayout();
    }

    // for test
    if (!titleLabel_->text().isEmpty())
        iconLabel_->setPixmap(Icon::movie(true));
    bl->setSpacing(0);
    bl->setMargin(0);
    bl->setContentsMargins(0, 0, 0, 0);
    bl->addStretch();
    bl->addWidget(iconLabel_);
    bl->addStretch();
    bl->addWidget(titleLabel_);
    bl->addStretch();
    bl->addWidget(valueLabel_);
    bl->addStretch();

    setLayout(bl);
}

void MenuItem::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
}

void MenuItem::resizeEvent(QResizeEvent *event)
{
    //    Q_UNUSED(event);
    int w = event->size().width();
    int h = event->size().height();
    if (layoutOrientation_ == Qt::Horizontal) {
        w /= 3;
    } else {
        h /= 3;
    }

    iconLabel_->resize(w, h);
    valueLabel_->resize(w, h);
    titleLabel_->resize(w, h);
}
