/****************************************************************************
** Copyright (C) 2001-2019 Klaralvdalens Datakonsult AB.  All rights reserved.
**
** This file is part of the KD Chart library.
**
** Licensees holding valid commercial KD Chart licenses may use this file in
** accordance with the KD Chart Commercial License Agreement provided with
** the Software.
**
**
** This file may be distributed and/or modified under the terms of the
** GNU General Public License version 2 and version 3 as published by the
** Free Software Foundation and appearing in the file LICENSE.GPL.txt included.
**
** This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
** WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
**
** Contact info@kdab.com if any conditions of this licensing are not
** clear to you.
**
**********************************************************************/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"
#include <TableModel.h>

QT_BEGIN_NAMESPACE
class QTimer;
QT_END_NAMESPACE
namespace KDChart {
    class Chart;
    class PieDiagram;
}

class MainWindow : public QWidget, private Ui::MainWindow
{
    Q_OBJECT

public:
    MainWindow( QWidget* parent = 0 );

private slots:
    // start position
    void on_startPositionSB_valueChanged( double pos );
    void on_startPositionSL_valueChanged( int pos );

    // explode
    void on_explodeSubmitPB_clicked();
    void on_animateExplosionCB_toggled( bool toggle );
    void setExplodeFactor( int column, qreal value );

    // animation
    void slotNextFrame();

    // 3D
    void on_threeDGB_toggled( bool toggle );
    void on_threeDFactorSB_valueChanged( int factor );

private:
    KDChart::Chart* m_chart;
    TableModel m_model;
    KDChart::PieDiagram* m_pie;
    QTimer* m_timer;

    int m_currentFactor;
    int m_currentDirection;
    int m_currentSlice;
};


#endif /* MAINWINDOW_H */

