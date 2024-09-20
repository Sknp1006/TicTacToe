#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

enum class CurrentPiece
{
    O,
    X
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_p_0_0_clicked();
    void on_p_0_1_clicked();
    void on_p_0_2_clicked();
    void on_p_1_0_clicked();
    void on_p_1_1_clicked();
    void on_p_1_2_clicked();
    void on_p_2_0_clicked();
    void on_p_2_1_clicked();
    void on_p_2_2_clicked();

private:
    bool CheckWin(char c);
    void SetPiece(int x, int y);

signals:
    void GameOver();

public slots:
    void GameOverSlot();

private:
    Ui::MainWindow *ui;
    CurrentPiece m_cp;
};
#endif // MAINWINDOW_H
