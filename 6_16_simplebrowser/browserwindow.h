#ifndef BROWSERWINDOW_H
#define BROWSERWINDOW_H

#include <QMainWindow>
#include <QWebEnginePage>

class Browser;
class TabWidget;
class WebView;

class BrowserWindow : public QMainWindow
{
    Q_OBJECT

public:
    BrowserWindow(Browser *browser, QWebEngineProfile *profile, bool forDevTools = false);
    QSize sizeHint() const override;
    TabWidget *tabWidget() const;
    WebView *currentTab() const;
    Browser *browser() { return m_browser; }
    ~BrowserWindow();

private:
    Browser *m_browser;
    QWebEngineProfile *m_profile;
    TabWidget *m_tabWidget;
};
#endif // BROWSERWINDOW_H
