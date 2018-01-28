#ifndef MENUITEM_H
#define MENUITEM_H

#include <QBoxLayout>
#include <QFrame>
#include <QIcon>
#include <QLabel>
#include <QWidget>

class ListItem : public QWidget
{
    Q_OBJECT
public:
    explicit ListItem(QWidget *parent = 0) :
        QWidget(parent),
        valueLabel_(new QLabel(this)),
        pixLabel_(new QLabel(this)) {

    }
    ~ListItem() {}
    void setValue(const QString &value) {valueLabel_->setText(value);}
    void setPixmap(const QPixmap &pixmap) {pixLabel_->setPixmap(pixmap);}

protected:
    virtual void resizeEvent(QResizeEvent */*event*/) {
        valueLabel_->setGeometry(0, 0, width() - height(), height());
        pixLabel_->setGeometry(width() - height(), 0, height(), height());
    }


private:
    QLabel *valueLabel_;
    QLabel *pixLabel_;
};

class MenuItem : public QWidget
{
    Q_OBJECT
public:
    explicit MenuItem(QWidget *parent = 0);
    explicit MenuItem(const QString &title,
                      const QString &value,
                      QWidget *parent = 0,
                      Qt::Orientation type = Qt::Vertical);
    virtual ~MenuItem();

    void setLayoutOrientation(Qt::Orientation type);
    void setBackground(const QColor &color);
    void setTitle(const QString &title) {titleLabel_->setText(title);}
    void setValue(const QString &value) {valueLabel_->setText(value);}
    void setIcon(const QPixmap &icon) {iconLabel_->setPixmap(icon);}

    void setSelected(bool select) {selected_ = select;}
    void setEnabled(bool enable) {enabled_ = enable;}
    void setCheckable(bool check) {checkable_ = check;}

signals:

public slots:

protected:
    virtual void paintEvent(QPaintEvent *event) override;
    virtual void resizeEvent(QResizeEvent *event) override;

private:
    void setupUi();
    void layoutItems();

private:
    QLabel *titleLabel_;
    QLabel *valueLabel_;
    QLabel *iconLabel_;

    bool selected_;
    bool enabled_;
    bool checkable_;

    Qt::Orientation layoutOrientation_;
};

#endif // MENUITEM_H
