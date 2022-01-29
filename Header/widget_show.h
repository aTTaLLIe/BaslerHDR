#ifndef WIDGET_SHOW_H
#define WIDGET_SHOW_H

#include <QLabel>
#include <memory>
#include <QPainter>

class Widget_Show : public QLabel
{

public:
    Widget_Show(QLabel * parent = nullptr) : QLabel(parent)
    {
        m_ptr_image = std::unique_ptr<QImage>{new QImage()};
    }
    ~Widget_Show()
    {

    }

    void paintEvent(QPaintEvent *event)
    {
        QPainter paint_img(this);
        setAttribute(Qt::WA_OpaquePaintEvent);
        paint_img.drawImage(0, 0, m_ptr_image);
    }

public slots:
    void DrawIamge(QImage img)
    {
        m_ptr_image = img;
        update();
    }
private:
    QImage m_ptr_image;
}


#endif // WIDGET_SHOW_H
