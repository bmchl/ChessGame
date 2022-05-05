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
#include "Chess.hpp"
#include "Position.hpp"

QT_BEGIN_NAMESPACE
namespace view
{
    class ChessWindow : public QMainWindow
    {
    Q_OBJECT
    private:
        logic::Game* game_;
    public:
        QWidget* centralwidget;
        QWidget* gridLayoutWidget;
        QGridLayout* gridLayout;
        QDialog* dialog;
        QPushButton* chessSquares[8][8];

        QWidget* horizontalLayoutWidget;
        QHBoxLayout* pieceChoiceLayout;
        QVBoxLayout* whitePieceChoiceLayout;
        QPushButton* pieceChoice1;
        QPushButton* pieceChoice2;
        QPushButton* pieceChoice3;
        QVBoxLayout* blackPieceChoiceLayout;
        QPushButton* pieceChoice4;
        QPushButton* pieceChoice5;
        QPushButton* pieceChoice6;

        ChessWindow(logic::Game* game, QWidget* parent = nullptr): game_(game)
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
            QMetaObject::connectSlotsByName(this);
            addSquares();
            addPieceChoices();
            displayStartOptions();
        }

        void addSquares()
        {
            for (int i = 0; i < 8; i++)
            {
                for (int j = 0; j < 8; j++)
                {
                    chessSquares[i][j] = new QPushButton(gridLayoutWidget);
                    chessSquares[i][j]->setMaximumSize(QSize(80, 80));
                    chessSquares[i][j]->setCheckable(false);
                    if ((i + j) % 2 == 0) {
                        chessSquares[i][j]->setStyleSheet("background-color:rgb(159,179,159)");
                    }
                    else {
                        chessSquares[i][j]->setStyleSheet("background-color:rgb(106,128,120)");
                    }
                    gridLayout->addWidget(chessSquares[i][j], i, j, 1, 1);
                    //QObject::connect(chessSquares[i][j],)
                }
            }
            chessSquares[0][0]->setStyleSheet("background-color:rgb(159,179,159); border-top-left-radius: 10");
            chessSquares[7][7]->setStyleSheet("background-color:rgb(159,179,159); border-bottom-right-radius: 10");
            chessSquares[0][7]->setStyleSheet("background-color:rgb(106,128,120); border-top-right-radius: 10");
            chessSquares[7][0]->setStyleSheet("background-color:rgb(106,128,120); border-bottom-left-radius: 10");
        }

        void addPieceChoices()
        {
            horizontalLayoutWidget = new QWidget(centralwidget);
            horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
            horizontalLayoutWidget->setGeometry(QRect(20, 110, 172, 256));
            pieceChoiceLayout = new QHBoxLayout(horizontalLayoutWidget);
            pieceChoiceLayout->setObjectName(QString::fromUtf8("pieceChoiceLayout"));
            pieceChoiceLayout->setContentsMargins(0, 0, 0, 0);
            whitePieceChoiceLayout = new QVBoxLayout();
            whitePieceChoiceLayout->setObjectName(QString::fromUtf8("whitePieceChoiceLayout"));
            pieceChoice1 = new QPushButton(horizontalLayoutWidget);
            pieceChoice1->setObjectName(QString::fromUtf8("pieceChoice1"));
            pieceChoice1->setFixedSize(QSize(80, 80));
            pieceChoice1->setStyleSheet("background-color:rgb(20,20,20);border-radius:20");
            pieceChoice1->setCheckable(false);
            pieceChoice1->setIcon(QIcon("./img/wking.png"));
            pieceChoice1->setIconSize(QSize(60, 60));

            whitePieceChoiceLayout->addWidget(pieceChoice1);

            pieceChoice2 = new QPushButton(horizontalLayoutWidget);
            pieceChoice2->setObjectName(QString::fromUtf8("pieceChoice2"));
            pieceChoice2->setMinimumSize(QSize(80, 80));
            pieceChoice2->setMaximumSize(QSize(80, 80));
            pieceChoice2->setStyleSheet("background-color:rgb(20,20,20);border-radius:20");
            pieceChoice2->setCheckable(false);
            pieceChoice2->setIcon(QIcon("./img/wknight.png"));
            pieceChoice2->setIconSize(QSize(60, 60));

            whitePieceChoiceLayout->addWidget(pieceChoice2);

            pieceChoice3 = new QPushButton(horizontalLayoutWidget);
            pieceChoice3->setObjectName(QString::fromUtf8("pieceChoice3"));
            pieceChoice3->setMinimumSize(QSize(80, 80));
            pieceChoice3->setMaximumSize(QSize(80, 80));
            pieceChoice3->setStyleSheet("background-color:rgb(20,20,20);border-radius:20");
            pieceChoice3->setCheckable(false);
            pieceChoice3->setIcon(QIcon("./img/wrook.png"));
            pieceChoice3->setIconSize(QSize(60, 60));

            whitePieceChoiceLayout->addWidget(pieceChoice3);


            pieceChoiceLayout->addLayout(whitePieceChoiceLayout);

            blackPieceChoiceLayout = new QVBoxLayout();
            blackPieceChoiceLayout->setObjectName(QString::fromUtf8("blackPieceChoiceLayout"));
            pieceChoice4 = new QPushButton(horizontalLayoutWidget);
            pieceChoice4->setObjectName(QString::fromUtf8("pieceChoice4"));
            pieceChoice4->setMinimumSize(QSize(80, 80));
            pieceChoice4->setMaximumSize(QSize(80, 80));
            pieceChoice4->setStyleSheet("background-color:rgb(20,20,20);border-radius:20");
            pieceChoice4->setCheckable(false);
            pieceChoice4->setIcon(QIcon("./img/bking.png"));
            pieceChoice4->setIconSize(QSize(60, 60));

            blackPieceChoiceLayout->addWidget(pieceChoice4);

            pieceChoice5 = new QPushButton(horizontalLayoutWidget);
            pieceChoice5->setObjectName(QString::fromUtf8("pieceChoice5"));
            pieceChoice5->setMinimumSize(QSize(80, 80));
            pieceChoice5->setMaximumSize(QSize(80, 80));
            pieceChoice5->setStyleSheet("background-color:rgb(20,20,20);border-radius:20");
            pieceChoice5->setCheckable(false);
            pieceChoice5->setIcon(QIcon("./img/bknight.png"));
            pieceChoice5->setIconSize(QSize(60, 60));

            blackPieceChoiceLayout->addWidget(pieceChoice5);

            pieceChoice6 = new QPushButton(horizontalLayoutWidget);
            pieceChoice6->setObjectName(QString::fromUtf8("pieceChoice6"));
            pieceChoice6->setMinimumSize(QSize(80, 80));
            pieceChoice6->setMaximumSize(QSize(80, 80));
            pieceChoice6->setStyleSheet("background-color:rgb(20,20,20);border-radius:20");
            pieceChoice6->setCheckable(false);
            pieceChoice6->setIcon(QIcon("./img/brook.png"));
            pieceChoice6->setIconSize(QSize(60, 60));

            blackPieceChoiceLayout->addWidget(pieceChoice6);

            pieceChoiceLayout->addLayout(blackPieceChoiceLayout);
        }
        void displayStartOptions()
        {
            dialog = new QDialog();
            //dialog->setStyleSheet("background-color:rgb(30,30,30)");
            dialog->setWindowTitle("choix de fin de jeu");

            dialog->setFixedSize(500, 600);
            auto buttonBox = new QDialogButtonBox(dialog);
            buttonBox->setGeometry(QRect(40, 530, 420, 30));
            buttonBox->setOrientation(Qt::Horizontal);
            buttonBox->setStandardButtons(QDialogButtonBox::Ok);
            //QObject::connect(buttonBox, buttonBox->accepted(), this, setMode(selectedMode));
            QObject::connect(buttonBox, SIGNAL(&QDialogButtonBox::accepted), dialog, SLOT(&QDialog::accept));

            auto groupBox = new QGroupBox(dialog);
            groupBox->setGeometry(QRect(20, 20, 460, 560));
            groupBox->setTitle("choisissez une des options suivantes:");

            auto radioButton = new QRadioButton(groupBox);
            radioButton->setGeometry(QRect(20, 220, 80, 20));
            radioButton->setText("option 1");
            radioButton->setChecked(true);
            QObject::connect(radioButton, SIGNAL(toggled(bool)), this, SLOT(option1Toggled(bool checked)));

            auto radioButton_2 = new QRadioButton(groupBox);
            radioButton_2->setGeometry(QRect(240, 220, 80, 20));
            radioButton_2->setText("option 2");
            QObject::connect(radioButton_2, SIGNAL(toggled(bool)), this, SLOT(view::ChessWindow::option2Toggled(bool checked)));

            auto radioButton_3 = new QRadioButton(groupBox);
            radioButton_3->setGeometry(QRect(20, 480, 80, 20));
            radioButton_3->setText("option 3");
            QObject::connect(radioButton_3, SIGNAL(toggled(bool)), this, SLOT(option3Toggled(bool checked)));

            auto radioButton_4 = new QRadioButton(groupBox);
            radioButton_4->setGeometry(QRect(240, 480, 80, 20));
            radioButton_4->setText("option 4");
            QObject::connect(radioButton_4, SIGNAL(toggled(bool)), this, SLOT(option4Toggled(bool checked)));

            auto label = new QLabel(groupBox);
            label->setObjectName(QString::fromUtf8("label"));
            label->setGeometry(QRect(20, 20, 200, 200));
            label->setPixmap(QPixmap("../../../../../../Users/banna/OneDrive - polymtl.ca/inf1500 docs folder from oct 20th/test ual comptage de 5.PNG"));

            auto label_2 = new QLabel(groupBox);
            label_2->setGeometry(QRect(240, 20, 200, 200));
            label_2->setPixmap(QPixmap("../../../../../../Users/banna/OneDrive - polymtl.ca/inf1500 docs folder from oct 20th/test ual comptage de 5.PNG"));

            auto label_3 = new QLabel(groupBox);
            label_3->setGeometry(QRect(240, 280, 200, 200));
            label_3->setPixmap(QPixmap("../../../../../../Users/banna/OneDrive - polymtl.ca/inf1500 docs folder from oct 20th/test ual comptage de 5.PNG"));

            auto label_4 = new QLabel(groupBox);
            label_4->setGeometry(QRect(20, 280, 200, 200));
            label_4->setPixmap(QPixmap("../../../../../../Users/banna/OneDrive - polymtl.ca/inf1500 docs folder from oct 20th/test ual comptage de 5.PNG"));

            //QObject::connect(this, SIGNAL(optionsGroup->clicked(int)), this, SLOT(setMode(selectedMode)));
            dialog->exec();
            //dialog->open();
            setMode(dialog->result());
        }
     public slots:
         void option1Toggled(bool checked)
         {
             if (checked)
             {
                 dialog->setResult(1);
             }
         }
         void option2Toggled(bool checked)
         {
             if (checked)
             {
                 dialog->setResult(2);
             }
         }
         void option3Toggled(bool checked)
         {
             if (checked)
             {
                 dialog->setResult(3);
             }
         }
         void option4Toggled(bool checked)
         {
             if (checked)
             {
                 dialog->setResult(4);
             }
         }
        Position getSelectedPosition(int x, int y)
        {
            return Position{ x,y };
        };
        void setMode(int mode)
        {
            switch (mode)
            {
            case 1:
                std::cout << "option 1 selected" << std::endl;
                break;
            case 2:
                std::cout << "option 2 selected" << std::endl;
                break;
            case 3:
                std::cout << "option 3 selected" << std::endl;
                break;
            case 4:
                std::cout << "option 4 selected" << std::endl;
                break;
            }
        }
    };

}
QT_END_NAMESPACE
#endif // VIEWXHXAII_H
