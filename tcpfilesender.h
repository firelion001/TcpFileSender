#ifndef TCPFILESENDER_H
#define TCPFILESENDER_H

#include <QDialog>
#include <QtNetwork>
#include <QtWidgets>
class TcpFileSender : public QDialog
{
    Q_OBJECT

public:
    explicit TcpFileSender(QWidget *parent = nullptr);
    ~TcpFileSender() override;
private slots:
    void start();//使用者案開始
    void startTransfer();//tcp connection 連線成功
    void updateClientProgress(qint64 numBytes);//tcp持續可傳輸事件
    void openFile();//使用者案開檔button
private:
    QProgressBar    *clientProgressBar;
    QLabel          *clientStatusLabel;
    QPushButton     *startButton;
    QPushButton     *quitButton;
    QPushButton     *openButton;
    QDialogButtonBox *buttonBox;
    QTcpSocket      tcpClient;

    qint64          totalBytes;
    qint64          bytesWritten;
    qint64          bytesToWrite;
    qint64          loadsize;
    QString         fileName;
    QFile           *localFile;
    QByteArray      outBlock;

};
#endif // TCPFILESENDER_H
