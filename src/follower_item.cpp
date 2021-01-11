#include "../include/wpr_command_center/follower_item.h"

static const double Pi = 3.14159265358979323846264338327950288419717;
static double TwoPi = 2.0 * Pi;
static float arrowSize = 15.0;

CFollowerItem::CFollowerItem()
{
    pntSrc = QPointF(0,0);
    pntDest = QPointF(0,0);
    penLink.setWidth(2); 
    penLink.setColor(Qt::green);
    penLink.setStyle(Qt::DashLine);
}

CFollowerItem::~CFollowerItem()
{

}

void CFollowerItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget * /* widget */)
{
    painter->setRenderHint(QPainter::Antialiasing, true);
    QLineF line(pntSrc,pntDest);
    if (qFuzzyCompare(line.length(), qreal(0.)))
    {
        return;
    }
    painter->setPen(penLink);
    painter->drawLine(line);
}

 QRectF CFollowerItem::boundingRect() const
 {
    float left = pntSrc.x();
    if(left > pntDest.x())
        left = pntDest.x();
    float top = pntSrc.y();
    if(top > pntDest.y())
        top = pntDest.y();
    float right = pntSrc.x();
    if(right < pntDest.x())
        right = pntDest.x();
    float bottom = pntSrc.y();
    if(bottom < pntDest.y())
        bottom = pntDest.y();
    float width = right - left;
    float height = bottom - top;
    QRectF rect(left,top,width,height);
     return rect;
 }
