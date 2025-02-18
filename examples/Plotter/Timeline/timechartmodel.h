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

#ifndef TIMECHARTMODEL_H
#define TIMECHARTMODEL_H

#include <QDateTime>
#include <QSortFilterProxyModel>
#include <QPair>

class TimeChartModel : public QSortFilterProxyModel
{
    Q_OBJECT
public:
    explicit TimeChartModel( QObject* parent = 0 );

    QPair< QDateTime, QDateTime > visibleRange() const;
    
public Q_SLOTS:
    void setVisibleRange( const QDateTime& start, const QDateTime& end );
    void setVisibleStart( const QDateTime& start );
    void setVisibleEnd( const QDateTime& end );

    QVariant data( const QModelIndex& index, int role = Qt::DisplayRole ) const;

protected:
    bool filterAcceptsRow( int source_row, const QModelIndex& source_parent ) const;

private:
    QPair< QDateTime, QDateTime > range;
};

#endif
