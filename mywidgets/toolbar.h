#ifndef TOOLBAR_H
#define TOOLBAR_H

#include <QWidget>
#include <QVector>
#include <QLabel>

class ToolBar : public QWidget
{
    Q_OBJECT
public:
    explicit ToolBar(int number, QWidget *parent = nullptr, Qt::Orientation orientation = Qt::Horizontal);
    virtual ~ToolBar();

    QLabel *label(int index) {return labels_[index];}

    void setLabelText(const QString &text, int index) {
        labels_[index]->setText(text);
    }
    void setLabelPixmap(const QPixmap &pixmap, int index) {
        labels_[index]->setPixmap(pixmap);
    }

signals:
    void clicked(int index);

public slots:

protected:
    virtual void mousePressEvent(QMouseEvent *event) override;

    void mouseMoveEvent(QMouseEvent *event);

private:
    void setupUi();
    int getIndex(const QPoint &pos);
    void layoutLabels();

private:
    QVector <QLabel *> labels_;
    Qt::Orientation orientation_;
    int index_;
};

#endif // TOOLBAR_H
