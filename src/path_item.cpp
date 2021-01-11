#include "../include/wpr_command_center/path_item.h"

static const double Pi = 3.14159265358979323846264338327950288419717;
static double TwoPi = 2.0 * Pi;
static float arrowSize = 15.0;

CPathItem::CPathItem()
{
    penPath.setWidth(2); 
    penPath.setColor(Qt::red);
    penMouse.setWidth(1); 
    penMouse.setColor(Qt::red);
    penMouse.setStyle(Qt::DashLine);
    bDrawMouse = false;
}

CPathItem::~CPathItem()
{

}

void CPathItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget * /* widget */)
{
     if(pathHolder.arPoint.size() >0)
    {
        painter->setRenderHint(QPainter::Antialiasing, true);
        painter->setPen(penPath); 

        float tmp_x = pathHolder.arPoint[0].x*-100;
        float tmp_y = pathHolder.arPoint[0].y*100;
        pntLast = QPointF(tmp_x,tmp_y);
        int nNumOfPoints = pathHolder.arPoint.size();
        for(int i=1;i<nNumOfPoints;i++)
        {
            float tmp_x = pathHolder.arPoint[i].x*-100;
            float tmp_y = pathHolder.arPoint[i].y*100;
            pntCur =  QPointF(tmp_x,tmp_y);
            QLineF line(pntLast,pntCur);
            painter->drawLine(line);
            pntLast = pntCur;
        }
        if(bDrawMouse == true)
        {
            painter->setPen(penMouse); 
            QLineF line(pntLast,pntMouse);
            painter->drawLine(line);
        }
    }
}

 QRectF CPathItem::boundingRect() const
 {
    float left =0;
    float right = 0;
    float top = 0;
    float bottom = 0;
    if(pathHolder.arPoint.size() >0)
    {
        for(int i=0;i<pathHolder.arPoint.size();i++)
        {
            float tmp_x = pathHolder.arPoint[i].x*-100;
            float tmp_y = pathHolder.arPoint[i].y*100;
            if(left > tmp_x)
                left = tmp_x;
            if(top > tmp_y)
                top = tmp_y;
            if(right < tmp_x)
                right = tmp_x;
            if(bottom < tmp_y)
                bottom = tmp_y;
        }
         if(bDrawMouse == true)
         {
            float tmp_x = pntMouse.x();
            float tmp_y = pntMouse.y();
            if(left > tmp_x)
                left = tmp_x;
            if(top > tmp_y)
                top = tmp_y;
            if(right < tmp_x)
                right = tmp_x;
            if(bottom < tmp_y)
                bottom = tmp_y;
         }
    }
    float width = right - left;
    float height = bottom - top;
    QRectF rect(left,top,width,height);
     return rect;
 }
