#ifndef     WPR_M_FOLLOWER_ITEM
#define     WPR_M_FOLLOWER_ITEM

#include <QGraphicsItem>
#include <QStyleOptionGraphicsItem>
#include <QPen>
#include <QStyle>
#include <QPainter>
#include <math.h>

class CFollowerItem : public QGraphicsItem
{
    public:
        CFollowerItem();
        ~CFollowerItem();
        QPointF pntSrc;
        QPointF pntDest;
        QPen penLink;

    private:
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget * /* widget */);
        QRectF boundingRect() const;
};

#endif //WPR_M_FOLLOWER_ITEM