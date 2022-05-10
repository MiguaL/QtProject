#ifndef TINTERACT_OBJECT_H
#define TINTERACT_OBJECT_H

#include <QObject>

class TInteractObj : public QObject
{
    Q_OBJECT

public:
    TInteractObj(QObject *parent);
    ~TInteractObj();
    // 页面端调用Qt公共接口，必须添加 Q_INVOKABLE宏，否则无法调用
    Q_INVOKABLE void global_GJavascriptToCplus(QString strParameter);       //Called by JS: Send message to Qt

signals:
    void SigReceivedMessFromJS(QString strParameter);          //Receive message from Web

    void SigSendMessageToJS(QString strParameter);             //Send message to Web
};


#endif //TINTERACT_OBJECT_H
