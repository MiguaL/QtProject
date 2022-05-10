#ifndef TABWIDGET_H
#define TABWIDGET_H

#include <QWidget>
#include <QTabWidget>
#include <QWebEnginePage>

QT_BEGIN_NAMESPACE
class QUrl;
QT_END_NAMESPACE

class WebView;

class TabWidget : public QTabWidget
{
    Q_OBJECT

public:
    TabWidget(QWebEngineProfile *profile, QWidget *parent = nullptr);
    WebView *currentWebView() const;

public slots:
    // current tab/page slots
    void setUrl(const QUrl &url);

    WebView *createTab();
    WebView *createBackgroundTab();
private:
    WebView *webView(int index) const;

    QWebEngineProfile *m_profile;
};

#endif // TABWIDGET_H
