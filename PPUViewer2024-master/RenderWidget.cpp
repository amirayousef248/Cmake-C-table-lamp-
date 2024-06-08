//
// copyright 2018 Palestine Polytechnic Univeristy
//
// This software can be used and/or modified for academich use as long as 
// this commented part is listed
//
// Last modified by: Zein Salah, on 24.02.2021
//

#include "RenderWidget.h"
#include <QPainter>

RenderWidget::RenderWidget(QWidget* parent) : QWidget(parent)
{

}

QSize RenderWidget::minimumSizeHint() const
{
    return QSize(100, 100);
}

QSize RenderWidget::sizeHint() const
{
    return QSize(600, 600);
}

void RenderWidget::paintEvent(QPaintEvent*)
{
    QPainter painter(this);


    QColor color(0, 0, 0);
    painter.setPen(color);

    painter.drawRect(QRect(0, 0, width() - 1, height() - 1));

    myDrawLine(45, 190, 145, 190);
    drawEllipse(95, 190, 50, 20);

    myDrawLine(100, 170, 100, 115);
    myDrawLine(90, 170, 90, 115);


    drawCircle(95, 95, 5);
    drawCircle(95, 95, 20);

    myDrawLine(100, 75, 110, 50);
    myDrawLine(95, 75, 110, 40);

    drawArc(160, 50, 70, 270, 30);
    myDrawLine(170, 20, 157, 80);

    drawArc(130, 50, 70, 290, 20);

    drawCircle(164, 50, 10);

}

void RenderWidget::myDrawLine(float x1, float y1, float x2, float y2)
{
    QPainter painter(this);

    QColor color(0, 0, 0);
    painter.setPen(color);

    float dx = abs(x2 - x1);
    float dy = abs(y2 - y1);
    float sx = (x1 < x2) ? 1 : -1;
    float sy = (y1 < y2) ? 1 : -1;
    float err = dx - dy;
    float e2;
    while (true) {
        painter.drawLine(QPointF(x1, y1), QPointF(x2, y2));
        if (x1 == x2 && y1 == y2)
            break;
        e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
}
void RenderWidget::drawEllipse(int xc, int yc, int a, int b) {

    QPainter painter(this);
    QColor color(0, 0, 0);
    painter.setPen(color);
    double theta = 0;
    double delta_theta = 1.0 / a;

    while (theta <= 3.1415) {
        int x = xc + a * cos(theta);
        int y = yc - b * sin(theta);
        painter.drawPoint(x, y);
        theta += delta_theta;
    }

}

void RenderWidget::drawCircle(int xc, int yc, int r) {
    QPainter painter(this);
    QColor color(0, 0, 0);
    painter.setPen(color);
    int x = r;
    int y = 0;
    int radiusError = 1 - x;

    while (x >= y) {
        painter.drawPoint(xc + x, yc + y);
        painter.drawPoint(xc - x, yc + y);
        painter.drawPoint(xc + x, yc - y);
        painter.drawPoint(xc - x, yc - y);
        painter.drawPoint(xc + y, yc + x);
        painter.drawPoint(xc - y, yc + x);
        painter.drawPoint(xc + y, yc - x);
        painter.drawPoint(xc - y, yc - x);

        y++;

        if (radiusError < 0)
            radiusError += 2 * y + 1;
        else {
            x--;
            radiusError += 2 * (y - x + 1);
        }
    }
}

void RenderWidget::drawArc(int xc, int yc, int theta1, int theta2, int r) {
    QPainter painter(this);
    QColor color(0, 0, 0);
    painter.setPen(color);

    double theta = theta1 * 3.1415 / 180;
    double delta_theta = 1.0 / r;

    while (theta <= theta2 * 3.1415 / 180) {
        int x = xc + r * cos(theta);
        int y = yc - r * sin(theta);

        painter.drawPoint(x, y);
        theta += delta_theta;
    }
}







