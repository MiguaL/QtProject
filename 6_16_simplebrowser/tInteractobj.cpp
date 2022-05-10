#include "tInteractobj.h"

TInteractObj::TInteractObj(QObject *parent)
    :QObject(parent)
{
}

TInteractObj::~TInteractObj()
{
}

void TInteractObj::global_GJavascriptToCplus(QString strParameter)
{
    emit SigReceivedMessFromJS(strParameter);
}
