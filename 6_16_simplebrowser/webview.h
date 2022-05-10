#ifndef WEBVIEW_H
#define WEBVIEW_H

#include <QIcon>
#include <QWebEngineView>

class WebPage;

class WebView : public QWebEngineView{
    Q_OBJECT

public:
    WebView(QWidget *parent = nullptr);
    void setPage(WebPage *page);
signals:
    void webActionEnabledChanged(QWebEnginePage::WebAction webAction, bool enabled);

private:
    void createWebActionTrigger(QWebEnginePage *page, QWebEnginePage::WebAction);

private:
    int m_loadProgress;
};

#endif // WEBVIEW_H
