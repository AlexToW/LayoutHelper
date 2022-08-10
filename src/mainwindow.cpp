#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    clipboard = QApplication::clipboard();
    if(clipboard == nullptr) {
        std::cerr << "Couldn't get clipboard text!" << std::endl;
        exit(EXIT_FAILURE);
    }

    this->resize(w_width, w_heigth);
    QScreen* screen = QApplication::screens().at(0);
    QSize size = screen->availableSize();
    this->move(0, size.height() - w_heigth);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::swap() {
    QString res = "";
    QString clip_text = clipboard->text();
    bool from_eng_to_rus = false, from_rus_to_eng = false;
    if(!clip_text.isEmpty()) {
        for(auto c : clip_text) {
            QString tmp = QString(c).toLower();
            if(is_eng(tmp)) {
                from_eng_to_rus = true;
                break;
            }
            if(is_rus(tmp)) {
                from_rus_to_eng = true;
                break;
            }
        }
    }
    qDebug() << (from_eng_to_rus ? "eng_rus" : "rus_eng");
    //qDebug() << "clip_text: " << clip_text;
    if(!clip_text.isEmpty()) {
        for(auto c : clip_text) {
            QString tmp = QString(c);
            if(from_eng_to_rus) {
                // есть хотя бы одна английская буква
                bool cont = true;;
                if(tmp == "<") {
                    res += QString::fromUtf8("Б");
                } else if(tmp == ",") {
                    res += QString::fromUtf8("б");
                } else if(tmp == ">") {
                    res += QString::fromUtf8("Ю");
                } else if(tmp == ".") {
                    res += QString::fromUtf8("ю");
                } else if(tmp == "?") {
                    res += ",";
                } else if(tmp == "&") {
                    res += "?";
                } else if(tmp == "[") {
                    res += QString::fromUtf8("х");
                } else if(tmp == "{") {
                    res += QString::fromUtf8("Х");
                } else if(tmp == "]") {
                    res += QString::fromUtf8("ъ");
                } else if(tmp == "}") {
                    res += QString::fromUtf8("Ъ");
                } else if(tmp == ";") {
                    res += QString::fromUtf8("ж");
                } else if(tmp == ":") {
                    res += QString::fromUtf8("Ж");
                } else if(tmp == "'") {
                    res += QString::fromUtf8("э");
                } else if(tmp == "\"") {
                    res += QString::fromUtf8("Э");
                } else {
                    cont = false;
                }
                if(cont) {
                    continue;
                }
            } else if(from_rus_to_eng){
                // есть хотя бы одна русская буква
                bool cont = true;
                if(tmp == QString::fromUtf8("б")) {
                    res += ",";
                } else if(tmp == QString::fromUtf8("Б")) {
                    res += "<";
                } else if(tmp == QString::fromUtf8("ю")) {
                    res += ".";
                } else if(tmp == QString::fromUtf8("Ю")) {
                    res += ">";
                } else if(tmp == QString::fromUtf8(".")) {
                    res += "/";
                } else if(tmp == QString::fromUtf8(",")) {
                    res += "?";
                }
                /*
                else if(tmp == "&") {
                    res += "?";
                }
                */
                else if(tmp == QString::fromUtf8("х")) {
                    res += "[";
                } else if(tmp == QString::fromUtf8("Х")) {
                    res += "{";
                } else if(tmp == QString::fromUtf8("ъ")) {
                    res += "]";
                } else if(tmp == QString::fromUtf8("Ъ")) {
                    res += "}";
                } else if(tmp == QString::fromUtf8("ж")) {
                    res += ";";
                } else if(tmp == QString::fromUtf8("Ж")) {
                    res += ":";
                } else if(tmp == QString::fromUtf8("э")) {
                    res += "'";
                } else if(tmp == QString::fromUtf8("Э")) {
                    res += "\"";
                } else {
                    cont = false;
                }
                if(cont) {
                    continue;
                }
            }
            if(is_eng(tmp)) {
                if(eng_to_rus.find(tmp) != eng_to_rus.end()) {
                    // ключ есть
                    res += eng_to_rus[tmp];
                } else if(eng_to_rus.find(tmp.toLower()) != eng_to_rus.end()){
                    res += eng_to_rus[tmp.toLower()].toUpper();
                } else {
                    res += "#";
                }
            } else if(is_rus(tmp)) {
                if(rus_to_eng.find(tmp) != rus_to_eng.end()) {
                    res += rus_to_eng[tmp];
                } else if(rus_to_eng.find(tmp.toLower()) != rus_to_eng.end()){
                    res += rus_to_eng[tmp.toLower()].toUpper();
                } else {
                    res += "#";
                }
            } else {
                res += tmp;
            }
        }
    }
    return res;
}

std::vector<QString> MainWindow::swap2() {
    std::vector<QString> res;
    return res;
}

bool MainWindow::is_eng(QString s) {
    if(s.length() > 1) {
        std::cerr << "Wtf?" << std::endl;
        exit(EXIT_FAILURE);
    }
    return std::find(eng_alphabet.begin(),
                     eng_alphabet.end(),
                     s.toLower()) != eng_alphabet.end();
}

bool MainWindow::is_rus(QString s) {
    if(s.length() > 1) {
        std::cerr << "Wtf2?" << std::endl;
        exit(EXIT_FAILURE);
    }
    return std::find(rus_alphabet.begin(),
                     rus_alphabet.end(),
                     s.toLower()) != rus_alphabet.end();
}


void MainWindow::on_pushButton_clicked() {
    swaped_text = swap();
    ui->textBrowser->setText(swap() + "\n" + ui->textBrowser->toPlainText());
}

void MainWindow::on_pushButton_2_clicked()
{
    clipboard->setText(swaped_text);
}

