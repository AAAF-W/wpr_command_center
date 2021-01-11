#ifndef     WPR_M_PATH_ITEM
#define     WPR_M_PATH_ITEM

#include <QGraphicsItem>
#include <QStyleOptionGraphicsItem>
#include <QPen>
#include <QStyle>
#include <QPainter>
#include <math.h>
#include "PathHolder.h"

class CPathItem : public QGraphicsItem
{
    public:
        CPathItem();
        ~CPathItem();
        QPen penPath;
        QPen penMouse;
        CPathHolder pathHolder;
        QPointF pntLast;
        QPointF pntCur;
        QPointF pntMouse;
        bool bDrawMouse;

    private:
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget * /* widget */);
        QRectF boundingRect() const;
};

#endif //WPR_M_PATH_ITEM