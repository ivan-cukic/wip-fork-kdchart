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

#include <QApplication>
#include <KDChartWidget>
#include <KDChartBarDiagram>
#include <KDChartPosition>
#include <KDChartLegend>


using namespace KDChart;

int main( int argc, char** argv ) {
    QApplication app( argc, argv );

    Widget widget;
    widget.resize( 600, 600 );

    QVector< qreal > vec0,  vec1,  vec2;

    vec0 << -5 << -4 << -3 << -2 << -1 << 0
         << 1 << 2 << 3 << 4 << 5;
    vec1 << 25 << 16 << 9 << 4 << 1 << 0
         << 1 << 4 << 9 << 16 << 25;
    vec2 << -125 << -64 << -27 << -8 << -1 << 0
         << 1 << 8 << 27 << 64 << 125;

    widget.setDataset( 0, vec0, "v0" );
    widget.setDataset( 1, vec1, "v1" );
    widget.setDataset( 2, vec2, "v2" );
    widget.setType( Widget::Bar );
 
    Legend* legend = new Legend( widget.diagram(), &widget );
    legend->setOrientation( Qt::Horizontal );
    legend->setTitleText( "Bars Legend" );
    legend->setText( 0,  "Vector 1" );
    legend->setText( 1,  "Vector 2" );
    legend->setText( 2,  "Vector 3" );
    legend->setShowLines(  true );

    // The following aligns the legend exactly to the
    // chart's coordinate plane's top-right corner.
    //
    // Note: We do NOT use Legend::setAlignment here, because when
    //       setRelativePosition is used the alignment is set at the
    //       KDChart::RelativePosition rather than at the KDChart::Legend.
    KDChart::RelativePosition relativePosition;
    relativePosition.setReferenceArea( widget.coordinatePlane() );
    relativePosition.setReferencePosition( Position::NorthEast );
    relativePosition.setAlignment( Qt::AlignTop | Qt::AlignRight );
    relativePosition.setHorizontalPadding( KDChart::Measure( -1.0, KDChartEnums::MeasureCalculationModeAbsolute ) );
    relativePosition.setVerticalPadding(   KDChart::Measure(  1.0, KDChartEnums::MeasureCalculationModeAbsolute ) );
    legend->setFloatingPosition( relativePosition );

    widget.addLegend( legend );

    widget.show();

    return app.exec();
}
