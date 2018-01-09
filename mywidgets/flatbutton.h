#ifndef FLATBUTTON_H
#define FLATBUTTON_H

#include <QWidget>
#include <QLabel>
#include <QAbstractButton>

class FlatButton : public QAbstractButton
{
    Q_OBJECT
public:
    FlatButton(QWidget *parent=nullptr);
    FlatButton(const QPixmap &pixmap, QWidget *parent=nullptr);
    FlatButton(const QString &text, QWidget *parent=nullptr);
    ~FlatButton();

    void setPixmap(const QPixmap &pixmap);
    void setText(const QString &text);

    inline bool checked() {return checked();}

protected:
    virtual void paintEvent(QPaintEvent *event) override;

private:
    void init();
private:
    QLabel *label;
};

#endif // FLATBUTTON_H
