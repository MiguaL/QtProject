#include "tabwidget.h"
#include "webview.h"
#include "webpage.h"

TabWidget::TabWidget(QWebEngineProfile *profile, QWidget *parent)
    : QTabWidget(parent)
    , m_profile(profile)
{
    setDocumentMode(true);
    setElideMode(Qt::ElideRight);
}

WebView *TabWidget::currentWebView() const
{
    return webView(currentIndex());
}

WebView *TabWidget::webView(int index) const
{
    return qobject_cast<WebView*>(widget(index));
}

void TabWidget::setUrl(const QUrl &url)
{
    if (WebView *view = currentWebView()) {
        view->setUrl(url);
        view->setFocus();
    }
}

WebView *TabWidget::createTab()
{
    WebView *webView = createBackgroundTab();
    setCurrentWidget(webView);
    return webView;
}

WebView *TabWidget::createBackgroundTab()
{
    WebView *webView = new WebView;
    WebPage *webPage = new WebPage(m_profile, webView);
    webView->setPage(webPage);
//    setupView(webView);
    int index = addTab(webView, tr("(Untitled)"));
//    setTabIcon(index, webView->favIcon());
    // Workaround for QTBUG-61770
    webView->resize(currentWidget()->size());
    webView->show();
    return webView;
}
