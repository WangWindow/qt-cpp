#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QHBoxLayout>
#include <QIcon>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    setWindowTitle("简易聊天客户端");
    resize(500, 600);
    setWindowIcon(QIcon(":/icon.ico"));

    // 聊天界面布局
    QWidget*     centralWidget = new QWidget(this);
    QVBoxLayout* mainLayout    = new QVBoxLayout(centralWidget);

    // 判断深色/浅色主题
    QColor   bgColor, textColor, inputBg, inputText, btnBg, btnText, borderColor;
    QPalette pal    = qApp->palette();
    bool     isDark = pal.color(QPalette::Window).value() < 128;
    if (isDark) {
        bgColor     = QColor(32, 34, 37);
        textColor   = QColor(230, 230, 230);
        inputBg     = QColor(44, 47, 51);
        inputText   = QColor(230, 230, 230);
        btnBg       = QColor(38, 120, 179);
        btnText     = QColor(255, 255, 255);
        borderColor = QColor(60, 60, 60);
    } else {
        bgColor     = QColor(248, 248, 248);
        textColor   = QColor(30, 30, 30);
        inputBg     = QColor(255, 255, 255);
        inputText   = QColor(30, 30, 30);
        btnBg       = QColor(64, 158, 255);
        btnText     = QColor(255, 255, 255);
        borderColor = QColor(200, 200, 200);
    }

    messageDisplay = new QTextEdit(this);
    messageDisplay->setReadOnly(true);
    messageDisplay->setStyleSheet(QString("background:%1;color:%2;border:1px solid %3;font-size:16px;padding:8px;")
                                      .arg(bgColor.name(), textColor.name(), borderColor.name()));
    messageInput = new QLineEdit(this);
    messageInput->setPlaceholderText("请输入消息...");
    messageInput->setStyleSheet(
        QString("background:%1;color:%2;font-size:15px;padding:6px;border-radius:4px;border:1px solid %3;")
            .arg(inputBg.name(), inputText.name(), borderColor.name()));
    sendButton = new QPushButton("发送", this);
    sendButton->setStyleSheet(QString("background:%1;color:%2;font-size:15px;padding:6px 18px;border-radius:4px;")
                                  .arg(btnBg.name(), btnText.name()));

    QHBoxLayout* inputLayout = new QHBoxLayout();
    inputLayout->addWidget(messageInput);
    inputLayout->addWidget(sendButton);

    mainLayout->addWidget(messageDisplay);
    mainLayout->addLayout(inputLayout);
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);

    connect(sendButton, &QPushButton::clicked, this, &MainWindow::onSendButtonClicked);
    connect(messageInput, &QLineEdit::returnPressed, this, &MainWindow::onSendButtonClicked);
}

void MainWindow::onSendButtonClicked() {
    QString text = messageInput->text();
    if (!text.isEmpty()) {
        messageDisplay->append("我: " + text);
        messageInput->clear();
    }
}

MainWindow::~MainWindow() {
    delete ui;
}
