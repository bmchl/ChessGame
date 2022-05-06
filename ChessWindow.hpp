// TD6 INF1015
// Michael Banna (2147128) & Nour Zahreddine (2167661)
// fichier View.hpp
// C'est le fichier généré par QtDesigner (de l'extension Qt VS Tools).
// Malgré le fait qu'il compile, l'interface que nous avons conçu n'apparait pas.
// Notre second namespace "view" se situe ici.
/********************************************************************************
** Form generated from reading UI file 'ViewXhXAii.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef VIEWXHXAII_H
#define VIEWXHXAII_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <QtWidgets/QDialog>
#include <QButtonGroup>
#include <QGroupBox>
#include <QLabel>
#include <QDialogButtonBox>
#include "Game.hpp"
#include "Position.hpp"
#include "ChessSquare.hpp"

QT_BEGIN_NAMESPACE
namespace view
{
    class ChessWindow : public QMainWindow
    {
    private:
        Game* game_;
        int selectedMode = 1;
        int selectionCount = 0;
        std::list<Position*> selectedPositions;
    public:
        QWidget* centralwidget;
        QWidget* gridLayoutWidget;
        QGridLayout* gridLayout;
        QDialog* dialog;
        QPushButton* chessSquares[8][8];
        QLabel* turnIndicator;
        QLabel* checkIndicator;
        ~ChessWindow()
        {
            std::cout << "destructor called" << std::endl;
            delete centralwidget;
            delete gridLayoutWidget;
            delete gridLayout;
            delete dialog;
            delete chessSquares;
            delete turnIndicator;
        }
        ChessWindow(Game* game, QWidget* parent = nullptr): game_(game)
        {
            this->resize(990, 770);
            this->setWindowTitle("let's play chess!");
            this->setStyleSheet("background-color:rgb(30,30,30)");
            this->setFixedSize(QSize(900, 700));
            this->setWindowIcon(QIcon("./img/appicon.png"));

            centralwidget = new QWidget(this);
            centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
            gridLayoutWidget = new QWidget(centralwidget);
            gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
            gridLayoutWidget->setGeometry(QRect(230, 30, 640, 640));
            gridLayout = new QGridLayout(gridLayoutWidget);
            gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
            gridLayout->setContentsMargins(0, 0, 0, 0);
            gridLayout->setSpacing(0);
            this->setCentralWidget(centralwidget);
            //QMetaObject::connectSlotsByName(this);
            addSquares();
            addTurnIndicator();
            addCheckIndicator();
            displayStartOptions();
            
        }
        void addSquares()
        {
            auto groupedSquares = new QButtonGroup(this);
            for (int i = 0; i < 8; i++)
            {
                for (int j = 0; j < 8; j++)
                {
                    chessSquares[i][j] = new ChessSquare(i, j, gridLayoutWidget);
                    chessSquares[i][j]->setMaximumSize(QSize(80, 80));
                    chessSquares[i][j]->setCheckable(false);
                    gridLayout->addWidget(chessSquares[i][j], i, j, 1, 1);
                    groupedSquares->addButton(chessSquares[i][j]);
                }
            }
            QObject::connect(groupedSquares, &QButtonGroup::buttonClicked, this, &ChessWindow::rememberSelectedSquare);
            stylizeRegularSquares();
        }
        void addTurnIndicator()
        {
            auto turnTitle = new QLabel(this);
            turnTitle->setStyleSheet("color:white;font-size:15px");
            turnTitle->setGeometry(30, 30, 100, 30);
            turnTitle->setText("current turn:");
            turnIndicator = new QLabel(this);
            turnIndicator->setStyleSheet("color:white;font-size:30px");
            turnIndicator->setGeometry(30, 60, 100, 30);
            updateTurn();
        }
        void incrementSelectionCount()
        {
            std::cout << "incrementing count " << std::endl;
            selectionCount++;
            if (selectionCount == 2)
            {
                executeMove();
                selectionCount = 0;
            }
        }
        void executeMove()
        {
            if (game_->isImpossibleMove(*std::next(selectedPositions.begin(), 1), selectedPositions.front()))
            {
                displayInvalidMoveDialog();
                stylizeRegularSquares();
            }
            else
            {
                updatePieces(*std::next(selectedPositions.begin(), 1), selectedPositions.front());
                game_->makeMove(*std::next(selectedPositions.begin(), 1), selectedPositions.front());
                updateTurn();
                stylizeRegularSquares();
                if (game_->isOver())
                {
                    displayGameOverDialog();
                }
            }
            updateCheckStatus();
        }
        void updateCheckStatus()
        {
            if (game_->isInCheck())
            {
                checkIndicator->setText("check!");
            }
            else
            {
                checkIndicator->setText("");
            }
        }
        void addCheckIndicator()
        {
            checkIndicator = new QLabel(this);
            checkIndicator->setStyleSheet("color:white;font-size:50px");
            checkIndicator->setGeometry(30, 610, 200, 60);
            checkIndicator->setText("");
            updateCheckStatus();
        }
        void displayGameOverDialog()
    {
            auto gameOverDialog = new QDialog();
            gameOverDialog->setWindowTitle("game over!");
            gameOverDialog->setFixedSize(500, 200);
            auto winner = new QLabel(gameOverDialog);
            winner->setText(game_->winner + " is the winner!");
            winner->setGeometry(QRect(20, 50, 100, 30));
            auto restartButton = new QPushButton(gameOverDialog);
            restartButton->setText("restart");
            restartButton->setGeometry(QRect(420, 150, 60, 20));
            QObject::connect(restartButton, &QPushButton::clicked, gameOverDialog, &QDialog::accept);
            auto exitButton = new QPushButton(gameOverDialog);
            exitButton->setText("exit");
            exitButton->setGeometry(QRect(320, 150, 60, 20));
            QObject::connect(exitButton, &QPushButton::clicked, gameOverDialog, &QDialog::reject);
            QObject::connect(gameOverDialog, &QDialog::accepted, this, &ChessWindow::restart);
            QObject::connect(gameOverDialog, &QDialog::rejected, this, &ChessWindow::exit);
            gameOverDialog->exec();
        }
        void restart()
        {
            game_->reset();
            selectionCount = 0;
            selectedPositions.clear();
            cleanBoard();
            displayStartOptions();
        }
        void exit()
        {
            game_->reset();
            selectionCount = 0;
            selectedPositions.clear();
            cleanBoard();
            this->close();
        }
        void cleanBoard()
        {
            for (int i = 0; i < 8; i++)
            {
                for (int j = 0; j < 8; j++)
                {
                    chessSquares[i][j]->setIcon(QIcon(""));
                }
            }
        }
        void displayInvalidMoveDialog()
        {
            dialog = new QDialog();
            dialog->setWindowTitle("invalid move error!");
            dialog->setFixedSize(500, 200);
            auto mbButton = new QPushButton(dialog);
            mbButton->setText("my bad :(");
            mbButton->setGeometry(QRect(400, 150, 60, 20));
            QObject::connect(mbButton, &QPushButton::clicked, dialog, &QDialog::accept);
            dialog->exec();
        }
        void updateTurn()
        {
            if (game_->turn == 'W') { game_->turn = 'B'; }
            else if (game_->turn == 'B') { game_->turn = 'W'; }

            if (game_->turn == 'W')
            {
                turnIndicator->setText(QString("White"));
            }
            else if (game_->turn == 'B')
            {
                turnIndicator->setText(QString("Black"));
            }
        }
        void updatePieces(Position* source, Position* destination)
        {
            for (auto pair : game_->pieces)
            {
                if (pair.second.row == source->row && pair.second.column == source->column)
                {
                    game_->pieces[pair.first] = *selectedPositions.front();
                }
            }
           if (game_->getPiece(*destination) != nullptr && !game_->isImpossibleMove(*std::next(selectedPositions.begin(), 1), selectedPositions.front()))
            {
               game_->pieces.erase(game_->getPiece(*destination));
            }
            chessSquares[destination->row][destination->column]->setIcon(QIcon(""));
            chessSquares[source->row][source->column]->setIcon(QIcon(""));
            displayPieces();
        }
        void displayPieces()
        {
            for (auto piece : game_->pieces)
            {
                chessSquares[piece.second.row][piece.second.column]->setIcon(QIcon(piece.first->iconPath));
                chessSquares[piece.second.row][piece.second.column]->setIconSize(QSize(60, 60));
            }
        }
        void stylizeRegularSquares()
        {
            for (int i = 0; i < 8; i++)
            {
                for (int j = 0; j < 8; j++)
                {
                    if ((i + j) % 2 == 0) {
                        chessSquares[i][j]->setStyleSheet("background-color:rgb(159,179,159)");
                    }
                    else {
                        chessSquares[i][j]->setStyleSheet("background-color:rgb(106,128,120)");
                    }
                }
            }
            chessSquares[0][0]->setStyleSheet("background-color:rgb(159,179,159); border-top-left-radius: 10");
            chessSquares[7][7]->setStyleSheet("background-color:rgb(159,179,159); border-bottom-right-radius: 10");
            chessSquares[0][7]->setStyleSheet("background-color:rgb(106,128,120); border-top-right-radius: 10");
            chessSquares[7][0]->setStyleSheet("background-color:rgb(106,128,120); border-bottom-left-radius: 10");
        }
        void highlightPossiblePositions(std::shared_ptr<Piece> piece)
        {
            stylizeRegularSquares();
            piece->updatePossiblePositions(game_->getPosition(piece));
            for (auto&& possiblePosition : piece->possiblePositions)
            {
                if (possiblePosition->row == 0 && possiblePosition->column == 0)
                {
                    chessSquares[0][0]->setStyleSheet("background-color:rgb(202,182,109); border-top-left-radius: 10");
                }
                else if (possiblePosition->row == 7 && possiblePosition->column == 7)
                {
                    chessSquares[7][7]->setStyleSheet("background-color:rgb(202,182,109); border-bottom-right-radius: 10");
                }
                else if (possiblePosition->row == 0 && possiblePosition->column == 7)
                {
                    chessSquares[0][7]->setStyleSheet("background-color:rgb(202,182,109); border-top-right-radius: 10");
                }
                else if (possiblePosition->row == 7 && possiblePosition->column == 0)
                {
                    chessSquares[7][0]->setStyleSheet("background-color:rgb(202,182,109); border-bottom-left-radius: 10");
                }
                else 
                {
                    chessSquares[possiblePosition->row][possiblePosition->column]->setStyleSheet("background-color:rgb(202,182,109)");
                }
            }
        }
        void displayStartOptions()
        {
            dialog = new QDialog();
            dialog->setStyleSheet("background-color:rgb(30,30,30)");
            dialog->setWindowTitle("choix de fin de jeu");

            dialog->setFixedSize(500, 600);
          
            auto playButton = new QPushButton(dialog);
            playButton->setText("play now!");
            playButton->setStyleSheet("color:white; background-color:rgb(60,60,60)");
            playButton->setGeometry(QRect(20, 550, 460, 30));
            QObject::connect(playButton, &QPushButton::clicked, dialog, &QDialog::accept);

            auto groupBox = new QGroupBox(dialog);
            groupBox->setGeometry(QRect(20, 20, 460, 520));
            groupBox->setTitle("choisissez une des options suivantes:");
            groupBox->setStyleSheet("color:white");


            auto radioButton = new QRadioButton(groupBox);
            radioButton->setGeometry(QRect(20, 220, 80, 20));
            radioButton->setText("option 1");
            radioButton->setChecked(true);
            radioButton->setStyleSheet("color:white");

            QObject::connect(radioButton, &QRadioButton::toggled, this, &ChessWindow::option1Toggled);

            auto radioButton_2 = new QRadioButton(groupBox);
            radioButton_2->setGeometry(QRect(240, 220, 80, 20));
            radioButton_2->setText("option 2");
            radioButton_2->setStyleSheet("color:white");
            QObject::connect(radioButton_2, &QRadioButton::toggled, this, &ChessWindow::option2Toggled);

            auto radioButton_3 = new QRadioButton(groupBox);
            radioButton_3->setGeometry(QRect(20, 480, 80, 20));
            radioButton_3->setText("option 3");
            radioButton_3->setStyleSheet("color:white");
            QObject::connect(radioButton_3, &QRadioButton::toggled, this, &ChessWindow::option3Toggled);

            auto radioButton_4 = new QRadioButton(groupBox);
            radioButton_4->setGeometry(QRect(240, 480, 80, 20));
            radioButton_4->setText("option 4");
            radioButton_4->setStyleSheet("color:white");
            QObject::connect(radioButton_4, &QRadioButton::toggled, this, &ChessWindow::option4Toggled);

            auto label = new QLabel(groupBox);
            label->setObjectName(QString::fromUtf8("label"));
            label->setGeometry(QRect(20, 20, 200, 200));
            label->setPixmap(QPixmap("./img/option1preview"));
            label->setScaledContents(true);
            label->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);

            auto label_2 = new QLabel(groupBox);
            label_2->setGeometry(QRect(240, 20, 200, 200));
            label_2->setPixmap(QPixmap("./img/option2preview"));
            label_2->setScaledContents(true);
            label_2->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);

            auto label_3 = new QLabel(groupBox);
            label_3->setGeometry(QRect(240, 280, 200, 200));
            label_3->setPixmap(QPixmap("./img/option3preview"));
            label_3->setScaledContents(true);
            label_3->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);

            auto label_4 = new QLabel(groupBox);
            label_4->setGeometry(QRect(20, 280, 200, 200));
            label_4->setPixmap(QPixmap("./img/option4preview"));
            label_4->setScaledContents(true);
            label_4->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
            dialog->exec();
            setMode();
        }
        void setMode()
        {
            switch (selectedMode)
            {
            case 1:
                std::cout << "option 1 selected" << std::endl;
                game_->setOption1();
                displayPieces();
                break;
            case 2:
                std::cout << "option 2 selected" << std::endl;
                game_->setOption2();
                displayPieces();
                break;
            case 3:
                std::cout << "option 3 selected" << std::endl;
                game_->setOption3();
                displayPieces();
                break;
            case 4:
                std::cout << "option 4 selected" << std::endl;
                game_->setOption4();
                displayPieces();
                break;
            }
        }
     public slots:
         void rememberSelectedSquare(QAbstractButton* button)
         {
             auto square = static_cast<ChessSquare*>(button);
             selectedPositions.push_front(square->position);
             std::cout << "remembered selected square at (" << selectedPositions.front()->row << "," << selectedPositions.front()->column << ")";
             if (selectionCount == 0 && game_->getPiece(*selectedPositions.front()) != nullptr)
             {
                 std::cout << " with " << *game_->getPiece(*selectedPositions.front());
                 highlightPossiblePositions(game_->getPiece(*selectedPositions.front()));
                 incrementSelectionCount();
             }
             else if(selectionCount > 0)
             {
                 incrementSelectionCount();
             }
             std::cout << std::endl;
         }
         void option1Toggled(bool checked)
         {
             if (checked)
             {
                 selectedMode = 1;
             }
         }
         void option2Toggled(bool checked)
         {
             if (checked)
             {
                 selectedMode = 2;
             }
         }
         void option3Toggled(bool checked)
         {
             if (checked)
             {
                 selectedMode = 3;
             }
         }
         void option4Toggled(bool checked)
         {
             if (checked)
             {
                 selectedMode = 4;
             }
         }
    };

}
QT_END_NAMESPACE
#endif // VIEWXHXAII_H