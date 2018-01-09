#include "flatbutton.h"

#include <QResizeEvent>
#include <QStylePainter>

FlatButton::FlatButton(QWidget *parent) :
    QAbstractButton(parent),
    label(new QLabel(this))
{
}

FlatButton::FlatButton(const QPixmap &pixmap, QWidget *parent) :
    QAbstractButton(parent),
    label(new QLabel(this))
{
    label->setPixmap(pixmap);
    resize(pixmap.size());
}

FlatButton::FlatButton(const QString &text, QWidget *parent) :
    QAbstractButton(parent),
    label(new QLabel(text, this))
{
}

FlatButton::~FlatButton()
{
    delete label;
}

void FlatButton::init()
{
    setObjectName(QString(QStringLiteral("_flat_button")));
    label->setObjectName(QString(QStringLiteral("_label")));
}

void FlatButton::setPixmap(const QPixmap &pixmap){
    label->setPixmap(pixmap);
    label->resize(pixmap.size());
    this->resize(pixmap.size());
}

void FlatButton::setText(const QString &text)
{
    label->setText(text);
}

void FlatButton::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    // TODO: draw outline
}

