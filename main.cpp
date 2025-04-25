#include "mainwindow.h"

#include <QApplication>
#include <QIcon>
#include <QLocale>
#include <QPalette>
#include <QSettings>
#include <QStyle>
#include <QStyleFactory>
#include <QTranslator>

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon("icon.ico"));

    // 自动根据系统设置切换黑白主题
    QPalette palette;
    bool     darkTheme = false;
#if defined(Q_OS_WIN)
    // Windows 10+ 深色模式检测（简易版，推荐用更专业API或第三方库）
    QSettings settings("HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Themes\\Personalize",
                       QSettings::NativeFormat);
    if (settings.value("AppsUseLightTheme", 1).toInt() == 0) {
        darkTheme = true;
    }
#endif
    if (darkTheme) {
        qApp->setStyle(QStyleFactory::create("Fusion"));
        palette.setColor(QPalette::Window, QColor(32, 34, 37));
        palette.setColor(QPalette::WindowText, QColor(230, 230, 230));
        palette.setColor(QPalette::Base, QColor(24, 26, 27));
        palette.setColor(QPalette::AlternateBase, QColor(44, 47, 51));
        palette.setColor(QPalette::ToolTipBase, QColor(255, 255, 255));
        palette.setColor(QPalette::ToolTipText, QColor(32, 34, 37));
        palette.setColor(QPalette::Text, QColor(230, 230, 230));
        palette.setColor(QPalette::Button, QColor(44, 47, 51));
        palette.setColor(QPalette::ButtonText, QColor(230, 230, 230));
        palette.setColor(QPalette::BrightText, Qt::red);
        palette.setColor(QPalette::Highlight, QColor(38, 120, 179));
        palette.setColor(QPalette::HighlightedText, QColor(255, 255, 255));
        qApp->setPalette(palette);
    } else {
        // 浅色模式下增强对比度
        QPalette lightPalette = qApp->style()->standardPalette();
        lightPalette.setColor(QPalette::Window, QColor(245, 245, 245));
        lightPalette.setColor(QPalette::WindowText, QColor(30, 30, 30));
        lightPalette.setColor(QPalette::Base, QColor(255, 255, 255));
        lightPalette.setColor(QPalette::AlternateBase, QColor(245, 245, 245));
        lightPalette.setColor(QPalette::ToolTipBase, QColor(30, 30, 30));
        lightPalette.setColor(QPalette::ToolTipText, QColor(255, 255, 255));
        lightPalette.setColor(QPalette::Text, QColor(30, 30, 30));
        lightPalette.setColor(QPalette::Button, QColor(235, 235, 235));
        lightPalette.setColor(QPalette::ButtonText, QColor(30, 30, 30));
        lightPalette.setColor(QPalette::BrightText, Qt::red);
        lightPalette.setColor(QPalette::Highlight, QColor(38, 120, 179));
        lightPalette.setColor(QPalette::HighlightedText, QColor(255, 255, 255));
        qApp->setPalette(lightPalette);
    }

    MainWindow w;
    w.show();
    return a.exec();
}
