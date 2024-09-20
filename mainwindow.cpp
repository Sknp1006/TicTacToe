#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>

static char board_data[3][3] =
{
    { '-', '-', '-' },
    { '-', '-', '-' },
    { '-', '-', '-' },
};


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowIcon(QIcon(":/tictactoe.ico"));

    // 首先下棋的
    m_cp = CurrentPiece::X;

    connect(this, &MainWindow::GameOver, this, &MainWindow::GameOverSlot);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::CheckWin(char c)
{
    if (board_data[0][0] == c && board_data[0][1] == c && board_data[0][2] == c)
        return true;
    if (board_data[1][0] == c && board_data[1][1] == c && board_data[1][2] == c)
        return true;
    if (board_data[2][0] == c && board_data[2][1] == c && board_data[2][2] == c)
        return true;
    if (board_data[0][0] == c && board_data[1][0] == c && board_data[2][0] == c)
        return true;
    if (board_data[0][1] == c && board_data[1][1] == c && board_data[2][1] == c)
        return true;
    if (board_data[0][2] == c && board_data[1][2] == c && board_data[2][2] == c)
        return true;
    if (board_data[0][0] == c && board_data[1][1] == c && board_data[2][2] == c)
        return true;
    if (board_data[0][2] == c && board_data[1][1] == c && board_data[2][0] == c)
        return true;

    return false;
}

void MainWindow::SetPiece(int x, int y)
{
    switch (m_cp) {
    case CurrentPiece::X:
        board_data[x][y] = 'X';
        if (CheckWin('X'))
        {
            QMessageBox::information(this, "Game Over", "X Win!");
            emit GameOver();
            return;
        }
        m_cp = CurrentPiece::O;
        break;
    case CurrentPiece::O:
        board_data[x][y] = 'O';
        if (CheckWin('O'))
        {
            QMessageBox::information(this, "Game Over", "O Win!");
            emit GameOver();
            return;
        }
        m_cp = CurrentPiece::X;
        break;
    default:
        break;
    }
}

void MainWindow::GameOverSlot()
{
    // 重置棋盘
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board_data[i][j] = '-';
        }
    }
    ui->p_0_0->setText("");
    ui->p_0_1->setText("");
    ui->p_0_2->setText("");
    ui->p_1_0->setText("");
    ui->p_1_1->setText("");
    ui->p_1_2->setText("");
    ui->p_2_0->setText("");
    ui->p_2_1->setText("");
    ui->p_2_2->setText("");
    m_cp = CurrentPiece::X;
}

void MainWindow::on_p_0_0_clicked()
{
    qDebug() << "0_0 clicked";
    ui->p_0_0->setText(m_cp == CurrentPiece::X ? "X" : "O");
    SetPiece(0, 0);
}

void MainWindow::on_p_0_1_clicked()
{
    qDebug() << "0_1 clicked";
    ui->p_0_1->setText(m_cp == CurrentPiece::X ? "X" : "O");
    SetPiece(0, 1);
}

void MainWindow::on_p_0_2_clicked()
{
    qDebug() << "0_2 clicked";
    ui->p_0_2->setText(m_cp == CurrentPiece::X ? "X" : "O");
    SetPiece(0, 2);
}

void MainWindow::on_p_1_0_clicked()
{
    qDebug() << "1_0 clicked";
    ui->p_1_0->setText(m_cp == CurrentPiece::X ? "X" : "O");
    SetPiece(1, 0);

}

void MainWindow::on_p_1_1_clicked()
{
    qDebug() << "1_1 clicked";
    ui->p_1_1->setText(m_cp == CurrentPiece::X ? "X" : "O");
    SetPiece(1, 1);
}

void MainWindow::on_p_1_2_clicked()
{
    qDebug() << "1_2 clicked";
    ui->p_1_2->setText(m_cp == CurrentPiece::X ? "X" : "O");
    SetPiece(1, 2);
}

void MainWindow::on_p_2_0_clicked()
{
    qDebug() << "2_0 clicked";
    ui->p_2_0->setText(m_cp == CurrentPiece::X ? "X" : "O");
    SetPiece(2, 0);
}

void MainWindow::on_p_2_1_clicked()
{
    qDebug() << "2_1 clicked";
    ui->p_2_1->setText(m_cp == CurrentPiece::X ? "X" : "O");
    SetPiece(2, 1);

}

void MainWindow::on_p_2_2_clicked()
{
    qDebug() << "2_2 clicked";
    ui->p_2_2->setText(m_cp == CurrentPiece::X ? "X" : "O");
    SetPiece(2, 2);
}

