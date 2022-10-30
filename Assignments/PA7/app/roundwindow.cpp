#include "roundwindow.h"
#include "ui_roundwindow.h"

RoundWindow::RoundWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::RoundWindow)
    , kb(new Keyboard)
{
    ui->setupUi(this);

    /**
     * TODO: TASK 2.1
     *
     * Add the 26 letter keys, Del key and Enter key to the Keyboard using addKey() functions.
     */
    kb->addKey(ui->toolButton_A, 'a');
    kb->addKey(ui->toolButton_B, 'b');
    kb->addKey(ui->toolButton_C, 'c');
    kb->addKey(ui->toolButton_D, 'd');
    kb->addKey(ui->toolButton_E, 'e');
    kb->addKey(ui->toolButton_F, 'f');
    kb->addKey(ui->toolButton_G, 'g');
    kb->addKey(ui->toolButton_H, 'h');
    kb->addKey(ui->toolButton_I, 'i');
    kb->addKey(ui->toolButton_J, 'j');
    kb->addKey(ui->toolButton_K, 'k');
    kb->addKey(ui->toolButton_L, 'l');
    kb->addKey(ui->toolButton_M, 'm');
    kb->addKey(ui->toolButton_N, 'n');
    kb->addKey(ui->toolButton_O, 'o');
    kb->addKey(ui->toolButton_P, 'p');
    kb->addKey(ui->toolButton_Q, 'q');
    kb->addKey(ui->toolButton_R, 'r');
    kb->addKey(ui->toolButton_S, 's');
    kb->addKey(ui->toolButton_T, 't');
    kb->addKey(ui->toolButton_U, 'u');
    kb->addKey(ui->toolButton_V, 'v');
    kb->addKey(ui->toolButton_W, 'w');
    kb->addKey(ui->toolButton_X, 'x');
    kb->addKey(ui->toolButton_Y, 'y');
    kb->addKey(ui->toolButton_Z, 'z');

    kb->addDelKey(ui->pushButton_Del);
    kb->addEnterKey(ui->pushButton_Enter);


    connect(ui->actionGive_Up, &QAction::triggered, this, &RoundWindow::popupConfirmGiveUp);
    connect(ui->actionReset_Round, &QAction::triggered, this, &RoundWindow::popupConfirmReset);
    connect(ui->actionCheat, &QAction::triggered, this, &RoundWindow::popupCheat);
    connect(ui->actionHint, &QAction::triggered, this, &RoundWindow::popupHint);
}

RoundWindow::~RoundWindow()
{
    delete ui;
    delete kb;
    delete wr;
}

void RoundWindow::generateLetterBoxes(QGridLayout *grid, LetterBox*** boxes, const int rows, const int columns) {
    for (int i=0; i<rows; ++i) {
        for (int j=0; j<columns; ++j) {
            grid->addWidget(boxes[i][j], i, j);
        }
    }
    // need to call this to properly resize the box grid layout on setup
    grid->activate();
}

/**
 * TODO: TASK 3
 *
 * Get the key being pressed with event->key().
 * If key is Qt::Key_Delete or Qt::Key_Backspace, treat as Del button pressed.
 * If key is Qt::Key_Return or Qt::Key_Enter, treat as Enter button pressed.
 * If key is Qt::Key_A, Qt::Key_B, ..., or Qt::Key_Z, treat as the corresponding letter key pressed.
 *
 * Hint: you can get the letter being pressed with event->text().at(0) (lowercase)
 */
void RoundWindow::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter){
        kb->enterKeyPressed();
    }
    else if (event->key() == Qt::Key_Delete || event->key() == Qt::Key_Backspace){
        kb->delKeyPressed();
    }
    else{
        QChar key_char = event->text().at(0).toLower();
        if (key_char.toLatin1() >= 'a' && key_char.toLatin1()<= 'z') {
             kb->keyPressed(key_char);
        }
    }
}

void RoundWindow::closeEvent(QCloseEvent *event) {
    QMessageBox::StandardButton choice =
            QMessageBox::question(this, "Exit", "Would you like to exit this round?");
    if (choice == QMessageBox::Yes) {
        event->accept();
        emit closeRound();
    } else {
        event->ignore();
    }
}

void RoundWindow::popupInvalidWord() {
    QMessageBox::information(this, "Invalid word",
        "The word you entered is not in the dictionary!");
}

void RoundWindow::popupInvalidHardWord() {
    QMessageBox::information(this, "Invalid word",
        "You must use yellow and green letters in Hard Mode!");
}

void RoundWindow::popupRoundWin() {
    QMessageBox::information(this, "You won!",
        "Congratulations! You guessed the right word in " + QString::number(wr->getNumTries()) + " tries!");
    ui->label->setText("You won!");
    ui->actionGive_Up->setEnabled(false);
    ui->actionCheat->setEnabled(false);
    ui->actionHint->setEnabled(false);
}

void RoundWindow::popupRoundLose() {
    QMessageBox::information(this, "You lost!",
        "The correct answer is " + wr->getAnswer().toUpper() + ".");
    ui->label->setText("You lost! (Answer: " + wr->getAnswer().toUpper() + ")");
    ui->actionGive_Up->setEnabled(false);
    ui->actionCheat->setEnabled(false);
    ui->actionHint->setEnabled(false);
}

void RoundWindow::popupConfirmGiveUp() {
    QMessageBox::StandardButton choice =
            QMessageBox::question(this, "Give up?", "Would you like to forfeit this round?");
    if (choice == QMessageBox::Yes) {
        wr->endRound(false);
    }
}

void RoundWindow::popupConfirmReset() {
    QMessageBox::StandardButton choice =
            QMessageBox::question(this, "Reset?", "Would you like restart the round? A new answer will be generated.");
    if (choice == QMessageBox::Yes) {
        wr->resetRound();
        ui->label->setText(title);
        ui->actionGive_Up->setEnabled(true);
        ui->actionCheat->setEnabled(true);
        ui->actionHint->setEnabled(true);
    }
}

void RoundWindow::popupCheat() {
    QMessageBox::information(this, "Cheat", "The correct answer is " + wr->getAnswer().toUpper() + ".");
}

void RoundWindow::popupHint() {
    QString hint = wr->getHint();
    if (hint == "long words") {
        QMessageBox::information(this, "Hint unavailable", "Unable to give hint for long words.");
    }
    else if (hint == "too many words") {
        QString extraHint = " Try guessing yourself before asking for hint.";
        if (wr->isFirstGuess()) {
            if (wr->getLength() == 4) {
                extraHint = " Try SARE as your first guess.";
            }
            if (wr->getLength() == 5) {
                extraHint = " Try TARES as your first guess.";
            }
        }
        QMessageBox::information(this, "Hint unavailable", "Too many possible answers." + extraHint);
    }
    else {
        QMessageBox::information(this, "Hint", "Try " + hint.toUpper() + ".");
    }
}

