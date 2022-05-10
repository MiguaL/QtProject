#include "browser.h"
#include "browserwindow.h"
#include "tabwidget.h"
#include "webview.h"
#include "tInteractobj.h"
#include <QVBoxLayout>
#include <QApplication>
#include <QScreen>
#include <tInteractobj.h>
#include <QWebChannel>

BrowserWindow::BrowserWindow(Browser *browser, QWebEngineProfile *profile, bool forDevTools)
    : m_browser(browser)
    , m_profile(profile)
    , m_tabWidget(new TabWidget(profile, this))
{
    setAttribute(Qt::WA_DeleteOnClose, true);
    setFocusPolicy(Qt::ClickFocus);
    if (!forDevTools) {
//        setWindowFlags(Qt::FramelessWindowHint | windowFlags());
//        showMaximized();
    }
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout;
    layout->setSpacing(0);
    layout->setContentsMargins(0, 0, 0, 0);

    layout->addWidget(m_tabWidget);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    m_tabWidget->createTab();
    QWebChannel *pWebChannel   = new QWebChannel(currentTab()->page());
    TInteractObj *pInteractObj = new TInteractObj(this);
    // 注册绑定对象，名称与页面端关联对象保存一致
    pWebChannel->registerObject(QStringLiteral("interactObj"), pInteractObj);
    currentTab()->page()->setWebChannel(pWebChannel);
}

QSize BrowserWindow::sizeHint() const
{
    QRect desktopRect = QApplication::primaryScreen()->geometry();
    QSize size = desktopRect.size() * qreal(0.9);
    return size;
}

TabWidget *BrowserWindow::tabWidget() const
{
    return m_tabWidget;
}

WebView *BrowserWindow::currentTab() const
{
    return m_tabWidget->currentWebView();
}

BrowserWindow::~BrowserWindow()
{
}

