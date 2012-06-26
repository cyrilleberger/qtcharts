/****************************************************************************
**
** Copyright (C) 2012 Digia Plc
** All rights reserved.
** For any questions to Digia, please use contact form at http://qt.digia.com
**
** This file is part of the Qt Commercial Charts Add-on.
**
** $QT_BEGIN_LICENSE$
** Licensees holding valid Qt Commercial licenses may use this file in
** accordance with the Qt Commercial License Agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia.
**
** If you have questions regarding the use of this file, please use
** contact form at http://qt.digia.com
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QABSTRACTAXIS_H
#define QABSTRACTAXIS_H

#include <qchartglobal.h>
#include <QPen>
#include <QFont>
#include <QVariant>

QTCOMMERCIALCHART_BEGIN_NAMESPACE

class QAbstractAxisPrivate;

class QTCOMMERCIALCHART_EXPORT QAbstractAxis : public QObject
{
	Q_OBJECT

    Q_PROPERTY(bool visible READ isAxisVisible WRITE setAxisVisible NOTIFY visibleChanged)
    Q_PROPERTY(QColor color READ axisPenColor WRITE setAxisPenColor NOTIFY colorChanged)
    Q_PROPERTY(bool labelsVisible READ labelsVisible WRITE setLabelsVisible NOTIFY labelsVisibleChanged)
    Q_PROPERTY(int labelsAngle READ labelsAngle WRITE setLabelsAngle)
    Q_PROPERTY(QFont labelsFont READ labelsFont WRITE setLabelsFont)
    Q_PROPERTY(QColor labelsColor READ labelsColor WRITE setLabelsColor NOTIFY labelsColorChanged)
    Q_PROPERTY(bool gridVisible READ isGridLineVisible WRITE setGridLineVisible NOTIFY gridVisibleChanged)
    Q_PROPERTY(bool shadesVisible READ shadesVisible WRITE setShadesVisible NOTIFY shadesVisibleChanged)
    Q_PROPERTY(QColor shadesColor READ shadesColor WRITE setShadesColor NOTIFY shadesColorChanged)
    Q_PROPERTY(QColor shadesBorderColor READ shadesBorderColor WRITE setShadesBorderColor NOTIFY shadesBorderColorChanged)
    //Q_PROPERTY(qreal min READ min WRITE setMin NOTIFY minChanged)
    //Q_PROPERTY(qreal max READ max WRITE setMax NOTIFY maxChanged)

public:

    enum AxisType {
        AxisTypeValues,
        AxisTypeCategories
    };

protected:
    explicit QAbstractAxis(QAbstractAxisPrivate &d,QObject *parent = 0);

public:
    ~QAbstractAxis();

    virtual AxisType type() const = 0;

    //axis handling
    bool isAxisVisible() const;
    void setAxisVisible(bool visible = true);
    void setAxisPen(const QPen &pen);
    QPen axisPen() const;
    void setAxisPenColor(QColor color);
    QColor axisPenColor() const;

    //grid handling
    bool isGridLineVisible() const;
    void setGridLineVisible(bool visible = true);
    void setGridLinePen(const QPen &pen);
    QPen gridLinePen() const;

    //labels handling
    bool labelsVisible() const;
    void setLabelsVisible(bool visible = true);
    void setLabelsPen(const QPen &pen);
    QPen labelsPen() const;
    void setLabelsBrush(const QBrush &brush);
    QBrush labelsBrush() const;
    void setLabelsFont(const QFont &font);
    QFont labelsFont() const;
    void setLabelsAngle(int angle);
    int labelsAngle() const;
    void setLabelsColor(QColor color);
    QColor labelsColor() const;

    //shades handling
    bool shadesVisible() const;
    void setShadesVisible(bool visible = true);
    void setShadesPen(const QPen &pen);
    QPen shadesPen() const;
    void setShadesBrush(const QBrush &brush);
    QBrush shadesBrush() const;
    void setShadesColor(QColor color);
    QColor shadesColor() const;
    void setShadesBorderColor(QColor color);
    QColor shadesBorderColor() const;

    //range handling
    virtual void setMin(QVariant min) = 0;
    virtual void setMax(QVariant max) = 0 ;
    virtual void setRange(QVariant min, QVariant max) = 0;

    virtual int ticksCount() const = 0;

    void show();
    void hide();

Q_SIGNALS:
    void visibleChanged(bool visible);
    void labelsVisibleChanged(bool visible);
    void gridVisibleChanged(bool visible);
    void colorChanged(QColor color);
    void labelsColorChanged(QColor color);
    void shadesVisibleChanged(bool visible);
    void shadesColorChanged(QColor color);
    void shadesBorderColorChanged(QColor color);

protected:
	QScopedPointer<QAbstractAxisPrivate> d_ptr;
    Q_DISABLE_COPY(QAbstractAxis);
    friend class ChartDataSet;
    friend class ChartAxis;
};

QTCOMMERCIALCHART_END_NAMESPACE
#endif
