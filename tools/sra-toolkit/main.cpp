/*===========================================================================
*
*                            PUBLIC DOMAIN NOTICE
*               National Center for Biotechnology Information
*
*  This software/database is a "United States Government Work" under the
*  terms of the United States Copyright Act.  It was written as part of
*  the author's official duties as a United States Government employee and
*  thus cannot be copyrighted.  This software/database is freely available
*  to the public for use. The National Library of Medicine and the U.S.
*  Government have not placed any restriction on its use or reproduction.
*
*  Although all reasonable efforts have been taken to ensure the accuracy
*  and reliability of the software and data, the NLM and the U.S.
*  Government do not and cannot warrant the performance or results that
*  may be obtained by using this software or data. The NLM and the U.S.
*  Government disclaim all warranties, express or implied, including
*  warranties of performance, merchantability or fitness for any particular
*  purpose.
*
*  Please cite the author in any work or product based on this material.
*
* ===========================================================================
*
*/

#include "sratoolkit.h"
#include "sratoolkitglobals.h"

#include <QApplication>
#include <QDesktopWidget>
#include <QFile>
#include <QPoint>

SRAToolkitTemplate * sraTemplate;

int main ( int argc, char *argv [] )
{
    QApplication a ( argc, argv );

#if OFFICAL_LOOKNFEEL
    sraTemplate = new SRAToolkitTemplate ( Official );
    QFile qss ( qss_path + "official_style.qss" );
#elif MODERN_LOOKNFEEL
    sraTemplate = new SRAToolkitTemplate ( Modern );
    QFile qss ( qss_path + "modern_style.qss" );
#elif DARKGLASS_LOOKNFEEL
    sraTemplate = new SRAToolkitTemplate ( DarkGlass );
    QFile qss ( qss_path + "darkglass_style.qss" );
#endif

    qss.open ( QFile::ReadOnly );
    a . setStyleSheet ( qss . readAll () );
    qss.close ();

    const QRect avail_geometry =
            QApplication :: desktop () -> availableGeometry ( QPoint ( 0, 0 ) );

    SRAToolkit window ( avail_geometry );

    window . show();

    int status = a . exec ();

    delete sraTemplate;

    return status;
}