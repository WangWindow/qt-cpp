#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QLineEdit>
#include <QMainWindow>
#include <QPushButton>
#include <QTextEdit>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private slots:
    void onSendButtonClicked();

private:
    QTextEdit*   messageDisplay;
    QLineEdit*   messageInput;
    QPushButton* sendButton;
};
#endif // MAINWINDOW_H
